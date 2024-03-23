/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:35:23 by ssibai            #+#    #+#             */
/*   Updated: 2023/08/08 16:08:28 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_identifier(const char *type, va_list arg, int i)
{
	if (type[i + 1] == '%')
		return (pf_putchar('%', 1));
	if (type[i + 1] == 's')
		return (pf_putstr((char *) va_arg(arg, char *), 1));
	if (type[i + 1] == 'c')
		return (pf_putchar(((char) va_arg(arg, int)), 1));
	if (type[i + 1] == 'd' || type[i + 1] == 'i')
		return (pf_putnbr(((int) va_arg(arg, int)), 1));
	if (type[i + 1] == 'u')
		return (pf_put_u_nbr((va_arg(arg, unsigned int)), 1));
	if (type[i + 1] == 'x')
		return (hex_convrt((va_arg(arg, unsigned int)), 1, 0, 0));
	if (type[i + 1] == 'X')
		return (hex_convrt((va_arg(arg, unsigned int)), 1, 1, 0));
	if (type[i + 1] == 'p')
		return (hex_convrt((va_arg(arg, unsigned long long)), 1, 0, 1));
	return (0);
}

int	ft_printf(const char *type, ...)
{
	int		ctr;
	va_list	args;
	int		i;

	va_start(args, type);
	i = 0;
	ctr = 0;
	while (type[i] != '\0')
	{
		if (type[i] == '%')
		{
			ctr += type_identifier(type, args, i);
			i++;
		}
		else
			ctr += pf_putchar(type[i], 1);
		i++;
	}
	va_end (args);
	return (ctr);
}
