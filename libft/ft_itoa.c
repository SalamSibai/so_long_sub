/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:38:01 by ssibai            #+#    #+#             */
/*   Updated: 2023/07/23 16:19:25 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int	num;
	int	numlen;

	numlen = 0;
	num = n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		numlen++;
		while (num < 0)
		{
			num = num / 10;
			numlen++;
		}
	}
	else
	{
		while (num > 0)
		{
			num = num / 10;
			numlen++;
		}
	}
	return (numlen);
}

char	*make_str(int n, int numlen, char *s)
{
	int		end;
	int		nd;
	char	*c;
	int		i;

	end = 0;
	nd = 0;
	c = s;
	i = numlen;
	if (n < 0)
	{
		c[0] = '-';
		n = n * -1;
		end++;
		nd++;
	}
	while (i >= end)
	{
		c[i] = (n % 10) + '0';
		n = n / 10;
		i--;
		nd++;
	}
	c[nd] = '\0';
	return (c);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		numlen;

	numlen = digit_count(n);
	s = NULL;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == INT_MAX)
		return (ft_strdup("2147483647"));
	if (n == 0)
		return (ft_strdup("0"));
	s = malloc((numlen + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	numlen --;
	s = make_str(n, numlen, s);
	return (s);
}
