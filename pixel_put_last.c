/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:00:06 by dcooray           #+#    #+#             */
/*   Updated: 2017/01/13 21:09:55 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_iso_last(t_iso *iso, t_coord *c, t_mlx *mlx, t_list *list)
{
	int		z_y;
	int		i;
	t_line	*line_n;

	line_n = NULL;
	if (list->next != NULL)
		line_n = (t_line *)list->next->content;
	z_y = 0;
	if (line_n != NULL)
	{
		i = ft_atoi(line_n->line[c->x]);
		z_y = i * mlx->scl;
	}
	iso->x1 = c->x * mlx->scl + c->y * mlx->scl;
	iso->x2 = iso->x1;
	iso->y1 = ((c->y + 1) * mlx->scl - c->x * mlx->scl) / 2
		- ((53 * z_y) / 100) + mlx->z;
	iso->y2 = iso->y1;
}

void	straight_line_last(t_iso *i, t_iso *i_t, t_mlx *mlx)
{
	if (i_t->y1 + 1 > i->y1)
		while (i_t->y1 > i->y1)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, i_t->x1, i_t->y1, mlx->clr);
			i_t->y1--;
		}
	else if (i_t->y1 - 1 < i->y1)
		while (i_t->y1 < i->y1)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, i_t->x1, i_t->y1, mlx->clr);
			i_t->y1++;
		}
}

void	init_param_pixel(t_iso **iso, t_line **line, t_list *list, t_coord *c)
{
	if ((*iso = (t_iso *)ft_memalloc(sizeof(t_iso))) == NULL)
	{
		del_list(&list);
		ft_memdel((void **)&c);
		malloc_error();
	}
	*line = (t_line *)list->content;
	c->x = 0;
}

void	init_param_pixel_bis(t_iso **iso, t_coord *c, t_tmp **tmp)
{
	c->y++;
	ft_memdel((void **)tmp);
	ft_memdel((void **)iso);
}

int		key_hook(int keycode, void *param)
{
	t_mlx	*mlx;

	if (keycode == 53)
	{
		mlx = (t_mlx *)param;
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_window(mlx->mlx, mlx->win);
		ft_memdel((void **)&param);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
