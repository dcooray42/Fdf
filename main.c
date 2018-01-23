/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:59:58 by dcooray           #+#    #+#             */
/*   Updated: 2017/01/13 21:00:00 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc == 2)
	{
		list = read_file(argv[1]);
		expose(&list);
	}
	else
	{
		ft_putstr("Usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" <filename>\n");
	}
	return (0);
}
