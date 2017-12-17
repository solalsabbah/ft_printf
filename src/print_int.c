/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:45:39 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/14 14:25:25 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int		first_case(int nb, int len, int ival, int *flags)
{
	if (flags[3] == 1 && flags[2] != 1 && flags[1] != 1 && flags[4] != 1)
	{
		if (ival < 0)
			ft_putsign(ival);
		print_width(nb, len, 1);
		ft_putnbr(abs_val(ival));
		return (1);
	}
	if (flags[2] == 1 && flags[1] != 1 && flags[3] != 1)
	{
		print_width(nb - 1, len, 0);
		ft_putsign(ival);
		ft_putnbr(abs_val(ival));
		return (1);
	}
	if ((flags[1] == 1 && flags[2] != 1 && flags[3] != 1 && flags[4] != 1))
	{
		ft_putnbr(ival);
		print_width(nb, len, 0);
		return (1);
	}
	return (0);
}

int		second_case(int nb, int len, int ival, int *flags)
{
	if (flags[2] == 1 && flags[3] == 1 && flags[1] != 1)
	{
		ft_putsign(ival);
		if (ival > 0)
			nb--;
		print_width(nb, len, 1);
		ft_putnbr(abs_val(ival));
		return (1);
	}
	if (flags[3] == 1 && flags[4] == 1 && flags[2] != 1 && flags[1] != 1)
	{
		ft_putchar(' ');
		print_width(nb - 1, len, 1);
		ft_putnbr(abs_val(ival));
		return (1);
	}
	if (flags[4] == 1 && flags[1] != 1 && flags[2] != 1 && flags[3] != 1)
	{
		if (ival > 0 && nb == 0)
			ft_putchar(' ');
		ft_putnbr(ival);
		return (1);
	}
	return (0);
}

int		third_case(int nb, int len, int ival, int *flags)
{
	if (flags[2] == 1 && flags[1] == 1)
	{
		ft_putsign(ival);
		ft_putnbr(abs_val(ival));
		print_width(nb - 1, len, 0);
		return (1);
	}
	if (flags[1] == 1 && flags[4] == 1 && flags[3] != 1)
	{
		if (ival < 0)
		{
			ft_putnbr(ival);
			print_width(nb, len, 0);
			return (1);
		}
		else
		{
			ft_putchar(' ');
			ft_putnbr(ival);
			nb--;
			print_width(nb, len, 0);
			return (1);
		}
	}
	return (0);
}

int		fourth_case(int nb, int len, int ival, int *flags)
{
	if (flags[1] != 1 && flags[2] != 1 && flags[3] != 1 & flags[4] != 1)
	{
		print_width(nb, len, 0);
		ft_putnbr(ival);
		return (1);
	}
	if (flags[1] == 1 && flags[3] == 1)
	{
		ft_putnbr(ival);
		print_width(nb, len, 0);
		return (1);
	}
	return (0);
}

int		print_int(va_list ap, int nb, int prec, int *flags)
{
	int 		len;
	int 		ival;
	int 		ret;
	long int	lval;

	ival = va_arg(ap, int);
	len = int_len(ival);
	if (len > nb)
	{
		if ((flags[2] == 1 && ival >= 0) || (flags[4] == 1 && ival >= 0))
			ret = len + 1;
		else
			ret = len;
	}
	else
	{
	
			ret = nb;
	}
	if (first_case(nb, len, ival, flags) == 1)
		return (ret);
	if (second_case(nb, len, ival, flags) == 1)
		return (ret);
	if (third_case(nb, len, ival, flags) == 1)
		return (ret);
	if (fourth_case(nb, len, ival, flags) == 1)
		return (ret);
	return (0);
}
