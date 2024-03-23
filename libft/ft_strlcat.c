/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:17:28 by ssibai            #+#    #+#             */
/*   Updated: 2024/02/10 13:35:24 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	if (!dst && !dstsize)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	j = 0;
	if (dstsize < dstlen)
		return (srclen + dstsize);
	while (dstlen + 1 < dstsize && src[j] != 0)
		dst[dstlen++] = src[j++];
	if (dstlen < dstsize)
		dst[dstlen] = '\0';
	while (src[j++] != 0)
		dstlen++;
	return (dstlen);
}
