# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 10:43:02 by svalente          #+#    #+#              #
#    Updated: 2023/03/08 11:31:11 by svalente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -Imlx -g -fsanitize=address
MILIB  = -I /usr/X11/include -g -L /usr/X11/lib -l minilibx-linux -framework OpenGL -framework AppKit
RM = rm -f

MLX_LIB_DIR = minilibx-linux/
MLX_INCLUDE = -I minilibx-linux/
LMLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -fPIC

SRC	= main.c\

$(VERBOSE).SILENT:

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -s -C minilibx-linux
		$(CC) $(CFLAGS) $(OBJ) $(LMLX_FLAGS) $(MLX_INCLUDE) -o $(NAME)

clean:
		$(RM) $(OBJ)
		
fclean:		clean
			$(RM) $(NAME)
	
re:			fclean all