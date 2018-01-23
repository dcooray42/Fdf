/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:35:13 by dcooray           #+#    #+#             */
/*   Updated: 2016/11/07 13:57:45 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*str;
	unsigned char	l;
	size_t			i;

	str = (char *)b;
	l = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i] = l;
		i++;
	}
	return (b);
}
