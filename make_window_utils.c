/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:43:05 by svalente          #+#    #+#             */
/*   Updated: 2023/09/01 14:19:36 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_player_img(int key, t_data *data)
{
	if (key == XK_Left || key == XK_a)
	{
		mlx_destroy_image(data->mlx_ptr, data->player);
		data->player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_LEFT,
				&(data->win_size_x), &(data->win_size_x));
	}
	if (key == XK_Right || key == XK_d)
	{
		mlx_destroy_image(data->mlx_ptr, data->player);
		data->player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_RIGHT,
				&(data->win_size_x), &(data->win_size_x));
	}
}

int	handle_input(int key, t_data *data)
{
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

void	print_n_moves(t_data *data)
{
	char	*number;
	char	*steps;

	number = ft_itoa(data->n_moves);
	steps = ft_strjoin("Number of moves: ", number);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 30, 0x000FFFFF, steps);
	free(number);
	free(steps);
}
