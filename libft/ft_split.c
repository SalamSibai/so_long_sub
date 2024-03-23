/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:57:46 by ssibai            #+#    #+#             */
/*   Updated: 2023/07/24 14:13:59 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_end(char const *s, int begin, char c)
{
	int	end;

	end = begin;
	while (s[end] && s[end] != c)
		end++;
	return (end);
}

int	word_count(char const *s, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
		}
		else
		{
			wc++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (wc);
}

void	free_split(char **p)
{
	int	j;

	j = 0;
	while (p[j] != NULL)
	{
		free (p[j]);
		j++;
	}
	free(p);
}

void	fill_p(char **p, char const *s, char c, int wc)
{
	unsigned int	begin;
	unsigned int	end;
	int				i;

	begin = 0;
	end = 0;
	i = 0;
	while (i < wc)
	{
		while (s[begin] != '\0' && s[begin] == c)
			begin++;
		end = set_end(s, begin, c);
		p[i] = ft_substr(s, begin, (size_t) end - begin);
		if (p[i] == NULL)
			return (free_split(p));
		begin = end;
		i++;
	}
	p[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		wc;

	wc = 0;
	if (s == NULL)
		return (NULL);
	wc = word_count(s, c);
	p = malloc((wc + 1) * sizeof(char *));
	if (p == NULL)
		return (NULL);
	fill_p(p, s, c, wc);
	return (p);
}
