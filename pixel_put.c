/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:59:22 by dcooray           #+#    #+#             */
/*   Updated: 2017/01/13 21:08:35 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_list *list, t_mlx *mlx, t_coord *c, t_iso *iso)
{
	t_line	*line;
	t_iso	*iso_tmp;
	t_tmp	*tmp;

	init_param_pixel(&iso_tmp, &line, list, c);
	c->x_max = line->x;
	tmp = init_tmp(list, mlx, c, iso);
	while (line->line[c->x] != NULL)
	{
		c->i = 0;
		get_color(line, tmp->mlx, tmp->c);
		while (c->i < mlx->scl)
			put_pixel_ter(tmp, iso_tmp);
		c->x++;
	}
	init_param_pixel_bis(&iso_tmp, c, &tmp);
}

void	init_iso(t_iso *iso, t_coord *c, t_mlx *mlx, t_list *list)
{
	int		z_y;
	t_line	*line;
	t_line	*line_n;

	line = (t_line *)list->content;
	line_n = NULL;
	if (list->next != NULL)
		line_n = (t_line *)list->next->content;
	c->z = 0;
	z_y = 0;
	if (line->line[c->x + 1] != NULL)
		c_z_coord(line, c, mlx);
	if (line_n != NULL)
		z_y_coord(list, &z_y, c, mlx);
	iso->x1 = c->x * mlx->scl + (c->y * mlx->scl + c->i);
	iso->x2 = c->x * mlx->scl + c->i + c->y * mlx->scl;
	iso->y1 = (c->y * mlx->scl + c->i - c->x * mlx->scl) / 2
		- ((53 * z_y) / 100) + mlx->z;
	iso->y2 = (c->y * mlx->scl - (c->x * mlx->scl + c->i)) / 2
		- ((53 * c->z) / 100) + mlx->z;
}

void	c_z_coord(t_line *line, t_coord *c, t_mlx *mlx)
{
	int	i;
	int	j;

	i = ft_atoi(line->line[c->x]);
	j = ft_atoi(line->line[c->x + 1]);
	if (i != j)
	{
		if (i > j)
			c->z = i * mlx->scl - (i - j) * c->i;
		else if (i < j)
			c->z = i * mlx->scl + (j - i) * c->i;
	}
	if (j == 0)
		c->z = i * mlx->scl - i * c->i;
	if (i == j)
		c->z = i * mlx->scl;
}

void	z_y_coord(t_list *list, int *z_y, t_coord *c, t_mlx *mlx)
{
	t_line	*line;
	t_line	*line_n;
	int		i;
	int		j;

	line = (t_line *)list->content;
	line_n = (t_line *)list->next->content;
	i = ft_atoi(line->line[c->x]);
	j = ft_atoi(line_n->line[c->x]);
	if (i != j)
	{
		if (i > j)
			*z_y = i * mlx->scl - (i - j) * c->i;
		else if (i < j)
			*z_y = i * mlx->scl + (j - i) * c->i;
	}
	if (j == 0)
		*z_y = i * mlx->scl - i * c->i;
	if (i == j)
		*z_y = i * mlx->scl;
}
