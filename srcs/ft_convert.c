/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:28:13 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:07 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char					convert(int i, int maj)
{
	int					a;

	a = 32;
	if (maj == 1)
		a = 0;
	if (i > 9)
		return (i + 55 + a);
	else
		return (i + 48);
	return (0);
}

char					*ft_convert_hex(unsigned long long nb, t_form *form)
{
	long long			res;
	int					maj;
	int					i;
	char				*str;

	i = 0;
	maj = 0;
	str = ft_strnew(22);
	if (form->field == 'X' || form->field == 'P')
		maj = 1;
	str[0] = 48;
	while (nb > 0)
	{
		res = nb % 16;
		str[i] = convert(res, maj);
		nb = nb / 16;
		i++;
	}
	ft_strrev(str);
	return (str);
}

char					*ft_convert_oct(unsigned long long nb)
{
	unsigned long long		res;
	char					*str;
	int						i;

	i = 0;
	res = nb;
	str = ft_strnew(22);
	str[0] = 48;
	while (nb > 0)
	{
		res = nb % 8;
		str[i] = res + 48;
		nb = nb / 8;
		i++;
	}
	ft_strrev(str);
	return (str);
}
