/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 08:39:12 by dcooray           #+#    #+#             */
/*   Updated: 2017/01/13 21:50:21 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_line(t_gnl *gnl)
{
	int	i;

	i = 0;
	gnl->nl = 0;
	while (gnl->i + i < gnl->ret)
	{
		if (gnl->buf[gnl->i + i] == '\n')
		{
			gnl->nl = 1;
			i++;
			break ;
		}
		i++;
	}
	gnl->i += i;
	return (ft_strsub(gnl->buf, gnl->i - i, i - gnl->nl));
}

static t_gnl	*get_fd(t_list **list, const int fd)
{
	t_gnl	*gnl;
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		gnl = (t_gnl *)(tmp->content);
		if (gnl->fd == fd)
			return (gnl);
		tmp = tmp->next;
	}
	gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	gnl->buf = ft_strnew(BUFF_SIZE);
	gnl->ret = 1;
	gnl->i = 1;
	gnl->nl = 1;
	gnl->fd = fd;
	tmp = ft_lstnew(gnl, sizeof(t_gnl));
	ft_memdel((void **)&gnl);
	ft_lstadd(list, tmp);
	return ((t_gnl *)(tmp->content));
}

static void		del_fd(t_list **list, const int fd, char **str)
{
	t_gnl	*gnl;
	t_list	**tmp1;
	t_list	*tmp2;

	tmp1 = list;
	while (*tmp1)
	{
		gnl = (t_gnl *)((*list)->content);
		if (gnl->fd == fd)
			break ;
		*tmp1 = (*tmp1)->next;
	}
	if (*tmp1)
	{
		tmp2 = (*tmp1)->next;
		ft_strdel(&(gnl->buf));
		ft_memdel((void **)&gnl);
		ft_memdel((void **)tmp1);
		*tmp1 = tmp2;
	}
	ft_strdel(str);
}

static int		read_buf(t_list **list, t_gnl *gnl, char **line, char **tmp)
{
	if (gnl->i == gnl->ret)
	{
		gnl->ret = read(gnl->fd, gnl->buf, BUFF_SIZE);
		if (gnl->ret == -1)
		{
			del_fd(list, gnl->fd, tmp);
			return (-1);
		}
		gnl->i = 0;
		if (gnl->ret == 0)
		{
			if (gnl->nl == 0)
			{
				*line = *tmp;
				return (1);
			}
		}
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	t_gnl			*gnl;
	int				ret;
	char			*tmp;

	if ((fd <= 2 && !(fd == 0)) || !line || BUFF_SIZE <= 0)
		return (-1);
	tmp = ft_strnew(0);
	gnl = get_fd(&list, fd);
	while (gnl->ret > 0)
	{
		if ((ret = read_buf(&list, gnl, line, &tmp)) != 0)
			return (ret);
		if (gnl->i < gnl->ret)
		{
			tmp = ft_strdeljoin(tmp, get_line(gnl));
			if (gnl->nl)
			{
				*line = tmp;
				return (1);
			}
		}
	}
	del_fd(&list, gnl->fd, &tmp);
	return (0);
}
