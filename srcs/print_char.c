/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 12:16:58 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/26 15:23:45 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			print_char(va_list ap, t_form *form, int *flags)
{
	char	cval;

	cval = va_arg(ap, int);
	if (flags[1] == 1)
	{
		ft_putchar(cval);
		print_width(form->width, 1, 0);
	}
	else
	{
		flags[3] == 1 ? print_width(form->width, 1, 1) : print_width(form->width, 1, 0);
		ft_putchar(cval);
	}
	if (form->width > 1)
		return (form->width);
	return (1);
}
