/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:18:36 by ssibai            #+#    #+#             */
/*   Updated: 2024/02/10 13:35:40 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*strsrc;
	char			*strdst;

	i = -1;
	strsrc = (char *)src;
	strdst = (char *)dst;
	if (strsrc == NULL && strdst == NULL)
		return (dst);
	while (++i < n)
		strdst[i] = strsrc[i];
	return (dst);
}
