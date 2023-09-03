/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:25:27 by svalente          #+#    #+#             */
/*   Updated: 2023/09/03 15:01:54 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map && map[i])
		free(map[i++]);
	free(map);
	map = NULL;
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
	ft_putstr_fd("Congratulations on your acceptance to Harvard!!\n", 1);
	leave(data);
}

void	ft_error_handler(char *msg, int fd)
{
	if (fd != -1)
		close(fd);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

/* void	free_matrix1(char **map)
{
	int	i;
	char **holder;

	holder = map;
	i = 0;
	while (holder && holder[i])
		free(holder[i++]);
	free(holder);
	map = NULL;
} */

/* void	free_matrix2(char ***map)
{
	char	**ptr;
	int		i;

	i = 0;
	if (!*map)
		return ;
	ptr = *map;
	while (ptr && ptr[i])
		free(ptr[i++]);
	free(ptr);
	*map = NULL;
} */