/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:34:50 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:07 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include <stdarg.h>
#include <limits.h>
#include "../includes/ft_printf.h"
#include "../includes/ft_fct_tab.h"

int				ft_fmt(va_list ap, t_form *form)
{
	int		i;

	i = 0;
	while (g_fct_tab[i].c != '0')
	{
		if (g_fct_tab[i].c == form->field)
		{
			form->ret = g_fct_tab[i].f(ap, form);
			return (0);
		}
		i++;
	}
	return (0);
}

static int		isform(char c)
{
	if (ft_isdigit(c) || c == '.' || c == '+' || c == ' ' || c == '-' ||
			c == '#' || c == 'j' || c == 'h' || c == 'l' || c == 'z')
		return (1);
	return (0);
}

int				parser(char **str, t_form *form, va_list ap)
{
	init_format(form);
	while (isform(**str))
	{
		flags(str, form);
		width(str, form);
		precision(str, form);
		length(str, form);
	}
	field(str, form);
	if (!form->field)
		return (0);
	ft_fmt(ap, form);
	return (0);
}

int				ft_printf(char *fmt, ...)
{
	int			i;
	int			ret;
	t_form		form;
	va_list		ap;

	i = 0;
	ret = 0;
	va_start(ap, fmt);
	while (*fmt != 0)
	{
		*fmt != '%' ? ft_putchar(*fmt) : 0;
		if (*fmt == '%')
		{
			fmt++;
			parser(&fmt, &form, ap);
			ret += form.ret;
		}
		else
		{
			ret++;
			fmt++;
		}
	}
	va_end(ap);
	return (ret);
}
