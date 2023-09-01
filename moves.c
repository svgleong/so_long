/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:56:48 by svalente          #+#    #+#             */
/*   Updated: 2023/09/01 10:15:25 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_enemy(t_data *data, int i, int j)
{
	if (data->map[i][j] && data->map[i][j] == 'K')
	{
		ft_putstr_fd("Caught by enemy :(\n", 1);
		leave(data);
	}
}

void	move_right(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' && (map[i][j + 1] == '0'
				|| map[i][j + 1] == 'C' || map[i][j + 1] == 'K'))
			{
				check_enemy(data, i, j + 1);
				map[i][j] = '0';
				map[i][j + 1] = 'P';
				data->n_moves++;
				return ;
			}
			if (map[i][j] == 'P' && map[i][j + 1] == 'E'
				&& !check_collectibles(data))
				win_game(data);
			j++;
		}
		i++;
	}
}

void	move_left(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' && (map[i][j - 1] == '0'
				|| map[i][j - 1] == 'C' || map[i][j - 1] == 'K'))
			{
				check_enemy(data, i, j - 1);
				map[i][j] = '0';
				map[i][j - 1] = 'P';
				data->n_moves++;
				return ;
			}
			if (map[i][j] == 'P' && map[i][j - 1] == 'E'
				&& !check_collectibles(data))
				win_game(data);
			j++;
		}
		i++;
	}
}

void	move_up(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' && (map[i - 1][j] == '0'
				|| map[i - 1][j] == 'C' || map[i - 1][j] == 'K'))
			{
				check_enemy(data, i - 1, j);
				map[i][j] = '0';
				map[i - 1][j] = 'P';
				data->n_moves++;
				return ;
			}
			if (map[i][j] == 'P' && map[i - 1][j] == 'E'
				&& !check_collectibles(data))
				win_game(data);
			j++;
		}
		i++;
	}
}

void	move_down(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' && (map[i + 1][j] == '0'
				|| map[i + 1][j] == 'C' || map[i + 1][j] == 'K'))
			{
				check_enemy(data, i + 1, j);
				map[i][j] = '0';
				map[i + 1][j] = 'P';
				data->n_moves++;
				return ;
			}
			if (map[i][j] == 'P' && map[i + 1][j] == 'E'
				&& !check_collectibles(data))
				win_game(data);
			j++;
		}
		i++;
	}
}
