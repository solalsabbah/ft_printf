/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:05:29 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:13 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char		*calc_bin(long int nbr, int p)
{
	int		q;
	int		r;
	int		i;
	char	*str;

	str = malloc(sizeof(str) * 32 + 1);
	q = 1;
	i = 0;
	while (q != 0)
	{
		q = nbr / 2;
		r = nbr % 2;
		str[i] = r + '0';
		nbr = q;
		i++;
	}
	if (p == 1)
		str[i] = '-';
	return (str);
}

int			print_bin(va_list ap, t_form *form)
{
	long int	nbr;
	int			p;
	int			len;
	char		*str;

	p = 0;
	form->width = form->width;
	nbr = va_arg(ap, long long);
	nbr = signed_cast(nbr, form->length);
	if (nbr < 0)
	{
		nbr = -nbr;
		p = 1;
	}
	str = calc_bin(nbr, p);
	len = ft_strlen(str);
	ft_putstr(ft_strrev(str));
	free(str);
	return (p + len);
}
