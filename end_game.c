/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:58:08 by svalente          #+#    #+#             */
/*   Updated: 2023/08/11 15:35:28 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int leave(t_data *data)
{
	/* t_data	*data;

	data = (t_data *)param; */
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	exit(0);
}

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_input(int key, t_data *data)
{
	/* t_data *data;

	data = (t_data *)param; */
	//printf("Key -> %d\n", key);
	if (key == XK_Escape)
		leave(data);
    //if (key == XK_Up || XK_w)
    else if (key == XK_Right || XK_d)
	{
		printf("ola\n");
		move_right(data->map);
		window_full_load(data);
	}
	else if (key == XK_Left|| XK_a)
	{
		printf("ola2\n");
		move_left(data->map);
		window_full_load(data);
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    //printf("Keypress: %d\n", keysym);
	return (0);
}

/* int handle_keyrelease(int keysym, void *data)
{
	(void)data;
    printf("Keyrealese: %d\n", keysym);
    return (0);
} */
