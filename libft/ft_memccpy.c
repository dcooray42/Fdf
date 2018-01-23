/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:28:26 by dcooray           #+#    #+#             */
/*   Updated: 2016/11/09 18:27:45 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*s1;
	const char		*s2;
	unsigned char	i;
	size_t			j;

	s1 = (char *)dst;
	s2 = (const char *)src;
	i = (unsigned char)c;
	j = 0;
	while (j < n)
	{
		s1[j] = s2[j];
		if ((unsigned char)s2[j] == i)
			return (&dst[j + 1]);
		j++;
	}
	return (NULL);
}
