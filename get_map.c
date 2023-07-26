/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:10:57 by svalente          #+#    #+#             */
/*   Updated: 2023/07/26 15:34:57 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

char	**create_matrix(t_list *list, int rows_counter);

/* void	print_list(t_list *lst)
{
	t_list *tmp = lst;

	while (tmp)
	{
		printf("[%d] ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
} */

char	**get_map(char *path)
{
	int		fd;
	int		rows_counter;
	t_list	*lines;
	char	**map;

	rows_counter = 0;
	lines = NULL;
	// map = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening the file\n");
		exit(1);
	}
	while (ft_lstadd_back(&lines, ft_lstnew(get_next_line(fd))))
		rows_counter++;
	map = create_matrix(lines, rows_counter);
	ft_lstclear(&lines, 0);
	close(fd);
	return (map);
}

char	**create_matrix(t_list *list, int rows_counter)
{
	t_list	*tmp;
	char	**matrix;
	int		i;

	i = 0;
	tmp = list;
	matrix = malloc(sizeof(char *) * (rows_counter + 1));
	if (!matrix)
		return (0);
	while (tmp)
	{
		matrix[i++] = tmp->content;
		tmp = tmp->next;
	}
	matrix[i] = 0;
	return(matrix);
}

/* int main(int ac, char **av)
{
	char **map = get_map(av[1]);
	int i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		i++;
	}
} */