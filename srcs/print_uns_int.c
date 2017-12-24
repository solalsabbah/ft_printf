/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 19:25:40 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/24 19:37:22 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "../includes/libft.h"
#include <stdio.h>

int		first_uns_case(t_form *form, int len, unsigned long long ival, int *flags)
{
	if (flags[3] == 1 && flags[2] != 1 && flags[1] != 1 && flags[4] != 1)
	{
		form->prec >= form->width ?  print_prec(form->prec, len, 1) : 0;	
		if (form->prec < form->width)
		{
			len > form->prec && form->prec != -1 ? print_width(form->width, len, 0) : 0;
			len > form->prec && form->prec == -1 ? print_width(form->width, len, 1) : 0;
			if (form->prec >= len)
			{
				print_width(form->width, form->prec, 0);
				print_prec(form->prec, len, 1);
			}
		}
		ft_putnbr_uns(ival);
		return (1);
	}
	if (flags[2] == 1 && flags[1] != 1 && flags[3] != 1)
	{
		form->prec > len ? print_width(form->width - 1, form->prec, 0) : 0;
		form->prec < len ? print_width(form->width - 1, len, 0) : 0;
		ft_putsign(ival);
		print_prec(form->prec, len, 1);
		ft_putnbr_uns(abs_val(ival));
		return (1);
	}
	if ((flags[1] == 1 && flags[2] != 1 && flags[3] != 1 && flags[4] != 1))
	{
		print_prec(form->prec, len, 1);
		if (form->prec > len)
			len = form->prec;
		ft_putnbr_uns(ival);
		print_width(form->width, len, 0);
		return (1);
	}
	return (0);
}

int		second_uns_case(t_form *form, int len, unsigned long long ival, int *flags)
{
	if (flags[2] == 1 && flags[3] == 1 && flags[1] != 1)
	{
		ft_putchar('+');
		form->width--;
		print_width(form->width, len, 1);
		ft_putnbr_uns(abs_val(ival));
		return (1);
	}
	if (flags[3] == 1 && flags[4] == 1 && flags[2] != 1 && flags[1] != 1)
	{
		ft_putchar(' ');
		print_width(form->width - 1, len, 1);
		ft_putnbr_uns(abs_val(ival));
		return (1);
	}
	if (flags[4] == 1 && flags[1] != 1 && flags[2] != 1 && flags[3] != 1)
	{
		if (ival > 0 && form->width == 0)
			ft_putchar(' ');
		else
			form->prec > len ? print_width(form->width, form->prec, 0) : print_width(form->width, len, 0);
		print_prec(form->prec, len, 1);
		ft_putnbr_uns(ival);
		return (1);
	}
	return (0);
}

int		third_uns_case(t_form *form, int len, unsigned long long ival, int *flags)
{
	if (flags[2] == 1 && flags[1] == 1)
	{
		ft_putchar('+');
		print_prec(form->prec, len, 1);
		ft_putnbr_uns(ival);
		len < form->prec ? len = form->prec : 0;
		print_width(form->width - 1, len, 0);
		return (1);
	}
	if (flags[1] == 1 && flags[4] == 1 && flags[3] != 1)
	{
			ft_putchar(' ');
			ft_putnbr_uns(ival);
			form->width--;
			print_width(form->width, len, 0);
			return (1);
	}
	return (0);
}

int				fourth_uns_case(t_form *form, int len, unsigned long long ival, int *flags)
{
	if (flags[1] != 1 && flags[2] != 1 && flags[3] != 1 & flags[4] != 1)
	{
		if (form->prec > len)
			print_width(form->width, form->prec, 0);
		else
			form->prec == 0 && ival == 0 ? print_width(form->width, 0, 0) : print_width(form->width, len, 0);
		print_prec(form->prec, len, 1);
		form->prec == 0 && ival == 0 ? 0 : ft_putnbr_uns(ival);
		return (1);
	}
	if (flags[1] == 1 && flags[3] == 1)
	{
		ft_putnbr_uns(ival);
		print_width(form->width, len, 0);
		return (1);
	}
	return (0);
}

int				print_uns_int(va_list ap, t_form *form, int *flags)
{
	int					len;
	int					ret;
	unsigned long long	ival;

	ival = va_arg(ap, unsigned long long);
	ival = signed_cast(ival, form->length);
	len = int_len(ival);
	if (len > form->width)
		if ((flags[2] == 1 && ival >= 0) || (flags[4] == 1 && ival >= 0))
			ret = len + 1;
		else
			ret = len;
	else
		ret = form->width;
	form->prec == 0 && ival == 0 ? ret = form->width : 0;
	form->prec > ret ? ret = form->prec : 0;
	form->prec > len && ival < 0 ? ret++ : 0;
	if (first_uns_case(form, len, ival, flags) == 1)
		return (ret);
	if (second_uns_case(form, len, ival, flags) == 1)
		return (ret);
	if (third_uns_case(form, len, ival, flags) == 1)
		return (ret);
	if (fourth_uns_case(form, len, ival, flags) == 1)
		return (ret);
	return (0);
}*/
