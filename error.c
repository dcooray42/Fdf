/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:58:41 by dcooray           #+#    #+#             */
/*   Updated: 2017/01/13 21:19:24 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	malloc_error(void)
{
	char	*str;

	str = ft_strdup("Error: Malloc failed\n");
	write(2, str, ft_strlen(str));
	ft_strdel(&str);
	exit(EXIT_SUCCESS);
}

void	empty_file(void)
{
	char	*str;

	str = ft_strdup("Error: Empty file\n");
	write(2, str, ft_strlen(str));
	ft_strdel(&str);
	exit(EXIT_SUCCESS);
}

void	basic_error(char *argv)
{
	char	*str;

	if (errno == EISDIR)
	{
		str = ft_strdup("Error: ");
		write(2, str, ft_strlen(str));
		write(2, argv, ft_strlen(argv));
		ft_putchar(' ');
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		ft_putchar('\n');
		ft_strdel(&str);
	}
	else
		perror("Error");
	exit(EXIT_SUCCESS);
}

void	error_x(t_list **list)
{
	char	*str;

	str = ft_strdup("Error: Different line lenght\n");
	write(2, str, ft_strlen(str));
	del_list(list);
	ft_strdel(&str);
	exit(EXIT_SUCCESS);
}

void	ft_error(t_list **list)
{
	t_line	*line;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		line = (t_line *)tmp->content;
		if (i == 0)
			i = line->x;
		if (i != line->x)
			error_x(list);
		tmp = tmp->next;
	}
}
