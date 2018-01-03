/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:45:39 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/03 18:59:10 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int				find_ret(long long ival, t_form *form, int len)
{
	int ret;

	ret = form->prec > len ? form->prec : len;
	ret = form->prec <= 0 && ival == 0 && !form->plus ? 0 : ret;
	ret += form->prec >= len && ival < 0 ? 1 : 0;
	ret += (form->plus == 1 && ival >= 0) || form->space == 1 ? 1 : 0;
	ret -= form->space == 1 && (form->prec == 0 || ival < 0) ? 1 : 0;
	ret = form->width > ret ? form->width : ret;
	ret += form->space == 1 && ival == 0 && form->prec == 0 ? 1 : 0;
	ret += !form->space && !form->zero && !form->plus &&
		ival == 0 && form->prec == -1 ? 1 : 0;
	return (ret);
}

int				print_int(va_list ap, t_form *form)
{
	int				len;
	int				ret;
	long long		ival;

	form->field == 'D' ? form->length = L : 0;
	ival = va_arg(ap, long long);
	ival = signed_cast(ival, form->length);
	len = int_len(ival);
	ret = find_ret(ival, form, len);
	form->prec == 0 && ival == 0 && form->width != 0 ? ret = form->width : 0;
	form->width -= form->prec > len ? form->prec : len;
	form->width += ival == 0 && form->prec == 0 ? 1 : 0;
	if (first_case(form, len, ival) == 1)
		return (ret);
	if (second_case(form, len, ival) == 1)
		return (ret);
	if (third_case(form, len, ival) == 1)
		return (ret);
	if (fourth_case(form, len, ival) == 1)
		return (ret);
	if (fifth_case(form, len, ival) == 1)
		return (ret);
	return (0);
}
