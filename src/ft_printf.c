/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:34:50 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/12 17:04:42 by ssabbah          ###   ########.fr       */
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

char *s = "salut";
char *c = "cool";


//===== STR  =======//

	printf("A <%5s ca va ? j'a  %#x ans>\n", s, 32);
	ft_printf(ANSI_COLOR_RED "A <%5s ca va ? j'a  %#x ans>\n"ANSI_COLOR_RESET, s, 32);
	
	printf("=== ligne 0 ====\n");
	printf("A <%12s>\n", s);
	ft_printf("B <%12s>\n", s);

	printf("=== ligne 1 ====\n");
	printf("A <%-12s>\n", s);
	ft_printf("B <%-12s>\n", s);
	
	printf("=== ligne 2 ====\n");
	printf("A <%-23s>\n", c);
	ft_printf("B <%-23s>\n", c);

	printf("\n=== ligne 2 ====\n");
	printf("A <%-23s>\n", c);
	ft_printf("B <%-23s>\n", c);

	printf("\n=== ligne 3 ====\n");
	printf("A <%s>\n", s);
	ft_printf("B <%s>\n", s);
	

/*
//========== TEST  pour Hex  ==========//
	
	printf("A <%#5x>\n",35);
	ft_printf("B <%#5x>\n", 35);
	
	printf("=== ligne 0 ====\n");
	printf("A <%#12x>\n", 35);
	ft_printf("B <%#12x>\n", 35);

	printf("=== ligne 1 ====\n");
	printf("A <%#-12x>\n",35);
	ft_printf("B <%#-12x>\n", 35);
	
	printf("=== ligne 2 ====\n");
	printf("A <%#-23x>\n",35);
	ft_printf("B <%#-23x>\n", 35);

	printf("\n=== ligne 2 ====\n");
	printf("A <%#-23x>\n",35);
	ft_printf("B <%#-23x>\n", 35);

	printf("\n=== ligne 3 ====\n");
	printf("A <%x>\n",35);
	ft_printf("B <%x>\n", 35);
	
	printf("\n=== ligne 4 ====\n");
	printf("A <%#01x>\n",-35);
	ft_printf("B <%#01x>\n", -35);
	
	printf("\n=== ligne 5 ====\n");
	printf("A <%03x>\n",-3500);
	ft_printf("B <%03x>\n",-3500);

	printf("\n=== ligne 6 ====\n");
	printf("A <%-32x>\n",-35);
	ft_printf("B <%-32x>\n", -35);
	
	printf("\n=== ligne 7 ====\n");
	printf("A <%0032x>\n",-12335);
	ft_printf("B <%0032x>\n", -12335);
	
	printf("\n=== ligne 7 bis ====\n");
	printf("A <%032x>\n", -35);
	ft_printf("B <%0032x>\n", -35);

	printf("\n=== ligne 8 ====\n");
	printf("A <%x>\n",35);
	ft_printf("B <%x>\n", 35);
	
	printf("=== ligne 9 ====\n");
	printf("A <%05x>\n", 35);
	ft_printf("B <%05x>\n", 35);
	
	printf("=== ligne 10 ====\n");
	printf("A <%-6x>\n", 35);
	ft_printf("B <%-6x>\n", 35);
	
	printf("\n=== ligne 11 ====\n");
	printf("A <%-6x>\n", -35);
	ft_printf("B <%-6x>\n", -35);
	
	printf("\n=== ligne 12 ====\n");
	printf("A <%#-1x>\n", -35);
	ft_printf("B <%#-1x>\n", -35);

	printf("\n=== ligne 13 ====\n");
	printf("A <%-6x>\n", -3509);
	ft_printf("B <%-6x>\n", -3509);


//========== TEST  pour O  ==========//
	
	printf("A <%0#5o>\n",35);
	ft_printf("B <%0#5o>\n", 35);
	
	printf("=== ligne 0 ====\n");
	printf("A <%#12o>\n", 35);
	ft_printf("B <%#12o>\n", 35);

	printf("=== ligne 1 ====\n");
	printf("A <%#-12o>\n",35);
	ft_printf("B <%#-12o>\n", 35);
	
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
	printf("A <%03o>\n",-3500);

	printf("=== ligne 6 ====\n");
	printf("A <%-32o>\n",-35);
	ft_printf("B <%-32o>\n", -35);
	
	printf("=== ligne 7 ====\n");
	printf("A <%0032o>\n",-12335);
	ft_printf("B <%0032o>\n", -12335);
	
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
	printf("A <%#-1o>\n", -35);
	ft_printf("B <%#-1o>\n", -35);

	printf("=== ligne 13 ====\n");
	printf("A <%-6o>\n", -3509);
	ft_printf("B <%-6o>\n", -3509);



 //========== TEST  pour D ==========//
	
	printf("A <%0+12d>\n",35);
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
