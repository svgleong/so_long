/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:25:27 by svalente          #+#    #+#             */
/*   Updated: 2023/08/28 23:06:58 by svalente         ###   ########.fr       */
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

void    ft_error_msg(char **map, char *msg)
{
    ft_putstr_fd(msg, 2);
    if (map)
        free_matrix(map);
    exit(EXIT_FAILURE);
}

void    ft_final_msg(t_data *data, char *msg)
{
    ft_putstr_fd(msg, 1);
	leave(data);
    if (data->map)
        free_matrix(data->map);
    exit(EXIT_SUCCESS);
}
