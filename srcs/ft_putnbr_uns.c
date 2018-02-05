/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:36:47 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:07 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "unistd.h"

void	ft_putnbr_uns(unsigned long long n)
{
	unsigned long long	nb;
	int					p;

	p = 0;
	nb = n;
	if (nb > 9)
	{
		ft_putnbr_uns(nb / 10);
		ft_putnbr_uns(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}
