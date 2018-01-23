/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:57:39 by dcooray           #+#    #+#             */
/*   Updated: 2016/11/11 13:23:37 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_num_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= (-1);
	}
	if (n >= 10)
	{
		i = 1 + ft_num_len(n / 10);
		ft_num_len(n % 10);
	}
	else
		i++;
	return (i);
}

static	int		ft_isneg(int n, int *neg)
{
	*neg = 0;
	if (n < 0)
	{
		n *= -1;
		*neg = 1;
	}
	return (n);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg;
	int		tmp;

	tmp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n = ft_isneg(n, &neg);
	i = ft_num_len(n);
	if (tmp < 0)
		i++;
	if ((str = (char *)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
