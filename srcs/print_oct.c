/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:53:57 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/28 18:49:08 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int			print_second_case(long long ival, int len, t_form *form, int *flags)
{
	if (flags[1] != 1 && flags[0] != 1)
	{
		flags[3] == 1 ? print_width(form->width, 0, 1) :
			print_width(form->width, 0, 0);
		print_prec(form->prec, len, 1);
		form->prec == 0 && ival != 0 ? print_width(form->width, 0, 1) : 0;
		form->prec == 0 && ival == 0 ? print_width(form->width, 0, 0) : 0;
		ival == 0 && form->prec == 0 ? 0 : ft_putnbr_uns(ival);
	}
	return (len);
}

int			print_first_case(long long ival, int len, t_form *form, int *flags)
{
	if (flags[0] == 1 && flags[1] != 1)
	{
		ival == 0 ? 0 : form->width--;
		flags[3] == 1 ? print_width(form->width, 0, 1) :
			print_width(form->width, 0, 0);
		form->prec > len || ival == 0 ? 0 : ft_putchar('0');
		print_prec(form->prec, len, 1);
		/*form->prec == 0 && ival == 0 ? 0 :*/ ft_putnbr_uns(ival);
	}
	if (flags[1] == 1)
	{
		if (flags[0] == 1)
		{
			form->prec > len ? 0 : form->width--;
			ival == 0 && form->prec == 0 ? form->width++ : 0;
			ival == 0 || form->prec > len ? 0 : ft_putchar('0');
		}
		print_prec(form->prec, len, 1);
		ft_putnbr_uns(ival);
		print_width(form->width, 0, 0);
	}
	return (len);
}

int			print_oct(va_list ap, t_form *form, int *flags)
{
	int					len;
	int					ret;
	unsigned long long	ival;

	ival = va_arg(ap, unsigned long long);
	ival = unsigned_cast(ival, form->length);
	ival = ft_convert_oct(ival);
	len = int_len(ival);
	ret = len;
	if (flags[4] == 1)
		return (-1);
	ival == 0 && form->prec == 0 ? ret = 0 : 0;
	ret = form->prec > ret ? form->prec : ret;
	ret += flags[0] == 1 && ival != 0 ? 1 : 0;
	ret += flags[0] == 1 && ival == 0 && form->prec == 0 ? 1 : 0;
	ret = form->width > ret ? form->width : ret;
	form->width -= form->prec > len ? form->prec : len;
	print_first_case(ival, len, form, flags);
	print_second_case(ival, len, form, flags);
	return (ret);
}
