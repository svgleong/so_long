/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:10:57 by svalente          #+#    #+#             */
/*   Updated: 2023/09/01 11:22:46 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**create_matrix(t_list *list, int rows_counter);
static void	clear_and_close(t_list **lines, int fd);

char	**get_map(char *path)
{
	int		fd;
	int		rows_counter;
	t_list	*lines;
	char	**map;
	char	*line;

	rows_counter = 0;
	lines = NULL;
	map = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error_handler("Error opening the file\n", fd);
	line = get_next_line(fd);
	if (!line)
		ft_error_handler("Error: the map is empty\n", fd);
	while (line)
	{
		ft_lstadd_back(&lines, ft_lstnew(line));
		rows_counter++;
		line = get_next_line(fd);
	}
	if (lines->content != NULL)
		map = create_matrix(lines, rows_counter);
	clear_and_close(&lines, fd);
	return (map);
}

static void	clear_and_close(t_list **lines, int fd)
{
	lstclear(lines);
	close(fd);
}

static char	**create_matrix(t_list *list, int rows_counter)
{
	t_list	*tmp;
	char	**matrix;
	int		i;

	i = 0;
	tmp = list;
	matrix = ft_calloc((rows_counter + 1), sizeof(char *));
	if (!matrix)
		return (0);
	while (tmp)
	{
		matrix[i++] = tmp->content;
		tmp = tmp->next;
	}
	matrix[i] = 0;
	return (matrix);
}

int	map_size(char **map, char side)
{
	int	i;

	i = 0;
	if (side == 'x')
		i = ft_strlen(map[0]) - 1;
	else if (side == 'y')
	{
		while (map[i])
			i++;
	}
	return (i);
}

/* int main(int ac, char **av)
{
	char **map = get_map(av[1]);
	(void)ac;
	int i = 0;
	printf("%d ", i);
	while (map[i])
	{
		printf("%d ", i);
		ft_putstr_fd(map[i], 1);
		i++;
	}
	free_matrix(map);
} */

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