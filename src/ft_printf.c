/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:15:41 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/08 17:53:16 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <stdio.h>

int		ft_printf(const char *restrict format, ...)
{
	return (0);
}

int		main(int argc, char **argv)
{
	int number;

	number = 3;	
	printf(" %-10d \n", number);
	printf(" %010d \n", number);
	printf(" %-#10x \n", number);  
	printf(" %u \n", number / 2);  
	printf(" %#x \n", number);
	printf("%%no argument expected");
	return (0);	
}
