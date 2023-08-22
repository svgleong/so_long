/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:26:16 by svalente          #+#    #+#             */
/*   Updated: 2023/08/22 17:53:15 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_shape(char **map)
{
    size_t	len;
    int		i;

    len = ft_strlen(map[0]);
    i = 1;
    while(map[i])
        if (ft_strlen(map[i++]) != len)
            ft_error_msg(map, "Error: Wrong map shape\n");
}

static void check_walls(char **map)
{
    int i;
	int j;

	i = 0;
	j = 0;
	while(map[j][i] && map[j][i] !='\n')	
		if (map[j][i++] != '1')
			ft_error_msg(map, "Error: The map is not surrounded by walls\n");
	j++;
	while(map[j])
	{
		i = ft_strlen(map[0]) - 2;
		if (map[j][0] != '1' || map[j][i] != '1')
			ft_error_msg(map, "Error: The map is not surrounded by walls\n");
		j++;
	}
	j--;
	i = 0;
	while(map[j][i] && map[j][i] !='\n')
		if (map[j][i++] != '1')
			ft_error_msg(map, "Error: The map is not surrounded by walls\n");
}

static void    check_characters(char **map)
{
    int i;
    int j;
	t_error	chars;
	
    j = 0;
	chars.collectible = 0;
	chars.exit = 0;
	chars.player = 0;
    while (map[j])
    {
		i = 0;
        while (map[j][i])
        {
            if (map[j][i] == 'C')
                chars.collectible++;
            else if (map[j][i] == 'E')
                chars.exit++;
            else if (map[j][i] == 'P')
                chars.player++;
            else if (!(map[j][i] == '1' || map[j][i] == '0' || map[j][i] == '\n'))
                ft_error_msg(map, "Error: Invalid character in map\n");
			i++;
        }
		j++;
    }
	if (chars.exit == 0)
		ft_error_msg(map, "Error: The map should contain one exit\n");
	if (chars.exit > 1)
		ft_error_msg(map, "Error: The map should contain only one exit\n");
	if (chars.player == 0)
		ft_error_msg(map, "Error: The map should contain one player\n");
	if (chars.player > 1)
		ft_error_msg(map, "Error: The map should contain only one player\n");
	if (chars.collectible == 0)
		ft_error_msg(map, "Error: The map should contain at least one collectible\n");
}

void check_map(t_data *data)
{
	if(data->map == 0)
	{
		printf("entrei\n");	
		ft_error_msg(data->map, "Error: The map is empty\n");
	}
    check_shape(data->map);
	check_walls(data->map);
	check_characters(data->map);
}