/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:04:17 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/16 17:20:03 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../includes/header.h"
#include "../libft/libft.h"

int		print_width(int nb, int len, int flag)
{
	char c;
	
	c = ' ';
	if (flag == 1)
		c = '0';
	while (nb > len)
	{
		ft_putchar(c);
		nb--;
	}
	return (0);
}

void	print_str(const char *sval, int nb)
{
		int	len;

		len = ft_strlen(sval);
		while (nb > len)
		{
			ft_putchar(' ');
			nb--;
		}
		ft_putstr(sval);
}

void	ft_print_number(const char p, int ival, int nb, int flag)
{
	int		len;
	char	*str;
	
	if (p == 'd')
	{
		len = int_len(ival);
		print_width(nb, len, flag);
		ft_putnbr(ival);
	}
	if (p == 'X')
	{
		str = ft_convert_hex(ival);
		len = ft_strlen(str);
		print_width(nb, len, flag);
		ft_putstr(str);
		
	}	
	if (p == 'o')
	{
		len = int_len(ft_convert_oct(ival));	
		print_width(nb, len, flag);	
		ft_putnbr(ft_convert_oct(ival));
	}
}

void	ft_minprintf(const char *fmt, ...)
{
	va_list		ap;
	const char	*p;
	const char	*sval;
	int		ival;
	char		cval;
	int			nb;
	int			flag;

	va_start(ap, fmt);
	p = fmt;
	flag = 0;
	while (*p != 0) 
	{
		if (*p != '%')
			ft_putchar(*p);
		else if (*p == '%')
		{
			p++;
			nb = ft_atoi(p);
			while (*p >= '0' && *p <= '9')
			{
				if (*p == '0')
					flag = 1;	
				p++;
			}
			if (*p == 'd' || *p == 'X' || *p == 'o' )
			{
				ival = va_arg(ap, int);
				ft_print_number(*p, ival, nb, flag);
			}
			else if (*p == 's')
			{
				sval = va_arg(ap, char *);
				print_str(sval, nb);
			}
			else if (*p == 'c')
			{	
				cval = va_arg(ap, int);	
				ft_putchar(cval);
			}
		}
		p++;
	}
	va_end(ap);
}
