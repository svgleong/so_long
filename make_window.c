/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:38:10 by svalente          #+#    #+#             */
/*   Updated: 2023/08/31 20:24:41 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_xpm_to_img(t_data *data)
{
	data->ground = mlx_xpm_file_to_image(data->mlx_ptr, GROUND, 
			&(data->win_size_x), &(data->win_size_x));
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL, 
			&(data->win_size_x), &(data->win_size_x));
	data->collectible = mlx_xpm_file_to_image(data->mlx_ptr, COLLECTIBLE, 
			&(data->win_size_x), &(data->win_size_x));
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, 
			&(data->win_size_x), &(data->win_size_x));
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, 
			&(data->win_size_x), &(data->win_size_x));
	data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, ENEMY, 
			&(data->win_size_x), &(data->win_size_x));
}

void	img_to_window(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, 
			j * 64, i * 64);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground, 
			j * 64, i * 64);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit, 
			j * 64, i * 64);
	else if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player, 
			j * 64, i * 64);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectible,
			j * 64, i * 64);
	else if (data->map[i][j] == 'K')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->enemy,
			j * 64, i * 64);
}

void	window_full_load(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			img_to_window(data, i, j);
			j++;
		}
		i++;
	}
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

int	window_update(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	window_full_load(data);
	print_n_moves(data);
	return (0);
}

int	create_window(t_data *data)
{
	/* data->win_size_y = map_size(data->map, 'y');
	data->win_size_x = map_size(data->map, 'x'); */
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == 0)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_size_x * 64,
			data->win_size_y * 64, "Game On");
	if (data->win_ptr == 0)
	{
		free(data->win_ptr);
		return (0);
	}
	window_xpm_to_img(data);
	window_full_load(data);
	print_n_moves(data);
	//mlx_key_hook(data->win_ptr, &window_update, data);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_hook(data->win_ptr, 17, 0, leave, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
