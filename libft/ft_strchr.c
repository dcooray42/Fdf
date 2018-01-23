/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:00:51 by dcooray           #+#    #+#             */
/*   Updated: 2016/11/04 16:14:27 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	l;
	int		i;

	l = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == l)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] != l)
		return (NULL);
	else
		return ((char *)&s[i]);
}
