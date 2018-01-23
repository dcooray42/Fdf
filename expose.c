/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:59:12 by dcooray           #+#    #+#             */
/*   Updated: 2017/01/13 21:14:13 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_flat(t_mlx *mlx, t_list *list)
{
	t_coord	*c;
	t_iso	*iso;

	mlx->win = mlx_new_window(mlx->mlx, mlx->w, mlx->h, "fdf");
	if ((iso = (t_iso *)ft_memalloc(sizeof(t_iso))) == NULL)
	{
		del_list(&list);
		malloc_error();
	}
	if ((c = (t_coord *)ft_memalloc(sizeof(t_coord))) == NULL)
	{
		del_list(&list);
		ft_memdel((void **)&iso);
		malloc_error();
	}
	c->y = 0;
	while (list)
	{
		put_pixel(list, mlx, c, iso);
		list = list->next;
	}
	ft_memdel((void **)&c);
	ft_memdel((void **)&iso);
}

void	return_scl(t_list *list, t_mlx *mlx, int x, int y)
{
	int	z;
	int	i;

	z = return_max_z(list, mlx);
	mlx->scl = 40;
	i = 1;
	mlx->w = mlx->scl * (x + y - 2);
	mlx->h = (mlx->scl * (x + y - 2)) / 2 + 53 * (mlx->scl * z - 1) / 100 + 1;
	while (mlx->scl > 1 && i)
	{
		if (mlx->w > 1500 || mlx->h > 1000)
		{
			mlx->scl--;
			mlx->w = mlx->scl * (x + y - 2);
			mlx->h = (mlx->scl * (x + y - 2)) / 2 + 53
				* (mlx->scl * z - 1) / 100 + 1;
		}
		if (mlx->w <= 1500 && mlx->h <= 1000)
			i = 0;
	}
	if (mlx->z >= 0)
		mlx->z = mlx->h - ((y - 1) * mlx->scl) / 2 - 1;
	else
		mlx->z = mlx->h - ((y - 1) * mlx->scl) / 2 + 53
			* (mlx->z * mlx->scl) / 100 - 1;
}

int		return_max_z(t_list *list, t_mlx *mlx)
{
	int		z_min;
	int		z_max;
	int		i;
	int		tmp;
	t_line	*line;

	z_min = 0;
	z_max = 0;
	while (list)
	{
		i = 0;
		line = (t_line *)list->content;
		while (line->line[i] != NULL)
		{
			tmp = ft_atoi(line->line[i]);
			if (tmp < 0 && tmp < z_min)
				z_min = tmp;
			if (tmp > 0 && tmp > z_max)
				z_max = tmp;
			i++;
		}
		list = list->next;
	}
	mlx->z = z_min;
	return (z_max - z_min);
}

void	expose(t_list **list)
{
	t_mlx	*mlx;
	t_line	*line;
	int		x;
	int		y;

	if ((mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))) == NULL)
	{
		del_list(list);
		malloc_error();
	}
	line = (t_line *)(*list)->content;
	x = line->x;
	y = line->y;
	mlx->h = 0;
	mlx->w = 0;
	return_scl(*list, mlx, x, y);
	mlx->mlx = mlx_init();
	reverse_list(list);
	draw_flat(mlx, *list);
	mlx_key_hook(mlx->win, &key_hook, (void *)mlx);
	mlx_hook(mlx->win, 17, (1L << 17), &red_cross, (void *)mlx);
	del_list(list);
	mlx_loop(mlx->mlx);
}
