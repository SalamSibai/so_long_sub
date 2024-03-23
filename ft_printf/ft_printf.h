/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai <ssibai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:35:32 by ssibai            #+#    #+#             */
/*   Updated: 2023/08/08 16:09:24 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *type, ...);
int	pf_putstr(char *c, int fd);
int	pf_putchar(char c, int fd);
int	pf_putnbr(int n, int fd);
int	pf_put_u_nbr(unsigned int n, int fd);
int	hex_convrt(unsigned long n, int fd, int up, int p);

#endif