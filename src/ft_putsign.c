/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:31:52 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/07 11:31:13 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/header.h"
#include <stdio.h>

int			ft_putsign(int	nb)
{
	if (nb <  0) 
		ft_putchar('-');
	else 
		ft_putchar('+');
	return (0);
}
