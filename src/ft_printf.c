/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:34:50 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/07 18:18:53 by ssabbah          ###   ########.fr       */
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
//========== TEST  pour O  ==========//
	
	printf("A <%0#12o>\n",35);
	ft_printf("B <%0#12o>\n", 35);
	
	printf("=== ligne 0 ====\n");
	printf("A <%0#12o>\n", -35);
	ft_printf("B <%0#12o>\n", -35);

	printf("=== ligne 1 ====\n");
	printf("A <%#-o>\n",35);
	ft_printf("B <%#-o>\n", 35);
	
	printf("=== ligne 2 ====\n");
	printf("A <%#-23o>\n",35);
	ft_printf("B <%#-23o>\n", 35);

	printf("=== ligne 2 ====\n");
	printf("A <%#-23o>\n",35);
	ft_printf("B <%#-23o>\n", 35);

	printf("=== ligne 3 ====\n");
	printf("A <%o>\n",35);
	ft_printf("B <%o>\n", 35);
	
	printf("=== ligne 4 ====\n");
	printf("A <%#01o>\n",-35);
	ft_printf("B <%#01o>\n", -35);
	
	printf("=== ligne 5 ====\n");
	printf("A <%03o>\n",-350);
	ft_printf("B <%03o>\n", -350);
	
	printf("=== ligne 6 ====\n");
	printf("A <%-32o>\n",-35);
	ft_printf("B <%-32o>\n", -35);
	
	printf("=== ligne 7 ====\n");
	printf("A <%0032o>\n",35);
	ft_printf("B <%0032o>\n", 35);
	
	printf("=== ligne 7 bis ====\n");
	printf("A <%032o>\n", -35);
	ft_printf("B <%0032o>\n", -35);

	printf("=== ligne 8 ====\n");
	printf("A <%o>\n",35);
	ft_printf("B <%o>\n", 35);
	
	printf("=== ligne 9 ====\n");
	printf("A <%05o>\n", 35);
	ft_printf("B <%05o>\n", 35);
	
	printf("=== ligne 10 ====\n");
	printf("A <%-6o>\n", 35);
	ft_printf("B <%-6o>\n", 35);
	
	printf("=== ligne 11 ====\n");
	printf("A <%-6o>\n", -35);
	ft_printf("B <%-6o>\n", -35);
	
	printf("=== ligne 12 ====\n");
	printf("A <%-1o>\n", -35);
	ft_printf("B <%-1o>\n", -35);

	printf("=== ligne 13 ====\n");
	printf("A <%-6o>\n", -35);
	ft_printf("B <%-6o>\n", -35);



 //========== TEST  pour D ==========//
	
/*	printf("A <%0+12d>\n",35);
	ft_printf("B <%0+12d>\n", 35);
	
	printf("=== ligne 0 ====\n");
	printf("A <%0+12d>\n", -35);
	ft_printf("B <%0+12d>\n", -35);

	printf("=== ligne 1 ====\n");
	printf("A <%+-d>\n",35);
	ft_printf("B <%+-d>\n", 35);
	
	printf("=== ligne 2 ====\n");
	printf("A <%+-23d>\n",35);
	ft_printf("B <%+-23d>\n", 35);

	printf("=== ligne 2 ====\n");
	printf("A <%+-23d>\n",35);
	ft_printf("B <%+-23d>\n", 35);

	printf("=== ligne 3 ====\n");
	printf("A <%d>\n",35);
	ft_printf("B <%d>\n", 35);
	
	printf("=== ligne 4 ====\n");
	printf("A <%+01d>\n",-35);
	ft_printf("B <%+01d>\n", -35);
	
	printf("=== ligne 5 ====\n");
	printf("A <% 03d>\n",-350);
	ft_printf("B <% 03d>\n", -350);
	
	printf("=== ligne 6 ====\n");
	printf("A <%-32d>\n",-35);
	ft_printf("B <%-32d>\n", -35);
	
	printf("=== ligne 7 ====\n");
	printf("A <%0032d>\n",35);
	ft_printf("B <%0032d>\n", 35);
	
	printf("=== ligne 7 bis ====\n");
	printf("A <%032d>\n", -35);
	ft_printf("B <%0032d>\n", -35);

	printf("=== ligne 8 ====\n");
	printf("A <% d>\n",35);
	ft_printf("B <% d>\n", 35);
	
	printf("=== ligne 9 ====\n");
	printf("A <%  05d>\n", 35);
	ft_printf("B <% 05d>\n", 35);
	
	printf("=== ligne 10 ====\n");
	printf("A <%- 6d>\n", 35);
	ft_printf("B <%- 6d>\n", 35);
	
	printf("=== ligne 11 ====\n");
	printf("A <%- 6d>\n", -35);
	ft_printf("B <%- 6d>\n", -35);
	
	printf("=== ligne 12 ====\n");
	printf("A <%- 1d>\n", -35);
	ft_printf("B <%- 1d>\n", -35);

	printf("=== ligne 13 ====\n");
	printf("A <%- 6d>\n", -35);
	ft_printf("B <%- 6d>\n", -35);

*/

//printf("",);
	return (0);
}
