/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:00:37 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/13 17:16:57 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>

int		ft_width(int ival,int nb)
{
	int	sp;

	sp = ft_strlen(ft_itoa(nb)) - ft_strlen(ft_itoa(ival));
	printf("sp :%d\n", sp);
	return (0);
}
