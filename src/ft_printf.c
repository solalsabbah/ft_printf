/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:34:50 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/30 17:11:47 by ssabbah          ###   ########.fr       */
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

	va_start(ap, format);
	j = 0;
	p = format; // p est un pointeur sur l adresse ? ca veut dire je modifie le contenu de format ?
	flag = 0;
	while (p[j] != 0) 
	{
		if (p[j] != '%')
			ft_putchar(p[j]);
		else if (p[j] == '%')
		{
			j++;
			j = j + ft_fmt(&p[j], ap); // continuer le curseur a la suite du format
		} 
		j++;
	}
	va_end(ap);
	return (0);
}

int main(void)
{
	int a = 43;

	ft_printf("ceci et le test n: %+30x, apres c est fini %s \n", a, "ok");
//	ft_printf("%b\n", a);
//	printf("real : %d\n", a);
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
