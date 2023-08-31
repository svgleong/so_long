/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:16 by svalente          #+#    #+#             */
/*   Updated: 2023/08/31 17:20:40 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_shape(char **map)
{
	size_t	len;
	int		i;
	int		j;
	size_t	count;

	len = ft_strlen(map[0]) - 1;
	i = 0;
	j = 0;
	while (map[j])
		j++;
	while (map[++i])
	{
		count = ft_strlen(map[i]) - 1;
		if (i == j - 1)
		{
			if (count == len - 1)
				return ;
			/* if (map[i][count] == '\n')
				return ; */
			ft_error_msg(map, "Error: Wrong map shape\n");
		}
		if (count != len)
			ft_error_msg(map, "Error: Wrong map shape\n");
	}
}

static void	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j][i] && map[j][i] != '\n')
		if (map[j][i++] != '1')
			ft_error_msg(map, "Error: The map is not surrounded by walls\n");
	j++;
	while (map[j])
	{
		i = ft_strlen(map[0]) - 2;
		if (map[j][0] != '1' || map[j][i] != '1')
			ft_error_msg(map, "Error: The map is not surrounded by walls\n");
		j++;
	}
	j--;
	i = 0;
	while (map[j][i] && map[j][i] != '\n')
		if (map[j][i++] != '1')
			ft_error_msg(map, "Error: The map is not surrounded by walls\n");
}

static void	check_n_characters(char **map, t_data *data)
{
	if (data->exit_counter == 0)
		ft_error_msg(map, "Error: The map should contain one exit\n");
	if (data->exit_counter > 1)
		ft_error_msg(map, "Error: The map should contain only one exit\n");
	if (data->player_counter == 0)
		ft_error_msg(map, "Error: The map should contain one player\n");
	if (data->player_counter > 1)
		ft_error_msg(map, "Error: The map should contain only one player\n");
	if (data->collectible_counter == 0)
		ft_error_msg(map, "Error: The map should contain one collectible\n");
}

static void	check_characters(t_data *data)
{
	int			i;
	int			j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'C')
				data->collectible_counter++;
			else if (data->map[j][i] == 'E')
				data->exit_counter++;
			else if (data->map[j][i] == 'P')
				data->player_counter++;
			else if (!(data->map[j][i] == '1' || data->map[j][i] == '0'
						|| data->map[j][i] == '\n' || data->map[j][i] == 'K'))
				ft_error_msg(data->map, "Error: Invalid character in map\n");
			i++;
		}
		j++;
	}
	check_n_characters(data->map, data);
}

void	check_map(t_data *data)
{
	if (data->map == 0)
		ft_error_msg(data->map, "Error: The map is empty\n");
	check_shape(data->map);
	check_walls(data->map);
	check_characters(data);
	data->win_size_y = map_size(data->map, 'y');
	data->win_size_x = map_size(data->map, 'x');
	get_position(data);
	check_path(data);
}
