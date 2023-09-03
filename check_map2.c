/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:29:49 by svalente          #+#    #+#             */
/*   Updated: 2023/09/03 15:38:31 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->x = j;
				data->y = i;
			}
			j++;
		}
		i++;
	}
}

char	**copy_map(t_data *data)
{
	char	**copy;
	int		i;

	i = 0;
	copy = ft_calloc(data->win_size_y + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	while (data->map[i])
	{
		copy[i] = ft_strdup(data->map[i]);
		if (copy[i] == NULL)
		{
			free_matrix(copy);
			ft_error_msg(data->map, "Error: Error checking path\n");
		}
		i++;
	}
	return (copy);
}

void	flood_fill(int x, int y, char **map, t_data *data)
{
	if (!map)
		return ;
	if (x < 0 || x > data->win_size_x || y < 0 || y > data->win_size_y
		|| map[y][x] == 'z' || map[y][x] == '1' || map[y][x] == 'E'
		|| map[y][x] == 'K')
		return ;
	map[y][x] = 'z';
	flood_fill(x + 1, y, map, data);
	flood_fill(x - 1, y, map, data);
	flood_fill(x, y + 1, map, data);
	flood_fill(x, y - 1, map, data);
	return ;
}

void	check_path_aux(t_data *data, char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				free_matrix(map);
				ft_error_msg(data->map, "Error: Invalid map\n");
			}
			else if (map[i][j] == 'E')
			{
				if (map[i][j - 1] != 'z' && map[i][j + 1] != 'z'
					&& map[i + 1][j] != 'z' && map[i - 1][j] != 'z')
				{
					free_matrix(map);
					ft_error_msg(data->map, "Error: Invalid map\n");
				}
			}
			j++;
		}
		i++;
	}
	free_matrix(map);
}

void	check_path(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = copy_map(data);
	flood_fill(data->x, data->y, map, data);
	if (!map)
		ft_error_msg(data->map, "Error: Error checking path\n");
	check_path_aux(data, map, i, j);
}

/* void	print_map(char **map)
{
	int i = 0;
	
	if(!map)
		return ;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
} */