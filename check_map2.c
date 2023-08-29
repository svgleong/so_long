/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:29:49 by svalente          #+#    #+#             */
/*   Updated: 2023/08/29 17:26:54 by svalente         ###   ########.fr       */
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
	copy = malloc(sizeof(char *) * data->win_size_y);
	if (!copy)
		return (0);
	while (data->map[i])
	{
		copy[i] = ft_strdup(data->map[i]);
		i++;
	}
	return (copy);
}

char	**flood_fill(int x, int y, t_data *data)
{
	char	**map;

	map = copy_map(data);
	if (map[y][x + 1] != 'z' && map[y][x + 1] != '1' && map[y][x + 1] != 'E' && map[y][x + 1] != 'K')
	{
		map[y][x + 1] = 'z';
		flood_fill(x + 1, y, data);
	}
	if (map[y][x - 1] != 'z' && map[y][x - 1] != '1' && map[y][x - 1] != 'E' && map[y][x - 1] != 'K')
	{
		map[y][x - 1] = 'z';
		flood_fill(x - 1, y, data);
	}
	if (map[y + 1][x] != 'z' && map[y + 1][x] != '1' && map[y + 1][x] != 'E' && map[y + 1][x] != 'K')
	{
		map[y + 1][x] = 'z';
		flood_fill(x, y + 1, data);
	}
	if (map[y - 1][x] != 'z' && map[y - 1][x] != '1' && map[y - 1][x] != 'E' && map[y - 1][x] != 'K')
	{
		map[y - 1][x] = 'z';
		flood_fill(x, y - 1, data);
	}
	return (map);
}

void	check_path(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = flood_fill(data->x, data->y, data);
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
}
