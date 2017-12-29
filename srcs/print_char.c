/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 12:16:58 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/28 18:21:46 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			print_wchar(wchar_t wc, t_form *form, int *flags)
{
	char	*str;

	if (wc == 0)
	{
		str = ft_strnew(1);
		str[0] = -1;
	}
	else
	{
		if (!(str = ft_getwchar(wc)))
			return (NULL);
	}
	return (wc);
}

int			print_char(va_list ap, t_form *form, int *flags)
{
	char		cval;
	wchar_t		wc;
	cval = va_arg(ap, int);
	if (form->field == 'C' || form->length == 'L')
	{
		wc = va_arg(ap, wchar_t);
		print_wchar(wc, form, flags);
		return (1);	
	}
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
