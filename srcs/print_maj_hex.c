/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:52:22 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/23 15:04:38 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>


int			maj_hex_one(const char *str, int len, int nb, int prec, int *flags)
{
	prec = 0;
	if (flags[1] == 1)
	{
		if (flags[0] == 1)
		{
			if (str[0] != '0')
			{
				ft_putstr("0X");
				nb = nb - 2;
			}
		}
		ft_putstr(str);
		print_width(nb, len, 0);
	}
	return (0);
}

int			maj_hex_two(const char *str, int len, int nb, int prec, int *flags)
{
	if (flags[0] == 1 && flags[1] != 1)
	{
		str[0] != '0' ? nb = nb - 2 : 0;
		flags[3] != 1 ? print_width(nb, len, 0) : 0;
		str[0] != '0' ? ft_putstr("0X") : 0;
		flags[3] == 1 ? print_width(nb, len, 1) : 0;
		prec == 0 ? 0 : ft_putstr(str);
	}

	if (flags[1] != 1 && flags[0] != 1)
	{
		prec == 0 && str[0] == '0' ? len = 0 : 0 ;
		flags[3] == 1 ?	print_width(nb, len, 1) : 0;
		flags[3] != 1 ? print_width(nb, len, 0) : 0;
		prec == 0 ? 0 : ft_putstr(str);
	}
	return (len);
}

int			print_maj_hex(va_list ap, t_form *form, int *flags)
{
	int					len;
	unsigned long long	ival;
	const char			*str;

	ival = va_arg(ap, unsigned long long);
	str = ft_convert_hex(ival, 1);
	if (flags[2] == 1 || flags[4] == 1)
		return (-1);
	flags[1] == 1 && flags[3] == 1 ? flags[3] = 0 : 0;
	len = ft_strlen(str);
	maj_hex_one(str, len, form->width, form->prec, flags);
	maj_hex_two(str, len, form->width, form->prec, flags);
	if (form->prec == 0 && str[0] == '0')
		len = 0;
	len < form->width ? len = form->width : 0;
	if (form->width == 0 && flags[0] == 1)
		len = len + 2;
	if (ival == 0 && flags[0] == 1)
		len = len - 2;
	return (len);
}
