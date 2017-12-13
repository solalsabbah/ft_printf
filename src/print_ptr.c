/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:06:27 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/13 17:16:33 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int		print_ptr(va_list ap, int nb, int *flags)
{
	void *adr;
	char *str;

	nb = 0;
	flags[0] = 1;
	adr = va_arg(ap, void*);
	str = ft_strjoin("0x", ft_convert_long_hex((long int)adr, 0));
	ft_putstr(str);
	return (14);
}
