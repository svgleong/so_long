/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:25:27 by svalente          #+#    #+#             */
/*   Updated: 2023/08/29 14:40:42 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	ft_error_msg(char **map, char *msg)
{
	ft_putstr_fd(msg, 2);
	if (map)
		free_matrix(map);
	exit(EXIT_FAILURE);
}

void	win_game(t_data *data)
{
	ft_putstr_fd("You Win!!\n", 1);
	leave(data);
}
