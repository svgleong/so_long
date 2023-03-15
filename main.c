/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:20:32 by svalente          #+#    #+#             */
/*   Updated: 2023/03/12 17:34:20 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    printf("Keypress: %d\n", keysym);
	return (0);
}

int handle_keyrelease(int keysym, void *data)
{
	(void)data;
    printf("Keyrealese: %d\n", keysym);
    return (0);
}

int	main(void)
{
	t_data	data;
	
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == 0)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1200, 900, "window");
	if (data.win_ptr == 0)
	{
		free(data.win_ptr);
		return (0);
	}
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
