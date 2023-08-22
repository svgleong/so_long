/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:43:05 by svalente          #+#    #+#             */
/*   Updated: 2023/08/22 15:58:36 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_player_img(int key, t_data *data)
{
	if (key == XK_Left|| key == XK_a)
	{
		printf("entrei\n");	
		data->player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_LEFT, 
			&(data->win_size_x), &(data->win_size_x));
		
		printf("sai\n");
	}
	if (key == XK_Right || key == XK_d)
	{
		printf("entrei2\n");
		data->player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_RIGHT, 
			&(data->win_size_x), &(data->win_size_x));
		printf("sai\n");
	}
}