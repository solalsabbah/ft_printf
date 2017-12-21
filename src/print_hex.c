/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:52:22 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/19 13:37:22 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int			print_flags_maj_hex(const char *str, int len, int nb, int prec, int *flags)
{
	if (flags[0] == 1 && flags[1] != 1)
	{
		if (str[0] != '0')
			nb = nb - 2;
		if (flags[3] != 1)
			print_width(nb, len, 0);
		if (str[0] != '0')
			ft_putstr("0X");
		if (flags[3] == 1)
			print_width(nb, len, 1);
		prec != 0 ? ft_putstr(str) : 0;
	}
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
	if (flags[1] != 1 && flags[0] != 1)
	{
		if (flags[3] == 1)
			print_width(nb, len, 1);
		if (flags[3] != 1)
			print_width(nb, len, 0);
		ft_putstr(str);
	}
	return (len);
}

int			print_flags_hex(const char *str, int len, int nb, int prec, int *flags)
{
	if (flags[0] == 1 && flags[1] != 1)
	{
		if (str[0] != '0')
			nb = nb - 2;
		if (flags[3] != 1)
			print_width(nb, len, 0);
		if (str[0] != '0')
			ft_putstr("0x");
		if (flags[3] == 1)
			print_width(nb, len, 1);
		prec == 0 ? 0 : ft_putstr(str);
	}
	if (flags[1] == 1)
	{
		if (flags[0] == 1)
		{
			if (str[0] != '0')
			{
				ft_putstr("0x");
				nb = nb - 2;
			}
		}
		ft_putstr(str);
		print_width(nb, len, 0);
	}
	if (flags[1] != 1 && flags[0] != 1)
	{
		prec == 0 && str[0] == '0' ? len = 0 : 0 ;
		if (flags[3] == 1)
			print_width(nb, len, 1);
		if (flags[3] != 1)
			print_width(nb, len, 0);
		prec == 0 ? 0 : ft_putstr(str);
	}
	return (len);
}

int			print_maj_hex(va_list ap, int nb, int prec, int *flags)
{
	int				len;
	unsigned int	ival;
	const char		*str;

	ival = va_arg(ap, unsigned int);
	str = ft_convert_hex(ival, 1);
	if (flags[2] == 1 || flags[4] == 1 || (flags[1] == 1 && flags[3] == 1))
		return (-1);
	len = ft_strlen(str);
	print_flags_maj_hex(str, len, nb, prec, flags);
	if (prec == 0 && str[0] == 0)
		return (nb);
	if (len < nb)
		len = nb;
	if (nb == 0 && flags[0] == 1)
		len = len + 2;
	return (len);
}

int			print_hex(va_list ap, int nb, int prec, int *flags)
{
	int					len;
	unsigned int		ival;
	const char			*str;

	ival = va_arg(ap, unsigned int);
	str = ft_convert_hex(ival, 0);
	if (flags[2] == 1 || flags[4] == 1)
		return (-1);
	if (flags[1] == 1 && flags[3] == 1)
		flags[3] = 0;
	len = ft_strlen(str);
	print_flags_hex(str, len, nb, prec, flags);
	if (prec == 0 && str[0] == '0')
		len = 0;
	if (len < nb)
		len = nb;
	if (nb == 0 && flags[0] == 1)
		len = len + 2;
	if (ival == 0 && flags[0] == 1)
		len = len - 2;
	return (len);
}
