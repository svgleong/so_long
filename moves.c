/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:56:48 by svalente          #+#    #+#             */
/*   Updated: 2023/08/11 16:08:32 by svalente         ###   ########.fr       */
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
				map[i][j] = '0';
				map[i][j + 1] = 'P';
				return ;
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
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_up(char **map)
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
				(map[i - 1][j] == '0' || map[i - 1][j] == 'C'))
			{
				map[i][j] = '0';
				map[i - 1][j] = 'P';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_down(char **map)
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
				(map[i + 1][j] == '0' || map[i + 1][j] == 'C'))
			{
				map[i][j] = '0';
				map[i + 1][j] = 'P';
				return ;
			}
			j++;
		}
		i++;
	}
}