/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:05:29 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/13 14:05:32 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

char		*calc_bin(long int nbr, int p)
{
	int	q;
	int	r;
	int	i;
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

int		print_bin(va_list ap, int nb, int *flags)
{
	long int		nbr;
	int			p;
	int			len;
	char			*str;

	p = 0;
	nb = 0;
	nbr = va_arg(ap, long int);
	flags[0] = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		p = 1;
	}
	str = calc_bin(nbr, p);
	len = ft_strlen(str);
	ft_putstr(ft_strrev(str));
	return (p + len);
}