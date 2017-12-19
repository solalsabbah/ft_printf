/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:45:39 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/19 16:43:38 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

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

int		first_case(int nb, int prec, int len, int ival, int *flags)
{
	if (flags[3] == 1 && flags[2] != 1 && flags[1] != 1 && flags[4] != 1)
	{
		if (ival < 0)
			ft_putsign(ival);
		prec >= nb ?  print_prec(prec, len, 1) : 0;
	 	if (prec < nb)
		{	
			len > prec && prec != -1 ? print_width(nb, len, 0) : 0;
			len > prec && prec == -1 ? print_width(nb, len, 1) : 0;
			if (prec >= len)
			{
				ival < 0 ? print_width(nb, prec, 1) : print_width(nb, prec, 0);
				print_prec(prec, len, 1);
			}
		}
		ft_putnbr(abs_val(ival));
		return (1);
	}
	if (flags[2] == 1 && flags[1] != 1 && flags[3] != 1)
	{
		prec > len ? print_width(nb - 1, prec, 0) : 0;
		prec < len ? print_width(nb - 1, len, 0) : 0;
		ft_putsign(ival);
		print_prec(prec, len, 1);
		ft_putnbr(abs_val(ival));
		return (1);
	}
	if ((flags[1] == 1 && flags[2] != 1 && flags[3] != 1 && flags[4] != 1))
	{
		print_prec(prec, len, 1);
		if (prec > len)
			len = prec;
		ft_putnbr(ival);
		print_width(nb, len, 0);
		return (1);
	}
	return (0);
}

int		second_case(int nb, int prec, int len, int ival, int *flags)
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
		else
			prec > len ? print_width(nb, prec, 0) : print_width(nb, len, 0);
		print_prec(prec, len, 1);
		ft_putnbr(ival);
		return (1);
	}
	return (0);
}

int		third_case(int nb, int prec, int len, int ival, int *flags)
{
	if (flags[2] == 1 && flags[1] == 1)
	{
		ft_putsign(ival);
		print_prec(prec, len, 1);
		ft_putnbr(abs_val(ival));
		len < prec ? len = prec : 0;
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

int		fourth_case(int nb, int prec, int len, int ival, int *flags)
{
	if (flags[1] != 1 && flags[2] != 1 && flags[3] != 1 & flags[4] != 1)
	{
		if (prec > len)
			print_width(nb, prec, 0);
		else
			print_width(nb, len, 0);
		print_prec(prec, len, 1);
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
		ret = nb;
	if (prec > ret)
		ret = prec;
	
	if (first_case(nb, prec, len, ival, flags) == 1)
		return (ret);
	if (second_case(nb, prec, len, ival, flags) == 1)
		return (ret);
	if (third_case(nb, prec, len, ival, flags) == 1)
		return (ret);
	if (fourth_case(nb, prec, len, ival, flags) == 1)
		return (ret);
	return (0);
}
