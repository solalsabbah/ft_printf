/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_maj_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 17:05:27 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/24 17:39:14 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int			maj_hex_one(const char *str, int len, t_form *form, int *flags)
{
	if (flags[1] == 1)
	{
		if (flags[0] == 1)
		{
			if (str[0] != '0')
			{
				ft_putstr("0X");
				form->width = form->width - 2;
			}
		}
		ft_putstr(str);
		print_width(form->width, len, 0);
	}
	return (0);
}

int			maj_hex_two(const char *str, int len, t_form *form, int *flags)
{
	if (flags[0] == 1 && flags[1] != 1)
	{
		str[0] != '0' ? form->width = form->width - 2 : 0;
		flags[3] != 1 ? print_width(form->width, len, 0) : 0;
		str[0] != '0' ? ft_putstr("0X") : 0;
		flags[3] == 1 ? print_width(form->width, len, 1) : 0;
		form->prec == 0 ? 0 : ft_putstr(str);
	}

	if (flags[1] != 1 && flags[0] != 1)
	{
		form->prec == 0 && str[0] == '0' ? len = 0 : 0 ;
		flags[3] == 1 ?	print_width(form->width, len, 1) : 0;
		flags[3] != 1 ? print_width(form->width, len, 0) : 0;
		form->prec == 0 ? 0 : ft_putstr(str);
	}
	return (len);
}

int			print_maj_hex(va_list ap, t_form *form, int *flags)
{
	int					len;
	unsigned long long	ival;
	const char			*str;
	int					ret;

	ival = va_arg(ap, unsigned long long);
	ival = unsigned_cast(ival, form->length);
	str = ft_convert_hex(ival, 1);
	if (flags[2] == 1 || flags[4] == 1)
		return (-1);
	flags[1] == 1 && flags[3] == 1 ? flags[3] = 0 : 0;
	len = ft_strlen(str);
	ret = len;
	if (form->prec == 0 && str[0] == '0')
		ret = 0;
	ret < form->width ? ret = form->width : 0;
	if (form->width == 0 && flags[0] == 1)
		ret = ret + 2;
	if (ival == 0 && flags[0] == 1)
		ret = ret - 2;
	maj_hex_one(str, len, form, flags);
	maj_hex_two(str, len, form, flags);
	return (ret);
}
