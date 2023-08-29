/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:58:08 by svalente          #+#    #+#             */
/*   Updated: 2023/08/29 14:28:44 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->collectible);
	mlx_destroy_image(data->mlx_ptr, data->ground);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->player);
	//mlx_destroy_image(data->mlx_ptr, data->enemy);
}

int leave(t_data *data)
{
	/* t_data	*data;

	data = (t_data *)param; */
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	destroy_sprites(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_matrix(data->map);
	exit(0);
}

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	check_collectibles(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    //printf("Keypress: %d\n", keysym);
	return (0);
} */

/* int handle_keyrelease(int keysym, void *data)
{
	(void)data;
    printf("Keyrealese: %d\n", keysym);
    return (0);
} */
