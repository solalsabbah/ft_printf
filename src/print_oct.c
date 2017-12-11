/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:53:57 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/11 15:57:23 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>

long int	negtounsigned(int nb)
{
	if (nb < 0)
		return (4294967296 + nb);
	else
		return (nb);
}

int			print_flags_oct(long int ival, int len, int nb, int *flags)
{
	if (flags[0] == 1 && flags[1] != 1)
	{
		if (flags[3] == 1)
			print_width(--nb, len, 1);
		else
			print_width(--nb, len, 0);
		ft_putchar('0');
		ft_putnbr_uns(ival);
	}
	if (flags[1] == 1)
	{
		if (flags[0] == 1)
		{
			nb--;
			ft_putchar('0');
		}
		ft_putnbr_uns(ival);
		print_width(nb, len, 0);
	}
	else if (flags[1] != 1 && flags[0] != 1)
	{
		if (flags[3] == 1)
			print_width(nb, len, 1);
		ft_putnbr_uns(ival);
	}
	return (len);
}

int			print_oct(va_list ap, int nb, int *flags)
{
	int len;
	int ival;
	long int val;

	ival = va_arg(ap, int);
	val = ft_convert_oct(ival);
	if (flags[2] == 1 || flags[4] == 1 || (flags[1] == 1 && flags[3] == 1))
		return (-1);
	if (ival < 0)
		val = ft_convert_uns_oct(negtounsigned(ival));
	len = int_len(val);
	print_flags_oct(val, len, nb, flags);
	return (len);
}
