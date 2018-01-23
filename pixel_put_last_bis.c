/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put_last_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:58:59 by dcooray           #+#    #+#             */
/*   Updated: 2017/01/13 21:05:32 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_tmp	*init_tmp(t_list *list, t_mlx *mlx, t_coord *c, t_iso *iso)
{
	t_tmp	*tmp;

	if ((tmp = (t_tmp *)ft_memalloc(sizeof(t_tmp))) == NULL)
	{
		del_list(&list);
		ft_memdel((void **)&mlx);
		ft_memdel((void **)&c);
		ft_memdel((void **)&iso);
		malloc_error();
	}
	tmp->list = list;
	tmp->iso = iso;
	tmp->mlx = mlx;
	tmp->c = c;
	return (tmp);
}

void	put_pixel_ter(t_tmp *tmp, t_iso *iso_tmp)
{
	t_line	*line;

	line = (t_line *)tmp->list->content;
	init_iso(tmp->iso, tmp->c, tmp->mlx, tmp->list);
	if (tmp->c->i > 0 || (tmp->c->i == 0 && tmp->c->x > 0))
		straight_line(tmp->iso, iso_tmp, tmp->mlx, tmp->c);
	if (tmp->c->i + 1 == tmp->mlx->scl && tmp->list->next != NULL)
	{
		cpy_iso(tmp->iso, iso_tmp);
		init_iso_last(tmp->iso, tmp->c, tmp->mlx, tmp->list);
		straight_line_last(tmp->iso, iso_tmp, tmp->mlx);
		init_iso(tmp->iso, tmp->c, tmp->mlx, tmp->list);
	}
	if (tmp->c->i + 1 == tmp->mlx->scl && tmp->c->x == line->x - 2)
	{
		cpy_iso(tmp->iso, iso_tmp);
		init_iso_last_bis(tmp->iso, tmp->c, tmp->mlx, tmp->list);
		straight_line_last_bis(tmp->iso, iso_tmp, tmp->mlx);
		init_iso(tmp->iso, tmp->c, tmp->mlx, tmp->list);
	}
	cpy_iso(tmp->iso, iso_tmp);
	put_pixel_bis(tmp->list, tmp->mlx, tmp->c, tmp->iso);
}

void	init_iso_last_bis(t_iso *iso, t_coord *c, t_mlx *mlx, t_list *list)
{
	int		z_y;
	int		i;
	t_line	*line;

	line = (t_line *)list->content;
	z_y = 0;
	if (line->line[c->x + 1] != NULL)
	{
		i = ft_atoi(line->line[c->x + 1]);
		z_y = i * mlx->scl;
	}
	iso->x2 = c->x * mlx->scl + c->y * mlx->scl;
	iso->x1 = iso->x2;
	iso->y2 = (c->y * mlx->scl - (c->x + 1) * mlx->scl) / 2
		- ((53 * z_y) / 100) + mlx->z;
	iso->y1 = iso->y2;
}

void	straight_line_last_bis(t_iso *i, t_iso *i_t, t_mlx *mlx)
{
	if (i_t->y2 + 1 > i->y2)
		while (i_t->y2 > i->y2)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, i_t->x2, i_t->y2, mlx->clr);
			i_t->y2--;
		}
	if (i_t->y2 - 1 < i->y2)
		while (i_t->y2 < i->y2)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, i_t->x2, i_t->y2, mlx->clr);
			i_t->y2++;
		}
}
