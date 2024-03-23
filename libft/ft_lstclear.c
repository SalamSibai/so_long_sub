/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:03:47 by ssibai            #+#    #+#             */
/*   Updated: 2023/07/25 14:39:00 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*flushed;

	if (lst == NULL || *lst == NULL || (*del) == NULL)
		return ;
	flushed = NULL;
	ft_lstiter(*lst, del);
	while (*lst != NULL)
	{
		flushed = *lst;
		*lst = ((*lst))-> next;
		free (flushed);
	}
	lst = NULL;
}
