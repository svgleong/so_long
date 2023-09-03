/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:20:32 by svalente          #+#    #+#             */
/*   Updated: 2023/09/03 15:39:01 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_data *data)
{
	data->map = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->collectible = 0;
	data->exit = 0;
	data->player = 0;
	data->num = 0;
	data->n_moves = 0;
	data->player_counter = 0;
	data->exit_counter = 0;
	data->collectible_counter = 0;
}

int	main(int ac, char **av)
{
	t_data		data;

	init_struct(&data);
	if (ac != 2)
		ft_error_msg(data.map, "Error: Wrong number of arguments\n");
	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
		ft_error_msg(data.map, "Error: Invalid map\n");
	data.map = get_map(av[1]);
	if (data.map == NULL)
		ft_error_msg(data.map, "Something went wrong :(\n");
	check_map(&data);
	create_window(&data);
}
