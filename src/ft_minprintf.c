/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:04:17 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/14 17:30:52 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../includes/header.h"
#include "../libft/libft.h"

const char		*after_percent(const char *p)
{
	int nb;
	int i;
	
	i = 0;	
	nb = ft_atoi(&p[i]);
	while (p[i] >= '0' && p[i] <= '9')
		i++;
	return (&p[i]);
}
void	ft_minprintf(const char *fmt, ...)
{
	va_list		ap;
	const char	*p;
	const char	*sval;
	int		ival;
//	double		dval;
	char		cval;
//	int			nb;
	int			tot;

	tot = 0;
	va_start(ap, fmt);
	p = fmt;
	while (*p != 0) 
	{
		if (*p != '%')
			ft_putchar(*p);
		else if (*p == '%')
		{
			p++;
			p = after_percent(&*p);
			if (*p == 'd' || *p == 'x' || *p == 'o' )
			{
				ival = va_arg(ap, int);
				if (*p == 'd')
					ft_putnbr(ival);
				if (*p == 'x')
					ft_convert_hex(ival);
				if (*p == 'o')
					ft_convert_oct(ival);
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
