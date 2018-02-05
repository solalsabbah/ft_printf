/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_uns_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:10:54 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:07 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		first_uns_case(t_form *form, int len, long long ival)
{
	if (form->plus == 1 && form->minus != 1 && form->zero != 1)
	{
		form->prec > len ? print_width(form->width, form->prec, 0) : 0;
		form->prec < len ? print_width(form->width, len, 0) : 0;
		print_prec(form->prec, len, 1);
		ft_putnbr_uns(ival);
		return (1);
	}
	if ((form->minus && !form->plus && !form->zero && !form->space))
	{
		print_prec(form->prec, len, 1);
		if (form->prec > len)
			len = form->prec;
		ft_putnbr_uns(ival);
		print_width(form->width, len, 0);
		return (1);
	}
	if (form->plus == 1 && form->zero == 1 && form->minus != 1)
	{
		print_width(form->width, len, 1);
		ft_putnbr_uns(ival);
		return (1);
	}
	return (0);
}

int		second_uns_case(t_form *form, int len, long long ival)
{
	if (form->zero && !form->plus && !form->minus && !form->space)
	{
		form->prec >= form->width ? print_prec(form->prec, len, 1) : 0;
		if (form->prec < form->width)
		{
			len > form->prec && form->prec != -1 ?
				print_width(form->width, len, 0) : 0;
			len > form->prec && form->prec == -1 ?
				print_width(form->width, len, 1) : 0;
			if (form->prec >= len)
			{
				ival < 0 ? print_width(form->width, len, 1) :
					print_width(form->width, form->prec, 0);
				print_prec(form->prec, len, 1);
			}
		}
		ft_putnbr_uns(ival);
		return (1);
	}
	return (0);
}

int		third_uns_case(t_form *form, int len, long long ival)
{
	if (form->plus == 1 && form->minus == 1)
	{
		print_prec(form->prec, len, 1);
		ft_putnbr_uns(ival);
		len < form->prec ? len = form->prec : 0;
		print_width(form->width, len, 0);
		return (1);
	}
	if (form->zero && form->space && !form->plus && !form->minus)
	{
		ft_putchar(' ');
		print_width(form->width - 1, len, 1);
		ft_putnbr_uns(ival);
		return (1);
	}
	if (form->space && !form->minus && !form->plus && !form->zero)
	{
		form->prec > len ? print_width(form->width, form->prec, 0) :
			print_width(form->width, len, 0);
		print_prec(form->prec, len, 1);
		ft_putnbr_uns(ival);
		return (1);
	}
	return (0);
}

int		fourth_uns_case(t_form *form, int len, long long ival)
{
	if (!form->minus && !form->plus && !form->zero && !form->space)
	{
		if (form->prec > len)
		{
			if (ival < 0)
			{
				ft_putchar('-');
				ival = -ival;
				len--;
			}
			print_width(form->width, form->prec, 0);
		}
		else
			form->prec == 0 && ival == 0 ? print_width(form->width, 0, 0) :
				print_width(form->width, len, 0);
		print_prec(form->prec, len, 1);
		form->prec == 0 && ival == 0 ? 0 : ft_putnbr_uns(ival);
		return (1);
	}
	return (0);
}

int		fifth_uns_case(t_form *form, int len, long long ival)
{
	if (form->minus == 1 && form->space == 1 && form->zero != 1)
	{
		if (ival < 0)
		{
			ft_putnbr_uns(ival);
			print_width(form->width, len, 0);
			return (1);
		}
		else
		{
			ft_putchar(' ');
			ft_putnbr_uns(ival);
			form->width--;
			print_width(form->width, len, 0);
			return (1);
		}
	}
	if (form->minus == 1 && form->zero == 1)
	{
		ft_putnbr_uns(ival);
		print_width(form->width, len, 0);
		return (1);
	}
	return (0);
}
