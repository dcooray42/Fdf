/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:00:19 by dcooray           #+#    #+#             */
/*   Updated: 2016/11/09 18:28:32 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*str;
	unsigned char	i;
	size_t			j;

	str = (const char *)s;
	i = (unsigned char)c;
	j = 0;
	while (j < n)
	{
		if ((unsigned char)str[j] == i)
			return ((void *)&s[j]);
		j++;
	}
	return (NULL);
}
