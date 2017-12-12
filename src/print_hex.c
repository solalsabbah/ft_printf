/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:52:22 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/12 15:38:18 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>

int			print_flags_hex(const char *str, int len, int nb, int *flags)
{
	if (flags[0] == 1 && flags[1] != 1)
	{
		nb = nb - 2;
		if (flags[3] == 1)
			print_width(nb, len, 1);
		else
			print_width(nb, len, 0);
		ft_putstr("0x");
		ft_putstr(str);
	}
	if (flags[1] == 1)
	{
		if (flags[0] == 1)
		{
			nb = nb - 2;
			ft_putstr("0x");
		}
		ft_putstr(str);
		print_width(nb, len, 0);
	}
	else if (flags[1] != 1 && flags[0] != 1)
	{
		if (flags[3] == 1)
			print_width(nb, len, 1);
		ft_putstr(str);
	}
	return (len);
}

int			print_hex(va_list ap, int nb, int *flags)
{
	int			len;
	int			ival;
	const char	*str;

	ival = va_arg(ap, int);
	str = ft_convert_hex(ival);
	if (flags[2] == 1 || flags[4] == 1 || (flags[1] == 1 && flags[3] == 1))
		return (-1);
	if (ival < 0)
		str = ft_convert_long_hex(negtounsigned(ival));
	len = ft_strlen(str);
	print_flags_hex(str, len, nb, flags);
	return (len);
}
