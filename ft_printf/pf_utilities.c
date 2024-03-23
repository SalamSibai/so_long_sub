/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:35:43 by ssibai            #+#    #+#             */
/*   Updated: 2023/08/08 16:15:48 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putstr(char *c, int fd)
{
	int	i;

	if (c == NULL)
	{
		write (fd, "(null)", 6);
		return (6);
	}
	i = 0;
	while (c[i] != '\0')
	{
		write (fd, &c[i], 1);
		i ++;
	}
	return (i);
}

int	pf_putchar(char c, int fd)
{
	write (fd, &c, 1);
	return (1);
}

int	pf_putnbr(int n, int fd)
{
	int		ctr;

	ctr = 0;
	if (n == -2147483648)
	{
		ctr += pf_putstr("-214", 1);
		ctr += pf_putnbr(7483648, fd);
	}
	else
	{
		if (n < 0)
		{
			ctr += pf_putchar('-', fd);
			n *= -1;
		}
		if (n < 10)
			ctr += pf_putchar(n + '0', fd);
		else
		{
			ctr += pf_putnbr(n / 10, fd);
			ctr += pf_putnbr(n % 10, fd);
		}
	}
	return (ctr);
}

int	pf_put_u_nbr(unsigned int n, int fd)
{
	int		ctr;
	char	c;

	ctr = 0;
	c = '0';
	if (n < 10)
	{
		c = n + '0';
		ctr += pf_putchar(c, fd);
	}
	else
	{
		ctr += pf_putnbr(n / 10, fd);
		ctr += pf_putnbr(n % 10, fd);
	}
	return (ctr);
}
