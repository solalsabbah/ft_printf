/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:48:21 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:07 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		first_case(t_form *form, int len, long long ival)
{
	if (form->zero && !form->plus && !form->minus && !form->space)
	{
		ival < 0 ? ft_putsign(ival) : 0;
		form->width -= ival < 0 && form->prec != -1 ? 1 : 0;
		form->prec > -1 || (form->hash == 1 && form->prec > -1) ?
			print_width(form->width, 0, 0) : print_width(form->width, 0, 1);
		form->prec += ival < 0 ? 1 : 0;
		print_prec(form->prec, len, 1);
		form->prec == 0 && ival == 0 ? 0 : ft_putnbr(abs_val(ival));
		return (1);
	}
	if (form->plus == 1 && form->zero == 1 && form->minus != 1)
	{
		ival >= 0 ? --form->width : 0;
		form->prec > -1 ? print_width(form->width, 0, 0) : 0;
		ft_putsign(ival);
		form->prec == -1 ? print_width(form->width, 0, 1) : 0;
		ival < 0 ? print_prec(++form->prec, len, 1) :
			print_prec(form->prec, len, 1);
		form->prec == 0 && ival == 0 ? 0 : ft_putnbr(abs_val(ival));
		return (1);
	}
	return (0);
}

int		second_case(t_form *form, int len, long long ival)
{
	if (form->plus == 1 && form->minus != 1 && form->zero != 1)
	{
		form->prec += ival < 0 ? 1 : 0;
		form->width -= ival >= 0 ? 1 : 0;
		print_width(form->width, 0, 0);
		ft_putsign(ival);
		print_prec(form->prec, len, 1);
		ft_putnbr(abs_val(ival));
		return (1);
	}
	if (form->space && !form->zero && !form->plus && !form->minus)
	{
		ival >= 0 || (form->width > 1 && ival < 0 && form->prec != -1) ?
			ft_putchar(' ') : 0;
		ival < 0 && form->width > 1 ? form->width-- : 0;
		if (form->prec == -1 && ival < 0)
			form->width = form->width + 2;
		print_width(--form->width, 0, 0);
		ival < 0 ? ft_putsign(ival) : 0;
		ival <= 0 ? print_prec(form->prec + 1, len, 1) :
			print_prec(form->prec, len, 1);
		ival == 0 && form->prec == 0 ? 0 : ft_putnbr(abs_val(ival));
		return (1);
	}
	return (0);
}

int		third_case(t_form *form, int len, long long ival)
{
	if (form->plus == 1 && form->minus == 1)
	{
		ft_putsign(ival);
		ival < 0 ? form->prec++ : 0;
		ival < 0 ? form->width++ : 0;
		print_prec(form->prec, len, 1);
		form->prec == 0 && ival == 0 ? 0 : ft_putnbr(abs_val(ival));
		len < form->prec ? len = form->prec : 0;
		print_width(--form->width, 0, 0);
		return (1);
	}
	if (form->minus == 1 && form->space == 1 && form->zero != 1)
	{
		ival >= 0 ? ft_putchar(' ') : 0;
		ival < 0 ? ft_putsign(ival) : 0;
		ival <= 0 ? print_prec(form->prec + 1, len, 1) :
			print_prec(form->prec, len, 1);
		(ival == 0 && form->prec == -1) || ival != 0 ?
			ft_putnbr(abs_val(ival)) : 0;
		print_width(--form->width, 0, 0);
		return (1);
	}
	return (0);
}

int		fourth_case(t_form *form, int len, long long ival)
{
	if ((form->minus == 1 && form->plus != 1 && form->space != 1))
	{
		ival < 0 ? ft_putsign(ival) : 0;
		ival < 0 ? print_prec(++form->prec, len, 1) :
			print_prec(form->prec, len, 1);
		form->prec == 0 && ival == 0 ? 0 : ft_putnbr(abs_val(ival));
		print_width(form->width, 0, 0);
		return (1);
	}
	if (!form->minus && !form->plus && !form->zero && !form->space)
	{
		ival < 0 && form->prec > len ? print_width(--form->width, 0, 0) :
			print_width(form->width, 0, 0);
		if (ival < 0)
		{
			ft_putchar('-');
			len--;
		}
		print_prec(form->prec, len, 1);
		form->prec == 0 && ival == 0 ? 0 : ft_putnbr(abs_val(ival));
		return (1);
	}
	return (0);
}

int		fifth_case(t_form *form, int len, long long ival)
{
	if (form->zero && form->space && !form->plus && !form->minus)
	{
		ival >= 0 || (form->width > 1 && ival < 0 && form->prec != -1) ?
			ft_putchar(' ') : 0;
		ival < 0 && form->width > 1 ? form->width-- : 0;
		if (form->prec == -1 && ival < 0)
			form->width = form->width + 2;
		form->prec >= 0 ? print_width(--form->width, 0, 0) : 0;
		ival < 0 ? ft_putsign(ival) : 0;
		form->prec < 0 ? print_width(--form->width, 0, 1) : 0;
		ival <= 0 ? print_prec(form->prec + 1, len, 1) :
			print_prec(form->prec, len, 1);
		ival == 0 && form->prec == 0 ? 0 : ft_putnbr(abs_val(ival));
		return (1);
	}
	return (0);
}
