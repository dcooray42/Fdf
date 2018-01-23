/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:17:04 by dcooray           #+#    #+#             */
/*   Updated: 2016/11/09 18:17:44 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	l;
	int		i;
	int		j;

	l = (char)c;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == l)
			j = i;
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	else if (!j && s[0] != l)
		return (NULL);
	else
		return ((char *)&s[j]);
}
