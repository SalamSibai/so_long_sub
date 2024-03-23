/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:26:58 by ssibai            #+#    #+#             */
/*   Updated: 2023/07/17 18:39:47 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*strdst;
	unsigned char	*strsrc;
	size_t			i;

	strdst = (unsigned char *)dst;
	strsrc = (unsigned char *)src;
	i = 0;
	while (strdst > strsrc && i < len)
		i++;
	while (i > 0)
	{
		strdst[i - 1] = strsrc[i - 1];
		i--;
	}
	while (strdst < strsrc && i < len)
	{
		if (strdst[i] != strsrc[i])
			strdst[i] = strsrc [i];
		i++;
	}
	return (dst);
}
