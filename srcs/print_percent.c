/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:06:25 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:37:51 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			print_percent(va_list ap, t_form *form)
{
	int ret;

	ap = 0;
	ret = form->width > 1 ? form->width : 1;
	if (form->minus == 1)
	{
		ft_putchar('%');
		print_width(form->width, 1, 0);
	}
	else
	{
		form->zero == 1 ? print_width(form->width, 1, 1) :
			print_width(form->width, 1, 0);
		ft_putchar('%');
	}
	return (ret);
}
