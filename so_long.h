/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:44:54 by svalente          #+#    #+#             */
/*   Updated: 2023/08/04 09:50:06 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		collectible;
	int		exit;
	int		player;
	int		*x;
	int		*y;
}	t_data;

char	**get_map(char *path);
void	free_matrix(char **paths);
void    ft_error_msg(char **map, char *msg);
void 	check_map(t_data *data);

#endif