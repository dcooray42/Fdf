/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:59:42 by dcooray           #+#    #+#             */
/*   Updated: 2017/01/13 21:56:31 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct	s_line
{
	char	**line;
	int		x;
	int		y;
}				t_line;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		h;
	int		w;
	int		scl;
	int		z;
	int		clr;
}				t_mlx;

typedef struct	s_coord
{
	int		x;
	int		y;
	int		z;
	int		i;
	int		x_max;
}				t_coord;

typedef struct	s_iso
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;
}				t_iso;

typedef struct	s_tmp
{
	t_iso	*iso;
	t_coord	*c;
	t_mlx	*mlx;
	t_list	*list;
}				t_tmp;

t_list			*read_file(char *argv);
void			init_line(t_list **list, char *str, int line_nb);
void			del_list(t_list **list);
void			malloc_error(void);
void			empty_file(void);
void			basic_error(char *argv);
void			error_x(t_list **list);
void			ft_error(t_list **list);
void			draw_flat(t_mlx *mlx, t_list *list);
void			return_scl(t_list *list, t_mlx *mlx, int x, int y);
int				return_max_z(t_list *list, t_mlx *mlx);
void			expose(t_list **list);
void			put_pixel(t_list *list, t_mlx *mlx, t_coord *c, t_iso *iso);
void			put_pixel_bis(t_list *list, t_mlx *mlx, t_coord *c, t_iso *iso);
void			init_iso(t_iso *iso, t_coord *c, t_mlx *mlx, t_list *list);
void			init_iso_last(t_iso *iso, t_coord *c, t_mlx *mlx, t_list *list);
void			init_iso_last_bis(t_iso *iso, t_coord *c, t_mlx *mlx,
									t_list *list);
void			c_z_coord(t_line *line, t_coord *c, t_mlx *mlx);
void			z_y_coord(t_list *list, int *z_y, t_coord *c, t_mlx *mlx);
void			straight_line(t_iso *i, t_iso *i_t, t_mlx *mlx, t_coord *c);
void			straight_line_last(t_iso *i, t_iso *i_t, t_mlx *mlx);
void			straight_line_last_bis(t_iso *i, t_iso *i_t, t_mlx *mlx);
void			cpy_iso(t_iso *iso, t_iso *iso_tmp);
void			reverse_list(t_list **list);
void			init_param_pixel(t_iso **iso, t_line **line, t_list *list,
									t_coord *c);
void			init_param_pixel_bis(t_iso **iso, t_coord *c, t_tmp **tmp);
int				key_hook(int keycode, void *param);
t_tmp			*init_tmp(t_list *list, t_mlx *mlx, t_coord *c, t_iso *iso);
void			put_pixel_ter(t_tmp *tmp, t_iso *iso_tmp);
void			get_color(t_line *line, t_mlx *mlx, t_coord *c);
int				ret_power(int nbr, int power);
void			hex_to_int(t_mlx *mlx, char *str, int power);
int				red_cross(void *param);

#endif
