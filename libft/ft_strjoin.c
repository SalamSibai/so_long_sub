/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:57:45 by ssibai            #+#    #+#             */
/*   Updated: 2023/07/25 18:42:51 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_result(char *s, char const *s1, char const *s2)
{
	char		*join;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	join = s;
	while (i < ft_strlen(s1))
	{
		join[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		join[j] = s2[i];
		j++;
		i++;
	}
	join[j] = 0;
	return (join);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	s1len;
	size_t	s2len;

	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	join = malloc((s1len + s2len + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	return (join_result(join, s1, s2));
}
