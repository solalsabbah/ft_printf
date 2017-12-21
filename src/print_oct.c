/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:53:57 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/19 16:39:14 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int			print_second_case(long int ival, int len, int nb, int prec, int *flags)
{
	if (flags[1] != 1 && flags[0] != 1)
	{
		if (flags[3] == 1 && prec == -1)
			 print_width(nb, len, 1);	
		else if (prec > nb)
		{	
			print_width(nb, prec, 0);	
			print_prec(prec, len, 1);
		}
		else if (flags[3] != 1)
		{	
			if (prec > len)
			{
				print_width(nb, prec, 0);
				print_width(prec, len, 1);
			}
			if (prec == -1)
				flags[3] == 1 ? print_width(nb, len, 1) : print_width(nb, len, 0);
			prec == 0 && ival != 0 ? print_width(nb, len, 1) : 0;
			prec == 0 && ival == 0 ? print_width(nb, 0, 0) : 0;
		}
		ival == 0 && prec == 0 ? 0 : ft_putnbr_uns(ival);
	}
	return (len);
}
int			print_first_case(long int ival, int len, int nb, int prec, int *flags)
{
	if (flags[0] == 1 && flags[1] != 1)
	{
		flags[3] == 1 ? print_width(--nb, len, 1) : print_width(--nb, len, 0);
		ft_putchar('0');
		prec == 0 && ival == 0 ? 0 : ft_putnbr_uns(ival);
	}
	if (flags[1] == 1)
	{
		if (flags[0] == 1)
		{
			nb--;
			ft_putchar('0');
		}
		print_prec(prec, len, 1);	
		ft_putnbr_uns(ival);
		prec > len ? print_width(nb, prec, 0) : print_width(nb, len, 0);
	}
	return (len);
}

int			print_oct(va_list ap, int nb, int prec, int *flags)
{
	int 		len;
	unsigned int	ival;
	long int	val;

	ival = va_arg(ap, unsigned int);
	val = ft_convert_oct(ival);
	if (flags[2] == 1 || flags[4] == 1)
		return (-1);
	len = int_len(val);
	print_first_case(val, len, nb, prec, flags);
	print_second_case(val, len, nb, prec, flags);
	val == 0 && prec == 0 ?  len = 0 : 0;
	if (prec > len)
		len = prec;
	if (flags[0] == 1 && val == 0)
		len = len + 1;
	if (nb > len)
		return (nb);
	return (len);
}
