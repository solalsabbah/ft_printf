/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:53:57 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/24 18:46:51 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int			print_second_case(long long ival, int len, t_form *form, int *flags)
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
int			print_first_case(long long ival, int len, t_form *form, int *flags)
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
		form->prec > len ? print_width(form->width, form->prec, 0) : print_width(form->width, len, 0);
	}
	return (len);
}

int			print_oct(va_list ap, t_form *form, int *flags)
{
	int 				len;
	int					ret;
	unsigned long long	ival;

	ival = va_arg(ap, unsigned long long);
	ival = ft_convert_oct(ival);
	ival = unsigned_cast(ival, form->length);
	len = int_len(ival);
	ret = len;
	if (flags[2] == 1 || flags[4] == 1)
		return (-1);
	ival == 0 && form->prec == 0 ? ret = 0 : 0;
	if (form->prec > ret)
		ret = form->prec;
	if (flags[0] == 1 && ival == 0)
		ret = ret + 1;
	if (form->width > ret)
		ret = form->width;
	print_first_case(ival, len, form, flags);
	print_second_case(ival, len, form, flags);
	return (ret);
}
