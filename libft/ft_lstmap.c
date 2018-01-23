/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:24:41 by dcooray           #+#    #+#             */
/*   Updated: 2016/11/11 13:25:07 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *map, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!map)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (map != NULL)
		new = f(map);
	new->next = ft_lstmap(map->next, f);
	return (new);
}
