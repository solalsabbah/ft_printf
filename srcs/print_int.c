/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:45:39 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/26 18:48:05 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int		first_case(t_form *form, int len, long long ival, int *flags)
{
	if (flags[3] == 1 && flags[2] != 1 && flags[1] != 1 && flags[4] != 1)
	{
		form->prec > len ? print_width(form->width, 0, 1) : print_width(form->width, 0, 0);
		ival < 0 ? ft_putsign(ival) : 0;
		form->prec >= form->width ?  print_prec(form->prec, len, 1) : 0;	
		if (form->prec < form->width)
		{
			len > form->prec && form->prec != -1 ? print_width(form->width, 0, 0) : 0;
			len > form->prec && form->prec == -1 ? print_width(form->width, 0, 1) : 0;
			if (form->prec >= len)
			{
				ival < 0 ? print_width(form->width, 0, 1) : print_width(form->width, 0, 0);
				print_prec(form->prec, len, 1);
			}
		}
		ft_putnbr(abs_val(ival));
		return (1);
	}
	if (flags[2] == 1 && flags[1] != 1 && flags[3] != 1)
	{
		form->prec > len ? print_width(form->width - 1, 0, 0) : 0;
		form->prec < len ? print_width(form->width - 1, 0, 0) : 0;
		ft_putsign(ival);
		print_prec(form->prec, len, 1);
		ft_putnbr(abs_val(ival));
		return (1);
	}
	if ((flags[1] == 1 && flags[2] != 1 && flags[3] != 1 && flags[4] != 1))
	{
		print_prec(form->prec, len, 1);
		if (form->prec > len)
			len = form->prec;
		ft_putnbr(ival);
		print_width(form->width, 0, 0);
		return (1);
	}
	return (0);
}

int		second_case(t_form *form, int len, long long ival, int *flags)
{
	if (flags[2] == 1 && flags[3] == 1 && flags[1] != 1)
	{
		ft_putsign(ival);
		if (ival >= 0)
			form->width--;
		print_width(form->width, 0, 1);
		ft_putnbr(abs_val(ival));
		return (1);
	}
	if (flags[3] == 1 && flags[4] == 1 && flags[2] != 1 && flags[1] != 1)
	{
		ft_putchar(' ');
		print_width(form->width - 1, 0, 1);
		ft_putnbr(abs_val(ival));
		return (1);
	}
	if (flags[4] == 1 && flags[1] != 1 && flags[2] != 1 && flags[3] != 1)
	{
		if (ival >= 0 && form->width <= 0)
			ft_putchar(' ');
		else
			print_width(form->width, 0, 0);
		print_prec(form->prec, len, 1);
		form->prec == 0 && ival == 0 ? 0 : ft_putnbr(ival);
		return (1);
	}
	return (0);
}

int		third_case(t_form *form, int len, long long ival, int *flags)
{
	if (flags[2] == 1 && flags[1] == 1)
	{
		ft_putsign(ival);
		print_prec(form->prec, len, 1);
		ft_putnbr(abs_val(ival));
		len < form->prec ? len = form->prec : 0;
		print_width(form->width - 1, 0, 0);
		return (1);
	}
	if (flags[1] == 1 && flags[4] == 1 && flags[3] != 1)
	{
		if (ival < 0)
		{
			ft_putnbr(ival);
			print_width(form->width, 0, 0);
			return (1);
		}
		else
		{
			ft_putchar(' ');
			ft_putnbr(ival);
			form->width--;
			print_width(form->width, 0, 0);
			return (1);
		}
	}
	return (0);
}

int				fourth_case(t_form *form, int len, long long ival, int *flags)
{
	if (flags[1] != 1 && flags[2] != 1 && flags[3] != 1 && flags[4] != 1)
	{
		print_width(form->width, 0, 0);
		if (ival < 0)
		{
			ft_putchar('-');
			ival = -ival;
			len--;
		}
		print_prec(form->prec, len, 1);
		form->prec == 0 && ival == 0 ? 0 : ft_putnbr(ival);
		return (1);
	}
	if (flags[1] == 1 && flags[3] == 1)
	{
		ft_putnbr(ival);
		print_width(form->width, 0, 0);
		return (1);
	}
	return (0);
}

int				print_int(va_list ap, t_form *form, int *flags)
{
	int			len;
	int			ret;
	long long	ival;

	ival = va_arg(ap, long long);
	ival = signed_cast(ival, form->length);
	len = int_len(ival);
	
	ret = form->prec > len ? form->prec : len;
	ret += form->prec > len && ival < 0 ? 1 : 0;
	ret += (flags[2] == 1 && ival >= 0) || flags[4] == 1  ? 1 : 0;
	ret -= flags[4] == 1 && (form->prec == 0 || ival < 0) ? 1 : 0;
	ret = form->width > ret ? form->width : ret;
	form->prec == 0 && ival == 0 && form->width != 0 ? ret = form->width : 0;
	form->width = form->prec > len ? form->width - form->prec : form->width - len;
	form->width += ival == 0 && form->prec == 0 ? 1 : 0;
	if (first_case(form, len, ival, flags) == 1)
		return (ret);
	if (second_case(form, len, ival, flags) == 1)
		return (ret);
	if (third_case(form, len, ival, flags) == 1)
		return (ret);
	if (fourth_case(form, len, ival, flags) == 1)
		return (ret);
	return (0);
}
