/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:56:48 by svalente          #+#    #+#             */
/*   Updated: 2023/08/29 14:43:53 by svalente         ###   ########.fr       */
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
				win_game(data);
			j++;
		}
		i++;
	}
}

int	handle_input(int key, t_data *data)
{
	/* t_data *data;

	data = (t_data *)param; */
	//printf("Key -> %d\n", key);
	if (key == XK_Escape)
		leave(data);
	else if (key == XK_Left || key == XK_a)
	{
		data->num = 1;
		move_left(data->map, data);
		change_player_img(XK_Left, data);
	}
	else if (key == XK_Right || key == XK_d)
	{
		data->num = 2;
		move_right(data->map, data);
		change_player_img(XK_Right, data);
	}
	else if (key == XK_Up || key == XK_w)
	{
		move_up(data->map, data);
	}
	else if (key == XK_Down || key == XK_s)
		move_down(data->map, data);
	window_update(data);
	return (0);
}
