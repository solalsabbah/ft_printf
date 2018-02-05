/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:52:22 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:13 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int			ft_puthash(t_form *form)
{
	if (form->field == 'X')
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
	return (0);
}

int			hex_one(const char *str, int len, t_form *form)
{
	if (form->minus == 1)
	{
		if (form->hash == 1)
		{
			if (str[0] != '0')
				form->prec == -1 ? ft_puthash(form) : 0;
		}
		print_prec(form->prec, len, 1);
		ft_putstr(str);
		print_width(form->width, 0, 0);
	}
	return (0);
}

int			hex_two(const char *str, int len, t_form *form)
{
	if (form->hash == 1 && form->minus != 1)
	{
		form->zero != 1 ? print_width(form->width, 0, 0) : 0;
		str[0] != '0' ? ft_puthash(form) : 0;
		form->zero == 1 ? print_width(form->width, 0, 1) : 0;
		print_prec(form->prec, len, 1);
		form->prec == 0 ? 0 : ft_putstr(str);
	}
	if (form->minus != 1 && form->hash != 1)
	{
		form->prec == 0 && str[0] == '0' ? len = 0 : 0;
		form->zero == 1 ? print_width(form->width, 0, 1) : 0;
		form->zero != 1 ? print_width(form->width, 0, 0) : 0;
		print_prec(form->prec, len, 1);
		form->prec == 0 ? 0 : ft_putstr(str);
	}
	return (len);
}

int			print_hex(va_list ap, t_form *form)
{
	int					len;
	int					ret;
	unsigned long long	ival;
	const char			*str;

	ival = va_arg(ap, unsigned long long);
	ival = unsigned_cast(ival, form->length);
	str = ft_convert_hex(ival, form);
	if (form->plus == 1 || form->space == 1)
		form->space = 0;
	form->minus == 1 && form->zero == 1 ? form->zero = 0 : 0;
	len = ft_strlen(str);
	ret = len;
	if (form->prec == 0 && str[0] == '0')
		ret = 0;
	ret = form->prec > ret ? form->prec : ret;
	ret += form->hash == 1 && ival != 0 ? 2 : 0;
	form->width -= form->width > ret ? ret : form->width;
	ret += form->width > 0 ? form->width : 0;
	hex_one(str, len, form);
	hex_two(str, len, form);
	free((char*)str);
	return (ret);
}
