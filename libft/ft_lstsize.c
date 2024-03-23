/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:41:10 by ssibai            #+#    #+#             */
/*   Updated: 2023/07/25 13:11:53 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ctr;
	t_list	*ctr_p;

	ctr = 0;
	ctr_p = lst;
	while (ctr_p != NULL)
	{
		ctr++;
		ctr_p = ctr_p -> next;
	}
	return (ctr);
}
