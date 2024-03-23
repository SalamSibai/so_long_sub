/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:23:10 by ssibai            #+#    #+#             */
/*   Updated: 2023/07/24 14:30:28 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ns;
	unsigned int	i;
	size_t			slen;

	if (f == NULL || s == NULL || ft_strlen(s) == 0)
		return (ft_strdup("\0"));
	slen = ft_strlen(s);
	i = 0;
	ns = malloc (slen + 1 * sizeof(char));
	if (ns == NULL)
		return (NULL);
	while (i < slen)
	{
		ns[i] = f(i, s[i]);
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
