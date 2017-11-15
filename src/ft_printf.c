/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:15:41 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/15 20:17:29 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int		ft_printf(const char *restrict format, ...)
{
	//ft_minprintf("%c\n", 'c');
	ft_minprintf(format);
	//ft_minprintf("J'ai %o ans en octal\n", 23);
	//ft_minprintf("Une serie d'entiers: %d, %d, %d, %d, %d\n",1,2,3,4,5);
	return (0);
}

int main(void)
{
	printf("%s\n", ft_convert_hex(511390));
	printf("%X\n", 511390);
	//ft_printf("Je m'appelle %s, j'ai %42d ans\n", "Solal", 23);
	//ft_printf("J'ai %x ans en hexadecimal\n", 23);
	//printf("%6s\n", "chien");
	//printf("%d\n", ft_atoi("005d\n"));
	return (0);
}
