/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:34:50 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/24 19:36:35 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../includes/libft.h"

int				ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	int		ret;
	t_form  form;
	va_list		ap;
	const char	*p;

	i = 0;
	ret = 0;
	va_start(ap, format);
	p = format;
	while (p[i] != 0) 
	{
		p[i] != '%' ? ft_putchar(p[i]) : 0;
		if (p[i] == '%')
		{
			if (ft_strpbrk(&p[i + 1], "sSpdDioOuUxXcCBb%") == NULL)
				return (1);
			len = ft_strpbrk(&p[i + 1], "sSpdDioOuUxXcCBb%") - &p[i + 1];
			ret = ret + ft_fmt(ft_strsub(&p[i + 1], 0, len + 1), ap, &form) - 1;
			i = ft_strpbrk(&p[i + 1], "sSpdDioOuUxXcCBb%") - &p[0];
		}
		ret++;
		i++;
	}
	va_end(ap);
	return (ret);
}

/*
int		main()
{
   	ft_printf("<%2.11u>\n", -1);
	printf("<%2.11u>\n", -1);
   	ft_printf("<%+11u>\n", 34);
	printf("<%+11u>\n", 34);
   	ft_printf("<%012u>\n", 1);
	printf("<%012u>\n", 1);
   	ft_printf("<%012u>\n", -1);
	printf("<%012u>\n", -1);
   	ft_printf("<%+-12u>\n", 1);
	printf("<%+-12u>\n", 1);
   	ft_printf("<%+-12u>\n", -1);
	printf("<%+-12u>\n", -1);
}
int		main(void)
{
	int a;	
	int b;
	  ft_printf("<%6.7u>\n", 295);
	  printf("<%6.7u>\n", 295);
	  ft_printf("<%-15u>\n", 4294967295);
	  printf("<%015u>\n", 4294967295);
	ft_printf("[%lld] wefw\n", -9223372036854775808);
	ft_printf("%hd wefw\n", -9);
	ft_printf("%jd wefw\n", -9);
	ft_printf("%zd wefw\n", -9);
	ft_printf("%hhd wefw\n", -9);
	ft_printf("%ld wefw\n", -9223372036854775808);
	ft_printf("%jd\n", -9223372036854775808);

	ft_printf("<%10.5d>\n", 4242);
	printf("<%10.5d>\n", 4242);
   	
	ft_printf("<%-5.10o>\n", 2500);	
   	printf("<%-5.10o>\n", 2500);	
	a = ft_printf("%#x\n", -42);
	b = ft_printf("%#X\n", 42);
	printf("%d\n", a);
	printf("%d\n", b);
	printf("=== ligne 11 ====\n");
	printf("A <%-6o>\n", 35);
	ft_printf("B <%-6o>\n", 35);
	
	printf("=== ligne 12 ====\n");
	printf("A <%- 1d>\n", -35);
	ft_printf("B <%- 1d>\n", -35);

	printf("=== ligne 13 ====\n");
	printf("A <%-6llo>\n", 123333599999912);
	ft_printf("B <%-6llo>\n", 123333599999912);

	printf("=== ligne 0 ====\n");
	printf("A <%0+12d>\n", -35);
	ft_printf("B <%0+12d>\n", -35);

	printf("%d\n", a);
	return (0);
}








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

	printf("=== ligne 14 ====\n");
	a = ft_printf("[%zd]\n", 3);	
	a = ft_printf("%");	
	b = printf("@moulitest: %.d %.0d\n", 0, 0);	
//===== STR  =======//

	char s[] ="salut";
	char c[]= "oui";
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
	a = ft_printf("<@moulitest: %.10d>\n", -42);
	printf("%d\n", a);
	b = printf("<@moulitest: %.10d>\n", -42);
	printf("%d\n", b);
	b = printf("<@moulitest: %#.x %#.0x>\n", 0, 0);
	ft_printf("@moulitest: %.10d\n", -42);
	ft_printf("@moulitest: %.o %.0o", 0, 0);
	ft_printf("@moulitest: %o\n", 0);
	ft_printf("%5o\n", 41);	
	printf("%d\n", b);
	printf("prec : 10 wdth : 0\n");
 	ft_printf("[%05o]\n", 42);
	printf("[%05o]\n", 42);	
 	printf("=========\n");
 	printf("prec : 10 wdth : 11 0 flag\n");
 	ft_printf("[%-10.5o]\n", 2500);	
	printf("[%-10.5o]\n", 2500);	
 	printf("=========\n");
 	printf("prec : 3 wdth : 10\n");
	ft_printf("[%10.3o]\n", 32);	
	printf("[%10.3o]\n", 32);	
 	printf("=========\n");
 	printf("=========\n");
 	printf("prec : 3 wdth : 2\n");
 	ft_printf("[%03.2d]\n", -3);	
	printf("[%03.2d]\n", -3);	
 	printf("=========\n");
	a = ft_printf("<%4.15d\n>", 42);
	b = printf("<%5.0s>\n", "this");
//	ft_printf("%#X\n", 0);
//	printf("\n<%d>\n", ft_printf("%X", 23454));
//	printf("\n<%d>\n", ft_printf("%x", 23454));


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

	ft_printf("\n");	
	return (0);
}
*/ 
