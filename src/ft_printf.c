/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:34:50 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/05 15:28:33 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../includes/header.h"
#include "../libft/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*p;
	int		flag;
	int		j;
	int		ret;
	
	ret = 0;
	va_start(ap, format);
	j = 0;
	p = format;
	flag = 0;
	while (p[j] != 0) 
	{
		if (p[j] != '%')
			ft_putchar(p[j]);
		else if (p[j] == '%')
		{
			j++;
			j = j + ft_fmt(&p[j], ap);
		}
		j++;
	}
	va_end(ap);
	ret = ret + j;
	return (ret);
}

int main(void)
{
		
	printf("A <%0+12d>\n",35);
	ft_printf("B <%0+12d>\n", 35);
	printf("=== ligne 1 ====\n");
	printf("A <%+-d>\n",35);
	ft_printf("B <%+-d>\n", 35);
	printf("=== ligne 2 ====\n");
	printf("A <%+-23d>\n",35);
	ft_printf("B <%+-23d>\n", 35);
	printf("=== ligne 3 ====\n");
	printf("A <%d>\n",35);
	ft_printf("B <%d>\n", 35);
	printf("=== ligne 4 ====\n");
	printf("A <%01d>\n",-35);
	ft_printf("B <%01d>\n", -35);
	printf("=== ligne 5 ====\n");
	printf("A <%0032d>\n",-35);
	ft_printf("B <%0032d>\n", -35);
	printf("=== ligne 6 ====\n");
	printf("A <%0032d>\n",-35);
	ft_printf("B <%0032d>\n", -35);
	printf("=== ligne 7 ====\n");
	printf("A <%0032d>\n",35);
	ft_printf("B <%0032d>\n", 35);
	printf("=== ligne 8 ====\n");
	printf("A <%0032d>\n",35);
	ft_printf("B <%0032d>\n", 35);
	printf("A <%  05d>\n", 35);
	ft_printf("B <%  05d>\n", 35);
	printf("A <%-+ 32d>\n",35);
	ft_printf("B <%-+ 32d>\n", 35);
	printf("A <%+30d>\n",0);
	ft_printf("B <%+30d>\n", 0);



//printf("",);
	return (0);
}
