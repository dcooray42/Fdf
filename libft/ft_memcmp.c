/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:24:33 by dcooray           #+#    #+#             */
/*   Updated: 2016/11/07 15:43:15 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*str1;
	const char	*str2;
	size_t		i;

	str1 = (const char *)s1;
	str2 = (const char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (str1[i] == str2[i] && i < (n - 1))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
