/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:12:18 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/29 15:36:53 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <stdio.h>

int			flags(const char **str)
{
	int i;

	i = 0;
	while (str[i] != 'S' ||str[i] != 's' || str[i] != 'd' || str[i] != 'D' || str[i] != 'i' || str[i] != 'o' || str[i] != 'O' || str[i] != 'x' || str[i] != 'X' || str[i] != 'c' || str[i] != 'C' || str[i] != 'n' || str[i] != 'u' || str[i] != 'U' || str[i] != 'b' || str[i] != 'B')
	{
		if (str[i] == '#')
		if (str[i] == '+')
		if (str[i] == '-')
		if (str[i] == '0')
	}	
	printf("%s\n", *str);
	return (0);
}
