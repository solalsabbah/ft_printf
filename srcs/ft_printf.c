/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:34:50 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/28 18:50:28 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "../includes/libft.h"

t_fct	g_fct_tab[] =
{
	{'S', &print_str},
	{'s', &print_str},
	{'p', &print_ptr},
	{'d', &print_int},
	{'D', &print_int},
	{'i', &print_int},
	{'o', &print_oct},
	{'O', &print_oct},
	{'x', &print_hex},
	{'X', &print_hex},
	{'c', &print_char},
	{'C', &print_char},
	{'u', &print_uns_int},
	{'U', &print_uns_int},
	{'b', &print_bin},
	{'B', &print_bin},
	{'%', &print_percent},
	{0, NULL}
};

void		init_format(t_form *form)
{
	form->width = 0;
	form->prec = -1;
	form->length = -1;
	form->field = 0;
}

int			ft_fmt(const char *str, va_list ap, t_form *form)
{
	int		i;
	int		ret;
	int 	*flags;

	i = 0;
	init_format(form);
	flags = ft_flags(str);
	width(str, form);
	precision(str, form);
	length(str, form);
	field(str, form);
	str = ft_strpbrk(str, "sSpdDioOuUxXcCBb%");
	while (g_fct_tab[i].c != '0')
	{
		if (g_fct_tab[i].c == str[0])
		{
			ret = g_fct_tab[i].f(ap, form, flags);
			return (ret);
		}
		i++;
	}
	return (0);
}

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
			if (ft_strpbrk(&p[i + 1], "sSpdDioOuUxXcCBb%") != NULL)
			{
				len = ft_strpbrk(&p[i + 1], "sSpdDioOuUxXcCBb%") - &p[i + 1];
				ret = ret + ft_fmt(ft_strsub(&p[i + 1], 0, len + 1), ap, &form) - 1;
				i = ft_strpbrk(&p[i + 1], "sSpdDioOuUxXcCBb%") - &p[0];
			}
			else 
				ret--;
		}
		ret++;
		i++;
	}
	va_end(ap);
	return (ret);
}
	/*

int		main(void)
{
	int a;	
	int b;
	
	a = printf("<%010d>\n", 110);
	b = ft_printf("<%010d>\n", 110);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%010d>\n", -110);
	b = ft_printf("<%010d>\n", -110);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%+6d>\n", 110);
	b = ft_printf("<%+6d>\n", 110);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%+4d>\n", 110);
	b = ft_printf("<%+4d>\n", 110);
	printf("%d\n", a);
	printf("%d\n", b);		
	a = printf("<%+4.1d>\n", 110);
	b = ft_printf("<%+4.1d>\n", 110);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%+6.d>\n", -40);
	b = ft_printf("<%+6.d>\n", -40);
	printf("%d\n", a);
	printf("%d\n", b);		
	

	a = printf("<%+4.1d>\n", -32);
	b = ft_printf("<%+4.1d>\n", -32);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%+5.d>\n", -5123);
	b = ft_printf("<%+5.d>\n", -5123);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%+3.5d>\n", -5123);
	b = ft_printf("<%+3.5d>\n", -5123);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%+.2d>\n", 0);
	b = ft_printf("<%+.2d>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%15.5d>\n", 0);
	b = ft_printf("<%15.5d>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%.5d>\n", 0);
	b = ft_printf("<%.5d>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);


	a = printf("<%10d>\n", -42);
	b = ft_printf("<%10d>\n", -42);
	printf("%d\n", a);
	printf("%d\n", b);		

	a = printf("<% d>\n", -1);
	b = ft_printf("<% d>\n", -1);
	printf("%d\n", a);
	printf("%d\n", b);		

	a = printf("<%12d>\n", 42);
	b = ft_printf("<%12d>\n", 42);
	printf("%d\n", a);
	printf("%d\n", b);		

	a = printf("<% +d>\n", 42);
	b = ft_printf("<% +d>\n", 42);
	printf("%d\n", a);
	printf("%d\n", b);		

	a = printf("<%04d>\n", 110);
	b = ft_printf("<%04d>\n", 110);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%04.1d>\n", 110);
	b = ft_printf("<%04.1d>\n", 110);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%06.d>\n", -40);
	b = ft_printf("<%06.d>\n", -40);
	printf("%d\n", a);
	printf("%d\n", b);		
	

	a = printf("<%04.1d>\n", -32);
	b = ft_printf("<%04.1d>\n", -32);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%05.d>\n", -5123);
	b = ft_printf("<%05.d>\n", -5123);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%03.5d>\n", -5123);
	b = ft_printf("<%03.5d>\n", -5123);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%0.2d>\n", 0);
	b = ft_printf("<%0.2d>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);		
	
	a = printf("<%15.5d>\n", 0);
	b = ft_printf("<%15.5d>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%.5d>\n", 0);
	b = ft_printf("<%.5d>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);

	a = printf("<% d>\n", -9999);
	b = ft_printf("<% d>\n", -9999);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%.2d>\n", 0);
	b = ft_printf("<%.2d>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);

	a = printf("<% .d>\n", 0);
	b = ft_printf("<% .d>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%15.4d>\n", -42);
	b = ft_printf("<%15.4d>\n", -42);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%.d>\n", 0);
	b = ft_printf("<%.d>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%.0d>\n", 0);
	b = ft_printf("<%.0d>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%10d>\n", -42);
	b = ft_printf("<%10d>\n", -42);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%10d>\n", -42);
	b = ft_printf("<%10d>\n", -42);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%zd>\n", 42);
	b = ft_printf("<%zd>\n", 42);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%zd>\n", 0);
	b = ft_printf("<%zd>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);

	a = printf("<%d>\n", 0);
	b = ft_printf("<%d>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = ft_printf("<%D>\n", 2147483647);
	b = printf("<%D>\n", 2147483647);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = ft_printf("<%0.4c>\n", 'a');
	b = printf("<%0.4c>\n", 'a');
	printf("%d\n", a);
	printf("%d\n", b);

	a = printf("%hD, %hD\n", 0, 65535);
	b = ft_printf("%hD, %hD\n", 0, 65535);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = ft_printf("<%0.4c>\n", 'a');
	b = printf("<%0.4c>\n", 'a');
	printf("%d\n", a);
	printf("%d\n", b);

	a = ft_printf("<%lld>\n", -9223372036854775808);
	b = printf("<%lld>\n", -9223372036854775808);
	printf("%d\n", a);
	printf("%d\n", b);
  	
	a = printf("<%.8x>\n", 42);
    b = ft_printf("<%.8x>\n", 42);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%#.8x>\n", 42);
    b = ft_printf("<%#.8x>\n", 42);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%#6x>\n", 42);
    b = ft_printf("<%#6x>\n", 42);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%#6.5x>\n", 42);
    b = ft_printf("<%#6.5x>\n", 42);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%#x>\n", 42);
    b = ft_printf("<%#x>\n", 42);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%-0.3x>\n", 0);
    b = ft_printf("<%#-0.3x>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%-0.3x>\n", 2);
    b = ft_printf("<%-0.3x>\n", 2);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%-08.3x>\n", 2);
    b = ft_printf("<%-08.3x>\n", 2);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%#12x>\n", 0);
    b = ft_printf("<%#12x>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%#12.3x>\n", 0);
    b = ft_printf("<%#12.3x>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%#12.3x>\n", 1);
    b = ft_printf("<%#12.3x>\n", 1);
	printf("%d\n", a);
	printf("%d\n", b);
	
	
	a = printf("<%#12.1x>\n", 42);
    b = ft_printf("<%#12.1x>\n", 42);
	printf("%d\n", a);
	printf("%d\n", b);

	a = ft_printf("<%#12.O>\n", 0);
	b = printf("<%#12.O>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = ft_printf("<%#12.O>\n", 0);
	b = printf("<%#12.O>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);

	a = ft_printf("<%#.O>\n", 0);
	b = printf("<%#.O>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);

	a = ft_printf("<%O>\n", 2147483647);
	b = printf("<%O>\n", 2147483647);
	printf("%d\n", a);
	printf("%d\n", b);
 
	a = printf("<%#o>\n", 35);
    b = ft_printf("<%#o>\n", 35);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%#.4o>\n", 0);
    b = ft_printf("<%#.4o>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%#.1o>\n", 0);
    b = ft_printf("<%#.1o>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%#.1o>\n", 0);
    b = ft_printf("<%#.1o>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%#12.15o>\n", 0);
    b = ft_printf("<%#12.15o>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("<%#12o>\n", 0);
    b = ft_printf("<%#12o>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);

	a = ft_printf("<%O>\n", 214);
	b = printf("<%O>\n", 214);
	printf("%d\n", a);
	printf("%d\n", b);
	
	
	a = printf("{% C}\n", L'a'); 
	b = ft_printf("{% c}\n", L'a'); 
	printf("%d\n", a);
	printf("%d\n", b);
	a = printf("a >%x<\n", LONG_MAX);
	b = ft_printf("b >%x<\n", LONG_MAX);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("a >%x<\n", 32);
	b = ft_printf("b >%x<\n", 32);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = ft_printf("<%#.O>\n", 0);
	b = printf("<%#.O>\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);

	a = printf("%U\n", ULONG_MAX);
	b = ft_printf("%U\n", ULONG_MAX);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("%lu\n", ULONG_MAX);
	b = ft_printf("%lu\n", ULONG_MAX);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("%lu\n", 0);
	b = ft_printf("%lu\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("%u%u%u%u%u\n", 1, 100, 999, 42, 999988888);
	printf("\n");	
	b = ft_printf("%u%u%u%u%u\n", 1, 100, 999, 42, 999988888);
	printf("%d\n", a);
	printf("%d\n", b);
	
	a = printf("%4.15u\n", 100);
	b = ft_printf("%4.15u\n", 100);
	printf("%d\n", a);
	printf("%d\n", b);
	
	printf("% o|%+o\n", 42, 42);
	ft_printf("% o|%+o\n", 42, 42);
	
	return (0);
}

*/





/*
   printf("A <%0#5.12o>\n",35);
   ft_printf("B <%0#5.12o>\n", 35);

   printf("=== ligne 0 ====\n");
   printf("A <%#o>\n", 35);
   ft_printf("B <%#o>\n", 35);

   printf("=== ligne 1 ====\n");
   printf("A <%#-12.o>\n",0);
   ft_printf("B <%#-12.o>\n", 0);

   printf("=== ligne 2 ====\n");
   printf("A <%#+23.o>\n",0);
   ft_printf("B <%#+23.o>\n", 0);

   printf("=== ligne 2 ====\n");
   printf("A <%#23.12o>\n",0);
   ft_printf("B <%#23.12o>\n", 0);

   printf("=== ligne 3 ====\n");
   printf("A <%.12o>\n",35);
   ft_printf("B <%.12o>\n", 35);

   printf("=== ligne 4 ====\n");
   printf("A <%#01o>\n",-35);
   ft_printf("B <%#01o>\n", -35);

   printf("=== ligne 5 ====\n");
   printf("A <%03o>\n",-3500);
   ft_printf("A <%03o>\n",-3500);

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


   a = printf("<%0.5%>\n", 0);
   b  = ft_printf("<%0.5%>\n", 0);

printf("%d\n", a);
printf("%d\n", b);
rintf("=== ligne 1 ====\n");
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



//========== TEST  pour D ==========//

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
