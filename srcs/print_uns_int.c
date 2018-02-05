/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:16:27 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:37:12 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_uns_int(va_list ap, t_form *form)
{
	int					len;
	int					ret;
	unsigned long long	ival;

	ival = va_arg(ap, unsigned long);
	if (form->field == 'U')
		form->length = 'L';
	ival = unsigned_cast(ival, form->length);
	len = uns_len(ival);
	ret = len;
	form->prec == 0 && ival == 0 ? ret = form->width : 0;
	ret = form->prec > ret ? form->prec : ret;
	ret = form->width > ret ? form->width : ret;
	if (first_uns_case(form, len, ival) == 1)
		return (ret);
	if (second_uns_case(form, len, ival) == 1)
		return (ret);
	if (third_uns_case(form, len, ival) == 1)
		return (ret);
	if (fourth_uns_case(form, len, ival) == 1)
		return (ret);
	if (fifth_uns_case(form, len, ival) == 1)
		return (ret);
	return (len);
}
