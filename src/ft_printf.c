/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:34:50 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/29 15:52:34 by ssabbah          ###   ########.fr       */
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
	int		nb;
	int		flag;
	int		i;

	t_fct        g_fct_tab[] =
	{
		{'S', &print_str},
		{'s', &print_str},
	//	{'p', &print_ptr}, NOT MANAGED YET
		{'d', &print_int},
		{'D', &print_int},
		{'i', &print_int},
		{'o', &print_oct},
		{'O', &print_oct},
		{'x', &print_hex},
		{'X', &print_hex},
		{'c', &print_char},
		{'C', &print_char},
		{'n', &print_blank}, 
		{'u', &print_uns_int},
		{'U', &print_uns_int}, 
		{'b', &print_bin},
		{'B', &print_bin},
		{0, NULL}
	};
	va_start(ap, format);
	p = format; // p est un pointeur sur l adresse ? ca veut dire je modifie le contenu de format ?
	flag = 0;
	while (*p != 0) 
	{
		if (*p != '%')
			ft_putchar(*p);
		else if (*p == '%')
		{
			p++;
			flags(&p);
			nb = ft_atoi(p);
			while (*p >= '0' && *p <= '9')
			{
				if (*p == '0') /// attention ca ne marche pas si 20 par exemple
					flag = 1;	
				p++;
			}
			i = 0;
			while (g_fct_tab[i].c != 0)
			{
				if (g_fct_tab[i].c == '0')
					break;
				if (g_fct_tab[i].c == *p)
					g_fct_tab[i].f(ap, nb);
				i++;
			}
		}
		p++;
	}
	va_end(ap);
	return (0);
}

int main(void)
{
	int a = -213648;

	ft_printf("%d\n test", a);
	ft_printf("%b\n", a);
	printf("%d\n", a);
	//a = 0;	
	//printf("%i\n", 'c');
	//ft_printf("%i\n", 'c');
	//ft_printf("salut %n toi\n", &a);
	//printf("salut %n toi\n", &a);
	//int age = 33;
	//int *ptrage = &age;
	//char c = 's';
	//char *ptrc = &c;	
	//printf("---------\n");
	//ft_printf("%p\n", age);
	//printf("---------\n");	
	//printf("%p\n", &c);
/*	printf("---------\n");
	ft_printf("hexa %x\n", &age);
	printf("---------\n");
	printf("vrai adresse %p\n", &age);
	printf("---------\n");
	ft_printf("%d\n", 511390);
	printf("%d\n", 511390);
	printf("===============\n");
	ft_printf("%23s\n", "511390");
	printf("%23s\n", "511390");
	printf("===============\n");
	ft_printf("%X\n", 1385261640);
	printf("%0X\n", 1385261640);
	printf("===============\n");
	ft_printf("%0023o\n", 511390);
	printf("%023o\n", 511390);
	printf("===============\n"); 

	//ft_printf(" Je m'apelle %12s, j'ai %11o ans\n", "Solal", 23);
	//printf(" Je m'apelle %12s, j'ai %11o ans\n", "Solal", 23);
	//ft_printf("Je m'appelle %s, j'ai %42d ans\n", "Solal", 23);
	//ft_printf("J'ai %x ans en hexadecimal\n", 23);
	//printf("%6s\n", "chien");
	//printf("%d\n", ft_atoi("005d\n"));*/
	return (0);
}
