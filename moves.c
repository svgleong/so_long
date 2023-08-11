/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:56:48 by svalente          #+#    #+#             */
/*   Updated: 2023/08/11 15:34:24 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' && 
				(map[i][j + 1] == '0' || map[i][j + 1] == 'C'))
			{
				printf("i:%d	j:%d\n", i, j);
				map[i][j] = '0';
				map[i][j + 1] = 'P';
			}
			j++;
		}
		i++;
	}
}

void	move_left(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' && 
				(map[i][j - 1] == '0' || map[i][j - 1] == 'C'))
			{
				map[i][j] = '0';
				map[i][j - 1] = 'P';
			}
			j++;
		}
		i++;
	}
}