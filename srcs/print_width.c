/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:49:23 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:36:59 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_width(int width, int len, int flag)
{
	char c;

	c = ' ';
	if (flag == 1)
		c = '0';
	if (len == -1)
		len = 0;
	while (width > len)
	{
		ft_putchar(c);
		width--;
	}
	return (width);
}
