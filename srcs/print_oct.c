/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:53:57 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/23 15:56:13 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int			print_second_case(long int ival, int len, t_form *form, int *flags)
{
	if (flags[1] != 1 && flags[0] != 1)
	{
		if (flags[3] == 1 && form->prec == -1)
			 print_width(form->width, len, 1);	
		else if (form->prec > form->width)
		{	
			print_width(form->width, form->prec, 0);	
			print_prec(form->prec, len, 1);
		}
		else if (flags[3] != 1)
		{	
			if (form->prec > len)
			{
				print_width(form->width, form->prec, 0);
				print_prec(form->prec, len, 1);
			}
			if (form->prec == -1)
				flags[3] == 1 ? print_width(form->width, len, 1) : print_width(form->width, len, 0);
			form->prec == 0 && ival != 0 ? print_width(form->width, len, 1) : 0;
			form->prec == 0 && ival == 0 ? print_width(form->width, 0, 0) : 0;
		}
		ival == 0 && form->prec == 0 ? 0 : ft_putnbr_uns(ival);
	}
	return (len);
}
int			print_first_case(long int ival, int len, t_form *form, int *flags)
{
	if (flags[0] == 1 && flags[1] != 1)
	{
		form->width--;
		flags[3] == 1 ? print_width(form->width, len, 1) : print_width(form->width, len, 0);
		ft_putchar('0');
		form->prec == 0 && ival == 0 ? 0 : ft_putnbr_uns(ival);
	}
	if (flags[1] == 1)
	{
		if (flags[0] == 1)
		{
			form->width--;
			ft_putchar('0');
		}
		print_prec(form->prec, len, 1);	
		ft_putnbr_uns(ival);
		form->prec > len ? print_width(form->width, form->length, 0) : print_width(form->width, len, 0);
	}
	return (len);
}

int			print_oct(va_list ap, t_form *form, int *flags)
{
	int 			len;
	unsigned long	ival;
	long long		val;

	ival = va_arg(ap, unsigned int);
	val = ft_convert_oct(ival);
	if (flags[2] == 1 || flags[4] == 1)
		return (-1);
	len = int_len(val);
	print_first_case(val, len, form, flags);
	print_second_case(val, len, form, flags);
	val == 0 && form->prec == 0 ? len = 0 : 0;
	if (form->prec > len)
		len = form->prec;
	if (flags[0] == 1 && val == 0)
		len = len + 1;
	if (form->width > len)
		return (form->width);
	return (len);
}
