/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:36:47 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/13 15:42:16 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "unistd.h"

void	ft_putnbr_uns(long int n)
{
	long int nb;
	int p;

	p = 0;
	nb = n;
	if (nb < 0 && p == 0)
	{	
		write(1, "-1", 2);
		p = 1;
	}
	if (nb > 9)
	{
		ft_putnbr_uns(nb / 10);
		ft_putnbr_uns(nb % 10);
	}
	else 
		ft_putchar(nb + '0');
}
