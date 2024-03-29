/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:44:54 by svalente          #+#    #+#             */
/*   Updated: 2023/09/01 10:16:34 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
# define PLAYER_LEFT "./images/player_left.xpm"
# define PLAYER_RIGHT "./images/player_right.xpm"
# define GROUND "./images/ground.xpm"
# define COLLECTIBLE "./images/collectible.xpm"
# define ENEMY "./images/enemy.xpm"

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
	void	*enemy;
	int		num;
	int		n_moves;
	int		x;
	int		y;
	int		player_counter;
	int		collectible_counter;
	int		exit_counter;
}	t_data;

char	**get_map(char *path);
void	free_matrix(char **paths);
void	ft_error_msg(char **map, char *msg);
void	ft_error_handler(char *msg, int fd);
void	get_position(t_data *data);
void	check_path(t_data *data);
void	check_map(t_data *data);
int		map_size(char **map, char side);
int		create_window(t_data *data);
int		handle_input(int key, t_data *data);
void	print_n_moves(t_data *data);
void	window_full_load(t_data *data);
int		window_update(t_data *data);
int		leave(t_data *data);
void	win_game(t_data *data);
void	move_right(char **map, t_data *data);
void	move_left(char **map, t_data *data);
void	move_up(char **map, t_data *data);
void	move_down(char **map, t_data *data);
void	change_player_img(int key, t_data *data);
int		check_collectibles(t_data *data);

#endif