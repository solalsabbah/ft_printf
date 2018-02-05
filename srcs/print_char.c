/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 12:16:58 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:13 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <locale.h>
#include "../includes/ft_printf.h"

int			print_wchar(wchar_t wc, t_form *form)
{
	char	*str;
	int		ret;

	form->width = form->width;
	if (wc == 0)
	{
		str = ft_strnew(1);
		str[0] = 0;
		return (1);
	}
	else
	{
		if (!(str = ft_getwchar((wchar_t)wc)))
			return (0);
	}
	ret = ft_strlen(str);
	write(1, str, ret);
	return (ret);
}

int			print_char(va_list ap, t_form *form)
{
	char		cval;
	wchar_t		wc;
	int			ret;

	if (form->field == 'C' || form->length == L)
	{
		wc = va_arg(ap, wchar_t);
		ret = print_wchar(wc, form);
		return (ret);
	}
	cval = va_arg(ap, int);
	if (form->minus == 1)
	{
		ft_putchar(cval);
		print_width(form->width, 1, 0);
	}
	else
	{
		form->zero == 1 ? print_width(form->width, 1, 1) :
			print_width(form->width, 1, 0);
		ft_putchar(cval);
	}
	ret = form->width > 1 ? form->width : 1;
	return (ret);
}
