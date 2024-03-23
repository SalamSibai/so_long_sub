/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:35:47 by ssibai            #+#    #+#             */
/*   Updated: 2023/08/08 16:16:20 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_toupper(char c, int fd)
{
	if (c >= 'a' && c <= 'f')
		c = c - 32;
	return (pf_putchar(c, fd));
}

int	hex_convrt(unsigned long n, int fd, int up, int p)
{
	char			*c;
	unsigned long	div;
	int				ctr;
	int				mod;

	ctr = 0;
	if (p == 1)
	{
		ctr += pf_putchar('0', fd);
		ctr += pf_putchar('x', fd);
	}
	if (n == 0)
		return (ctr + pf_putchar('0', fd));
	c = "0123456789abcdef";
	div = n / 16;
	mod = n % 16;
	if (div == 0)
	{
		if (up == 1)
			return (ctr + pf_toupper(c[mod], fd));
		return (ctr + pf_putchar(c[mod], fd));
	}
	return (ctr + hex_convrt(div, fd, up, 0) + hex_convrt(mod, fd, up, 0));
}
