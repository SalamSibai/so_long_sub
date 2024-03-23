/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:51:09 by ssibai            #+#    #+#             */
/*   Updated: 2024/02/10 13:35:05 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	findstart(char const *str, char const *set)
{
	int		j;
	int		begin;
	int		len;
	char	*c;

	begin = 0;
	len = (int)ft_strlen(str);
	j = 0;
	while (j < len)
	{
		c = ft_strchr(set, str[j]);
		if (c == NULL)
			break ;
		begin++;
		j++;
	}
	return (begin);
}

int	findend(char const *str, char const *set)
{
	int		end;
	int		len;
	char	*c;

	end = (int)ft_strlen(str);
	len = end - 1;
	while (len >= 0)
	{
		c = ft_strchr(set, str[len]);
		if (c == NULL)
			break ;
		end--;
		len--;
	}
	return (end);
}

char	*cpyresult(char *trim, char const *s1, int start, int finish)
{
	int	i;

	i = 0;
	while (start < finish)
	{
		trim[i] = s1[start];
		i++;
		start++;
	}
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	char	*trim;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	begin = findstart(s1, set);
	end = findend(s1, set);
	if (begin >= end)
		return (ft_strdup(""));
	trim = malloc((end - begin + 1) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	trim = cpyresult(trim, s1, begin, end);
	trim [end - begin] = 0;
	return (trim);
}
