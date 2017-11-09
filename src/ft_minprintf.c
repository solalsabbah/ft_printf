/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:04:17 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/09 15:35:12 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	ft_minprintf(const char *fmt, ...)
{
	va_list		ap;
	const char	*p;
	const char	*sval;
	int			ival;
	double		dval;
	
	va_start(ap, fmt);
	p = fmt;
	for (p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue; 
		}
		switch (*++p)
		{
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break ;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
					  putchar(*sval);
				  break;
		}
	}
	va_end(ap);
}

int main() 
{
	ft_minprintf("int %d\n", 5);
	ft_minprintf("String %s et int %d\n","Bonjour",5);
	//ft_minprintf("Une serie d'entiers: %d, %d, %d, %d, %d\n",1,2,3,4,5);
	return 0;
}
