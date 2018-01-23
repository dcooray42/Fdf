/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:49:56 by dcooray           #+#    #+#             */
/*   Updated: 2016/11/11 13:22:43 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)ft_memchr(dst, '\0', size);
	if (!s1)
		return (size + ft_strlen(src));
	s2 = (char *)src;
	i = (size_t)(s1 - dst) + ft_strlen(s2);
	while ((size_t)(s1 - dst) < size - 1 && *s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return (i);
}
