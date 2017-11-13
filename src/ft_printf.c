/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:15:41 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/13 14:29:01 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <stdio.h>

int		ft_printf(const char *restrict format, ...)
{
	format = NULL;
	//ft_minprintf("%c\n", 'c');
	ft_minprintf("J'ai %x ans en hexadecimal\n", 23);
	ft_minprintf("Je m'appelle %s, j'ai %d\n","Solal", 15);
	//ft_minprintf("Une serie d'entiers: %d, %d, %d, %d, %d\n",1,2,3,4,5);
	return (0);
}

int main(void)
{
	ft_printf("14");
	return (0);
}
