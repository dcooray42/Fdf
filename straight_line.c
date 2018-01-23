/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   straight_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:00:14 by dcooray           #+#    #+#             */
/*   Updated: 2017/01/13 21:01:55 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	straight_line(t_iso *i, t_iso *i_t, t_mlx *mlx, t_coord *c)
{
	if (i_t->y1 - 1 > i->y1 && !(c->i == 0 && c->x > 0))
		while (i_t->y1 > i->y1)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, i_t->x1, i_t->y1, mlx->clr);
			i_t->y1--;
		}
	else if (i_t->y1 + 1 < i->y1 && !(c->i == 0 && c->x > 0))
		while (i_t->y1 < i->y1)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, i_t->x1, i_t->y1, mlx->clr);
			i_t->y1++;
		}
	if (c->x + 1 < c->x_max && i_t->y2 - 1 > i->y2)
		while (i_t->y2 > i->y2)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, i_t->x2, i_t->y2, mlx->clr);
			i_t->y2--;
		}
	else if (c->x + 1 < c->x_max && i_t->y2 + 1 < i->y2)
		while (i_t->y2 < i->y2)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, i_t->x2, i_t->y2, mlx->clr);
			i_t->y2++;
		}
}

void	put_pixel_bis(t_list *list, t_mlx *mlx, t_coord *c, t_iso *iso)
{
	t_line	*line;

	line = (t_line *)list->content;
	if (list->next != NULL)
		mlx_pixel_put(mlx->mlx, mlx->win, iso->x1, iso->y1, mlx->clr);
	if (line->line[c->x + 1] != NULL)
		mlx_pixel_put(mlx->mlx, mlx->win, iso->x2, iso->y2, mlx->clr);
	c->i++;
}

void	cpy_iso(t_iso *iso, t_iso *iso_tmp)
{
	iso_tmp->x1 = iso->x1;
	iso_tmp->x2 = iso->x2;
	iso_tmp->y1 = iso->y1;
	iso_tmp->y2 = iso->y2;
}

void	reverse_list(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp_ret;
	t_list	**tmp_l;
	t_line	*line;
	int		y;

	tmp_ret = NULL;
	tmp_l = list;
	line = (t_line *)(*tmp_l)->content;
	y = line->y;
	while (*tmp_l != NULL)
	{
		line = (t_line *)(*tmp_l)->content;
		line->y = y;
		tmp = ft_lstnew(line, sizeof(t_line));
		ft_lstadd(&tmp_ret, tmp);
		ft_memdel((void **)&line);
		tmp = (*tmp_l)->next;
		ft_memdel((void **)tmp_l);
		*tmp_l = tmp;
	}
	del_list(list);
	*list = tmp_ret;
}
