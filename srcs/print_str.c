/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 12:20:41 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:37:28 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int				ft_putstr_prec(char const *s, int prec)
{
	int i;

	i = 0;
	if (prec == -1)
	{
		ft_putstr(s);
		return (0);
	}
	while (s[i] != 0 && prec > 0)
	{
		ft_putchar(s[i]);
		prec--;
		i++;
	}
	return (0);
}

int				ascii_str(char **sval, int len, t_form *form)
{
	int			ret;

	if (form->prec < len && form->prec != -1)
		len = form->prec;
	ret = form->width > len ? form->width : len;
	if (form->minus != 1)
		form->zero == 1 ? print_width(form->width, len, 1) :
			print_width(form->width, len, 0);
	ft_putstr_prec(*sval, form->prec);
	if (form->minus == 1)
		print_width(form->width, len, 0);
	if (ft_strcmp(*sval, "(null)") == 0)
		ft_strdel(sval);
	return (ret);
}

int				print_str(va_list ap, t_form *form)
{
	wchar_t			*wc;
	char			*sval;
	int				len;

	if (form->field == 'S' || form->length == L)
	{
		wc = va_arg(ap, wchar_t *);
		return (print_wstr(wc, form));
	}
	sval = va_arg(ap, char *);
	if (sval == NULL)
	{
		sval = ft_strdup("(null)");
		len = 6;
	}
	else
		len = ft_strlen(sval);
	return (ascii_str(&sval, len, form));
}
