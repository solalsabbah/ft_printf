/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:53:57 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/14 16:12:30 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

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
		else	
			print_width(nb, len, 0);
		ft_putnbr_uns(ival);
	}
	return (len);
}

int			print_oct(va_list ap, int nb, int prec, int *flags)
{
	int 			len;
	unsigned int	ival;
	long int		val;

	ival = va_arg(ap, unsigned int);
	val = ft_convert_oct(ival);
	if (flags[2] == 1 || flags[4] == 1)
		return (-1);
	len = int_len(val);
	print_flags_oct(val, len, nb, flags);
	if (nb > len)
		return (nb);
	return (len);
}
