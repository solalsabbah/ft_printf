/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:04:17 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/15 20:17:18 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../includes/header.h"
#include "../libft/libft.h"

void	ft_print_number(const char p, int ival, int nb)
{
	int_len(ival);	
	if (p == 'd')
	{
		nb = 0;
		ft_putnbr(ival);
	}
	if (p == 'x')
		ft_convert_hex(ival);
	if (p == 'o')
		ft_convert_oct(ival);

}

void	ft_minprintf(const char *fmt, ...)
{
	va_list		ap;
	const char	*p;
	const char	*sval;
	int		ival;
	char		cval;
	int			nb;

	nb = 0;
	va_start(ap, fmt);
	p = fmt;
	while (*p != 0) 
	{
		if (*p != '%')
			ft_putchar(*p);
		else if (*p == '%')
		{
			p++;
			nb = ft_atoi(p);
			while (*p >= '0' && *p <= '9')
				p++;
			if (*p == 'd' || *p == 'x' || *p == 'o' )
			{
				ival = va_arg(ap, int);
				ft_print_number(*p, ival, nb);
			}
			if (*p == 's')
			{
				sval = va_arg(ap, char *);
				ft_putstr(sval);
			}
			if (*p == 'c')
			{	
				cval = va_arg(ap, int);	
				ft_putchar(cval);
			}
		}
		p++;
	}
	va_end(ap);
}
