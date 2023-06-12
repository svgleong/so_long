# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 10:43:02 by svalente          #+#    #+#              #
#    Updated: 2023/06/11 15:04:07 by svalente         ###   ########.fr        #
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

LIBFT_PATH = ./Libft
FT_PRINTF_PATH = ./ft_printf
GNL_PATH = ./get_next_line

LIBFT = ./Libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a

SRC	= main.c\

$(VERBOSE).SILENT:

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT_PATH)
		make -C $(FT_PRINTF_PATH)
		make -s -C minilibx-linux
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(LMLX_FLAGS) $(MLX_INCLUDE) -o $(NAME)

clean:
		make clean -C $(LIBFT_PATH)
		make clean -C $(FT_PRINTF_PATH)
		$(RM) $(OBJ)
		
fclean:		clean
			make fclean -C $(LIBFT_PATH)
			make fclean -C $(FT_PRINTF_PATH)
			$(RM) $(NAME)
	
re:			fclean all