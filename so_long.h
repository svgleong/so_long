/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:44:54 by svalente          #+#    #+#             */
/*   Updated: 2023/08/11 15:34:58 by svalente         ###   ########.fr       */
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

# define WALL "./images/wall.xpm"
# define EXIT "./images/exit.xpm"
# define PLAYER "./images/player.xpm"
# define GROUND "./images/ground.xpm"
# define COLLECTIBLE "./images/collectible.xpm"

typedef struct s_data
{
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_size_x;
	int		win_size_y;
	void	*collectible;
	void	*exit;
	void	*player;
	void	*ground;
	void	*wall;
	int		*x;
	int		*y;
}	t_data;

typedef struct s_error
{
	int	player;
	int	collectible;
	int	exit;
	int	walls;
	int	ground;
}				t_error;

char	**get_map(char *path);
void	free_matrix(char **paths);
void    ft_error_msg(char **map, char *msg);
void 	check_map(t_data *data);
int		map_size(char **map, char side);
int		create_window(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_input(int key, t_data *data);
void	window_full_load(t_data *data);
int 	leave(t_data *data);
void	move_right(char **map);
void	move_left(char **map);

#endif