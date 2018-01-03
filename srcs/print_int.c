/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:45:39 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/03 17:48:44 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int		first_case(t_form *form, int len, long long ival)
{
	if (form->zero == 1 && form->plus != 1 && form->minus != 1 && form->space != 1)
	{
		ival < 0 ? ft_putsign(ival) : 0;
		form->width -= ival < 0 && form->prec != -1? 1 : 0;
		form->prec > -1 || (form->hash == 1 && form->prec > -1) ? print_width(form->width, 0, 0) : print_width(form->width, 0, 1);
		form->prec += ival < 0 ? 1 : 0;
		print_prec(form->prec, len, 1);
		form->prec == 0 && ival == 0 ? 0 : ft_putnbr(abs_val(ival));
		return (1);
	}
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
	if ((form->minus == 1 && form->plus != 1 && form->space != 1))
	{
		ival < 0 ? ft_putsign(ival) : 0;
		ival < 0 ? print_prec(++form->prec, len, 1) : print_prec(form->prec, len, 1);
		form->prec == 0 && ival == 0 ? 0 : ft_putnbr(abs_val(ival));
		print_width(form->width, 0, 0);
		return (1);
	}
	return (0);
}

int		second_case(t_form *form, int len, long long ival)
{
	if (form->plus == 1 && form->zero == 1 && form->minus != 1)
	{
		ival >= 0 ? --form->width : 0;
		form->prec > -1 ? print_width(form->width, 0, 0) : 0;
		ft_putsign(ival);
		form->prec == -1 ? print_width(form->width, 0, 1) : 0;
		ival < 0 ? print_prec(++form->prec, len, 1) : print_prec(form->prec, len, 1);
		form->prec == 0 && ival == 0 ? 0 : ft_putnbr(abs_val(ival));
		return (1);
	}
	if (form->zero == 1 && form->space == 1 && form->plus != 1 && form->minus != 1)
	{
		ival >= 0 || (form->width > 1 && ival < 0 && form->prec != -1)? ft_putchar(' ') : 0;
		ival < 0 && form->width > 1 ? form->width-- : 0;
		if (form->prec == -1 && ival < 0)
			form->width = form->width + 2;
		form->prec >= 0 ? print_width(--form->width, 0, 0) : 0;
		ival < 0 ? ft_putsign(ival) : 0;
	  	form->prec < 0 ? print_width(--form->width, 0, 1) : 0;
		ival <= 0 ? print_prec(form->prec + 1, len, 1) : print_prec(form->prec, len, 1);
		ival == 0 && form->prec == 0 ? 0 : ft_putnbr(abs_val(ival));
		return (1);
	}
	if (form->space == 1 && form->zero == 0 && form->plus == 0 && form->minus == 0)
	{
		ival >= 0 || (form->width > 1 && ival < 0 && form->prec != -1)? ft_putchar(' ') : 0;
		ival < 0 && form->width > 1 ? form->width-- : 0;
		if (form->prec == -1 && ival < 0)
			form->width = form->width + 2;
		print_width(--form->width, 0, 0);
		ival < 0 ? ft_putsign(ival) : 0;
		ival <= 0 ? print_prec(form->prec + 1, len, 1) : print_prec(form->prec, len, 1);
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
		ival <= 0 ? print_prec(form->prec + 1, len, 1) : print_prec(form->prec, len, 1);
		(ival == 0 && form->prec == -1) || ival != 0 ? ft_putnbr(abs_val(ival)) : 0;
		print_width(--form->width, 0, 0);
			
		return (1);
	}
	return (0);
}

int				fourth_case(t_form *form, int len, long long ival)
{
	if (form->minus != 1 && form->plus != 1 && form->zero != 1 && form->space != 1)
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

int				print_int(va_list ap, t_form *form)
{
	int				len;
	int				ret;
	long long		ival;
	
	form->field == 'D' ? form->length = L : 0;
	ival = va_arg(ap, long long);
	ival = signed_cast(ival, form->length);
	len = int_len(ival);
	ret = form->prec > len ? form->prec : len;
	ret = form->prec <= 0 && ival == 0 && !form->plus ? 0 : ret;
	ret += form->prec >= len && ival < 0 ? 1 : 0;
	ret += (form->plus == 1 && ival >= 0) || form->space == 1 ? 1 : 0;
	ret -= form->space == 1 && (form->prec == 0 || ival < 0) ? 1 : 0;
	ret = form->width > ret ? form->width : ret;
	ret += form->space == 1 && ival == 0 && form->prec == 0 ? 1 : 0;
	ret += !form->space && !form->zero && !form->plus && ival == 0 && form->prec == -1 ? 1 : 0;
	form->prec == 0 && ival == 0 && form->width != 0 ? ret = form->width : 0;
	form->width -= form->prec > len ? form->prec : len;
	form->width += ival == 0 && form->prec == 0 ? 1 : 0;
	if (first_case(form, len, ival) == 1)
		return (ret);
	if (second_case(form, len, ival) == 1)
		return (ret);
	if (third_case(form, len, ival) == 1)
		return (ret);
	if (fourth_case(form, len, ival) == 1)
		return (ret);
	return (0);
}
