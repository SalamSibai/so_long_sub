/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:55:42 by ssibai            #+#    #+#             */
/*   Updated: 2024/02/10 13:35:02 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	slen;
	size_t	cctr;

	i = 0;
	if (s == NULL || start > ft_strlen(s) || s[0] == 0)
		return (ft_strdup("\0"));
	slen = ft_strlen(s);
	if (start + len < slen)
		cctr = len;
	else
		cctr = slen - (size_t) start;
	sub = malloc((cctr + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (i < cctr)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
