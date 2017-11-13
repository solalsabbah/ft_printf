/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:54:43 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/13 14:25:33 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>

int		ft_convert_hex(int n)
{
	int	base;
	int	rem;

	base = 16;
	while (base < n / 16)
		base = base * 16;
	while (n > 15) 
	{
		rem = n / base;
		n = n - rem * base;
		base = base / 16;
		if (rem > 9) 
			ft_putchar(55 + rem);
		else
			ft_putnbr(rem);
	}
	if (n > 9)
		ft_putchar(55 + n);
	else
		ft_putnbr(n);
	return (0);	
}

int		ft_convert_oct(int n)
{
	int o;
	int nb;
	int j;

	o = n;

	nb = 0;
	j = 0;
	while (j > 0)
	{
		nb = nb * 10 + (j % 8);
		j = j / 8;
	}
	while (nb > 0)
	{
		o = o * 10 + (nb % 10);
		nb = nb / 10;
	}
	return (o);
}
