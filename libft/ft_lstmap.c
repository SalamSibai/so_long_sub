/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:38:03 by ssibai            #+#    #+#             */
/*   Updated: 2023/07/25 17:51:40 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*del_and_free(t_list *node, void (*del)(void *))
{
	ft_lstclear(&node, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newl;
	t_list	*temp;

	if (lst == NULL || f == NULL )
		return (NULL);
	newl = ft_lstnew(f(lst -> content));
	if (newl == NULL)
		return (NULL);
	temp = NULL;
	lst = lst -> next;
	while (lst != NULL)
	{
		temp = ft_lstnew(f(lst -> content));
		if (temp == NULL)
			del_and_free(lst, del);
		ft_lstadd_back(&newl, temp);
		lst = lst -> next;
	}
	return (newl);
}
