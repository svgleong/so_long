# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 10:48:12 by svalente          #+#    #+#              #
#    Updated: 2023/08/31 22:15:49 by svalente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_functions ft_verify ft_printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

#$(VERBOSE).SILENT:

all: $(NAME)

$(NAME): $(SRC:=.o)
			$(AR) $(NAME) $(SRC:=.o)
			echo -e "\n[ft_printf successfully compiled :D]"

clean:
	$(RM) $(SRC:=.o) $(BONUS:=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all