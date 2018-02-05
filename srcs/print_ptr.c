/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:06:27 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:37:41 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		ptr_one(const char *str, int len, t_form *form)
{
	if (form->minus == 1)
	{
		ft_putstr("0x");
		print_prec(form->prec, len, 1);
		ft_putstr(str);
		print_width(form->width, 0, 0);
	}
	else if (form->minus != 1)
	{
		form->prec == 0 && str[0] == '0' ? len = 0 : 0;
		form->zero == 1 ? print_width(form->width, 0, 1) : 0;
		form->zero != 1 ? print_width(form->width, 0, 0) : 0;
		ft_putstr("0x");
		print_prec(form->prec, len, 1);
		str[0] == '0' && form->prec > -1 ? 0 : ft_putstr(str);
	}
	return (0);
}

int		print_ptr(va_list ap, t_form *form)
{
	void		*adr;
	char		*str;
	int			len;
	int			ret;

	adr = va_arg(ap, void*);
	str = ft_convert_hex((long int)adr, form);
	len = str[0] == '0' && form->prec != -1 ? 0 : ft_strlen(str);
	ret = len + 2;
	if (form->prec > ret)
		ret = form->prec + 2;
	if (form->width > ret)
		ret = form->width;
	form->width -= len > form->prec ? (len + 2) : (form->prec + 2);
	ptr_one(str, len, form);
	free(str);
	return (ret);
}
