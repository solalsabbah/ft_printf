/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 15:04:31 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/28 16:08:13 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
