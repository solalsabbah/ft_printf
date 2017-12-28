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
		wchar_t c;
		int		i;
		int		error;

		i = 0;
		c = 0;
		if ((0xD800 <= wc && wc <= 0xDFFF) || wc > 0x10FFFF || wc < 0x0)
			error = 1;
		else if (!wc)
			c = wc;
		else if (++i && wc <= 0x7F)
			c = wc;
		else if (i++ && wc <= 0x7FF)
			c = (0x80 + (wc & 0x3F)) * 0x100 + (wc >> 6 | 0xC0);
		else if (i++ && wc <= 0xFFFF)
			c = ((0x80 + (wc & 0x3F)) * 0x100 + (0x80 + (wc >> 6 & 0x3F))) *
				0x100 + (wc >> 12 | 0xE0);
		else if (i++ && wc <= 0x10FFFF)
			c = (((0x80 + (wc & 0x3F)) * 0x100 + (0x80 + (wc >> 6 & 0x3F))) *
					0x100 + (0x80 + (wc >> 12 & 0x3F))) * 0x100 + (wc >> 18 | 0xF0);
		ft_putchar(c);	
		return (c);
}

int			print_char(va_list ap, t_form *form, int *flags)
{
	char		cval;
	wchar_t		w;
	cval = va_arg(ap, int);
	if (form->field == 'C' || form->length == 'L')
	{
		w = va_arg(ap, wchar_t);
		print_wchar(w, form, flags);
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
