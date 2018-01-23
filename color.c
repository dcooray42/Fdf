/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 08:41:11 by dcooray           #+#    #+#             */
/*   Updated: 2017/01/20 08:41:15 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_color(t_line *line, t_mlx *mlx, t_coord *c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = ft_strdup(line->line[c->x]);
	while (str[i] != '\0' && str[i] != ',')
		i++;
	if (str[i] == ',')
	{
		i++;
		if (str[i] != '\0' && str[i] == '0' && ft_toupper(str[i + 1]) == 'X')
		{
			i += 2;
			j = i;
			while (str[j] != '\0' && ft_isxdigit(str[j]))
				j++;
			if (str[j] == '\0')
				hex_to_int(mlx, &str[i], ft_strlen(&str[i]) - 1);
		}
	}
	else
		mlx->clr = 0xFFFFFF;
	ft_strdel(&str);
}

int		ret_power(int nbr, int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (nbr);
	return (ret_power(nbr, power - 1) * nbr);
}

void	hex_to_int(t_mlx *mlx, char *str, int power)
{
	int	i;
	int	pwr;
	int	tmp;

	i = 0;
	mlx->clr = 0;
	while (str[i] != '\0')
	{
		pwr = ret_power(16, power - i);
		if (ft_isalpha(str[i]))
			tmp = (ft_toupper(str[i]) - 'A' + 10) * pwr;
		else
			tmp = (str[i] - '0') * pwr;
		mlx->clr += tmp;
		i++;
	}
}
