/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:00:30 by ssibai            #+#    #+#             */
/*   Updated: 2023/07/11 19:00:30 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;
	char	*pstr1;
	char	*pstr2;

	pstr1 = (char *)str1;
	pstr2 = (char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (pstr1[i] != pstr2[i])
			return ((unsigned char)pstr1[i] - (unsigned char)pstr2[i]);
		i ++;
	}
	return (0);
}
