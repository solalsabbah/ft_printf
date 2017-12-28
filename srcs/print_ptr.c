/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:06:27 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/28 17:48:57 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int		ptr_one(const char *str, int len, t_form *form, int *flags)
{
	if (flags[1] == 1)
	{
		ft_putstr("0x");
		print_prec(form->prec, len, 1);
		ft_putstr(str);
		print_width(form->width, 0, 0);
	}
	else if (flags[1] != 1)
	{
		form->prec == 0 && str[0] == '0' ? len = 0 : 0;
		flags[3] == 1 ? print_width(form->width, 0, 1) : 0;
		flags[3] != 1 ? print_width(form->width, 0, 0) : 0;
		ft_putstr("0x");
		print_prec(form->prec, len, 1);
		str[0] == '0' && form->prec > -1 ? 0 : ft_putstr(str);
	}
	return (0);
}

int		print_ptr(va_list ap, t_form *form, int *flags)
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
	ptr_one(str, len, form, flags);
	return (ret);
}
