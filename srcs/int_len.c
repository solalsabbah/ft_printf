/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 15:04:31 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:13 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		uns_len(unsigned long long nb)
{
	int len;

	len = 1;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int		int_len(long long nb)
{
	int len;

	len = 1;
	while (!(nb > -10 && nb < 10))
	{
		nb /= 10;
		len++;
	}
	nb < 0 ? len++ : 0;
	return (len);
}
