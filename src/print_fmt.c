/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:27:37 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/13 14:06:02 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int				print_str(va_list ap, int nb, int *flags)
{
	int			len;
	const char	*sval;

	sval = va_arg(ap, char *);
	len = ft_strlen(sval);
	if (flags[1] != 1)
		print_width(nb, len, 0);
	ft_putstr(sval);
	if (flags[1] == 1)
		print_width(nb, len, 0);
	return (len);
}

int			print_char(va_list ap, int nb, int *flags)
{
	char	cval;

	cval = va_arg(ap, int);
	if (flags[1] == 1)
	{
		ft_putchar(cval);
		print_width(nb, 1, 0);
	}
	else
	{
		print_width(nb, 1, 0);
		ft_putchar(cval);
	}
	return (1);
}

int		print_uns_int(va_list ap, int nb, int *flags)
{
	int len;
	unsigned int ival;

	flags[0] = 1; // to change
	ival = va_arg(ap, unsigned int);
	len = int_len(ival);
	print_width(nb, len, 0); // to change
	ft_putnbr_uns(ival);
	return (len);
}
