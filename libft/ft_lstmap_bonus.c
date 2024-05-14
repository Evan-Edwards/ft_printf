/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:35:23 by eedwards          #+#    #+#             */
/*   Updated: 2024/04/26 15:27:53 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*node;
	void	*current;

	if (!lst || !f || !del)
		return (NULL);
	map = NULL;
	while (lst)
	{
		current = f(lst->content);
		node = ft_lstnew(current);
		if (!node)
		{
			del(current);
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, node);
		lst = lst->next;
	}
	return (map);
}
