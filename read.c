/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:59:28 by dcooray           #+#    #+#             */
/*   Updated: 2017/01/13 21:06:48 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*read_file(char *argv)
{
	int		fd;
	t_list	*list;
	char	*line;
	int		i;

	line = NULL;
	list = NULL;
	i = 1;
	if ((fd = open(argv, O_RDONLY)) == -1)
		basic_error(argv);
	while (get_next_line(fd, &line) > 0)
	{
		init_line(&list, line, i);
		ft_strdel(&line);
		i++;
	}
	if (close(fd) == -1 || errno == EISDIR)
		basic_error(argv);
	if (list == NULL)
		empty_file();
	ft_error(&list);
	return (list);
}

void	init_line(t_list **list, char *str, int line_nb)
{
	t_line	*line;
	t_list	*tmp;
	int		i;

	i = 0;
	if ((line = (t_line *)ft_memalloc(sizeof(t_line))) == NULL)
		malloc_error();
	if ((line->line = ft_strsplit(str, ' ')) == NULL)
	{
		ft_memdel((void **)&line);
		malloc_error();
	}
	while (line->line[i] != NULL)
		i++;
	line->x = i;
	line->y = line_nb;
	if ((tmp = ft_lstnew(line, sizeof(t_line))) == NULL)
	{
		ft_memdel((void **)&line);
		malloc_error();
	}
	ft_memdel((void **)&line);
	ft_lstadd(list, tmp);
}

void	del_list(t_list **list)
{
	t_line	*line;
	t_list	**lst;
	t_list	*tmp;
	int		i;

	lst = list;
	while (*lst)
	{
		tmp = (*lst)->next;
		line = (t_line *)((*lst)->content);
		i = 0;
		while (line->line[i] != NULL)
		{
			ft_strdel(&(line->line[i]));
			i++;
		}
		ft_memdel((void **)&(line->line));
		ft_memdel((void **)&line);
		ft_memdel((void **)lst);
		*lst = tmp;
	}
}
