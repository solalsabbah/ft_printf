/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:53:57 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:36:24 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int			print_second_case(char *str, int len, t_form *form)
{
	if (form->minus != 1 && form->hash != 1)
	{
		form->zero == 1 ? print_width(form->width, 0, 1) :
			print_width(form->width, 0, 0);
		print_prec(form->prec, len, 1);
		str[0] == '0' && form->prec == 0 ? 0 : ft_putstr(str);
	}
	return (len);
}

int			print_first_case(char *str, int len, t_form *form)
{
	if (form->hash == 1 && form->minus != 1)
	{
		str[0] == '0' ? 0 : form->width--;
		form->zero == 1 ? print_width(form->width, 0, 1) :
			print_width(form->width, 0, 0);
		form->prec > len || str[0] == '0' ? 0 : ft_putchar('0');
		print_prec(form->prec, len, 1);
		ft_putstr(str);
	}
	if (form->minus == 1)
	{
		if (form->hash == 1)
		{
			form->prec > len ? 0 : form->width--;
			str[0] == '0' && form->prec == 0 ? form->width++ : 0;
			str[0] == '0' || form->prec > len ? 0 : ft_putchar('0');
		}
		print_prec(form->prec, len, 1);
		ft_putstr(str);
		print_width(form->width, 0, 0);
	}
	return (len);
}

int			print_oct(va_list ap, t_form *form)
{
	int						len;
	int						ret;
	char					*str;
	unsigned long long		ival;

	ival = va_arg(ap, unsigned long long);
	if (form->field == 'O')
		form->length = L;
	ival = unsigned_cast(ival, form->length);
	str = ft_convert_oct(ival);
	len = ft_strlen(str);
	ret = len;
	if (form->space == 1)
		form->space = 0;
	str[0] == '0' && form->prec == 0 ? ret = 0 : 0;
	ret = form->prec > ret ? form->prec : ret;
	ret += form->hash == 1 && str[0] != '0' ? 1 : 0;
	ret += form->hash == 1 && str[0] == '0' && form->prec == 0 ? 1 : 0;
	ret = form->width > ret ? form->width : ret;
	form->width -= form->prec > len ? form->prec : len;
	str[0] == '0' && form->prec == 0 ? form->width++ : 0;
	print_first_case(str, len, form);
	print_second_case(str, len, form);
	free((char*)str);
	return (ret);
}
