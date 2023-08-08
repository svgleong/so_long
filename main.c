/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:20:32 by svalente          #+#    #+#             */
/*   Updated: 2023/08/04 10:18:04 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* int leave(void *param)
{
	t_data	*data;

	data = (t_data *)param;
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

int	handle_input(int key, void *param)
{
	t_data *data;

	data = (t_data *)param;
	printf("Key -> %d\n", key);
	if (key == XK_Escape)
		leave(data);
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
} */

/* int	main(void)
{
	t_data	data;
	int		x = 1;
	int		y = 1;
	
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == 0)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 920, 680, "slay");
	if (data.win_ptr == 0)
	{
		free(data.win_ptr);
		return (0);
	}
	//mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	data.collectible = mlx_xpm_file_to_image(data.mlx_ptr,
			"./wall.xpm", &x, &y);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.collectible, 30, 0);
	mlx_hook(data.win_ptr, 17, 0, leave, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
} */

void	init_struct(t_data *data)
{
	data->map = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->collectible = 0;
	data->exit = 0;
	data->player = 0;
}

int	main(int ac, char **av)
{
	t_data	data;
	
	init_struct(&data);
	if (ac != 2)
		ft_error_msg(data.map, "Error: Syntax should be ./so_long selected_map\n");
	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
		ft_error_msg(data.map, "Error: Invalid map\n");
	data.map = get_map(av[1]);
	check_map(&data);
}
