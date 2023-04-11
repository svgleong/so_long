/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:20:32 by svalente          #+#    #+#             */
/*   Updated: 2023/04/10 14:07:29 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	leave(char *msg)
{
	printf("%s", msg);
	exit(0);
	return (0);
}

int	main(void)
{
	t_data	data;
	int		x = 1;
	int		y = 1;
	
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == 0)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "window");
	if (data.win_ptr == 0)
	{
		free(data.win_ptr);
		return (0);
	}
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	data.collectible = mlx_xpm_file_to_image(data.mlx_ptr,
			"./wall.xpm", &x, &y);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.collectible, 30, 0);
	mlx_hook(data.win_ptr, 17, 0, leave,
		(void *)"Did you give up? 😲​​\n");
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
