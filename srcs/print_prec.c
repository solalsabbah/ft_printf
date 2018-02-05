/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:08:13 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:36:43 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_prec(int prec, int len, int type)
{
	char c;

	c = ' ';
	if (type == 1)
		c = '0';
	while (prec > len)
	{
		ft_putchar(c);
		prec--;
	}
	return (prec);
}
