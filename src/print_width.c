/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:49:23 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/19 14:33:14 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		print_width(int nb, int len, int flag)
{
	char c;

	c = ' ';
	if (flag == 1)
		c = '0';
	while (nb > len)
	{
		ft_putchar(c);
		nb--;
	}
	return (nb);
}
