/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 16:15:00 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:07 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_format(t_form *form)
{
	form->width = 0;
	form->prec = -1;
	form->length = -1;
	form->field = 0;
	form->minus = 0;
	form->plus = 0;
	form->space = 0;
	form->zero = 0;
	form->hash = 0;
	form->ret = 0;
}

int			flags(char **str, t_form *form)
{
	while (**str == '#' || **str == '-' || **str == '+'
			|| **str == '0' || **str == ' ')
	{
		**str == '#' ? form->hash = 1 : 0;
		**str == '+' ? form->plus = 1 : 0;
		**str == '0' ? form->zero = 1 : 0;
		**str == '-' ? form->minus = 1 : 0;
		**str == ' ' ? form->space = 1 : 0;
		(*str)++;
	}
	return (0);
}

int			width(char **str, t_form *form)
{
	int nb;

	if (ft_isdigit(*str[0]))
	{
		nb = ft_atoi(*str);
		form->width = nb;
		*str += int_len(nb);
	}
	return (0);
}

int			precision(char **str, t_form *form)
{
	int	nb;

	if (**str == '.')
	{
		(*str)++;
		if (!ft_isdigit(*str[0]))
		{
			form->prec = 0;
			return (0);
		}
		nb = ft_atoi((*str));
		form->prec = nb;
		*str += int_len(nb);
		return (0);
	}
	return (0);
}

int			length(char **str, t_form *form)
{
	if (**str != 'j' && **str != 'h' && **str != 'l' && **str != 'z')
		return (0);
	form->length = (**str == 'h' && form->length < H) ? H : form->length;
	form->length = !ft_strncmp(*str, "hh", 2) ? HH : form->length;
	form->length = !ft_strncmp(*str, "l", 1) ? L : form->length;
	form->length = !ft_strncmp(*str, "ll", 2) ? LL : form->length;
	form->length = !ft_strncmp(*str, "z", 1) ? Z : form->length;
	form->length = !ft_strncmp(*str, "j", 1) ? J : form->length;
	if (form->length != -1)
		*str += form->length > 3 ? 2 : 1;
	return (0);
}
