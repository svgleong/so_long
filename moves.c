/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:56:48 by svalente          #+#    #+#             */
/*   Updated: 2023/08/24 17:43:33 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (map[i][j] == 'P' && 
				(map[i][j + 1] == '0' || map[i][j + 1] == 'C'))
			{
				map[i][j] = '0';
				map[i][j + 1] = 'P';
				data->n_moves++;
				ft_printf("moves -> %d\n", data->n_moves);
				return ;
			}
			if (map[i][j] == 'P' && map[i][j + 1] == 'E' 
				&& !check_collectibles(data))
				ft_error_msg(data->map, "You Win\n");
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
			if (map[i][j] == 'P' && 
				(map[i][j - 1] == '0' || map[i][j - 1] == 'C'))
			{
				map[i][j] = '0';
				map[i][j - 1] = 'P';
				data->n_moves++;
				ft_printf("moves -> %d\n", data->n_moves);
				return ;
			}
			if (map[i][j] == 'P' && map[i][j - 1] == 'E' 
				&& !check_collectibles(data))
				ft_error_msg(data->map, "You Win\n");
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
			if (map[i][j] == 'P' && 
				(map[i - 1][j] == '0' || map[i - 1][j] == 'C'))
			{
				map[i][j] = '0';
				map[i - 1][j] = 'P';
				data->n_moves++;
				ft_printf("moves -> %d\n", data->n_moves);
				return ;
			}
			if (map[i][j] == 'P' && map[i - 1][j] == 'E' 
				&& !check_collectibles(data))
				ft_error_msg(data->map, "You Win\n");
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
			if (map[i][j] == 'P' && 
				(map[i + 1][j] == '0' || map[i + 1][j] == 'C'))
			{
				map[i][j] = '0';
				map[i + 1][j] = 'P';
				data->n_moves++;
				ft_printf("moves -> %d\n", data->n_moves);
				return ;
			}
			if (map[i][j] == 'P' && map[i + 1][j] == 'E' 
				&& !check_collectibles(data))
				ft_error_msg(data->map, "You Win\n");
			j++;
		}
		i++;
	}
}
