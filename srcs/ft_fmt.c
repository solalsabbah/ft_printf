/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:27:49 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/24 17:59:12 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

t_fct	g_fct_tab[] =
{
	{'S', &print_str},
	{'s', &print_str},
	{'p', &print_ptr},
	{'d', &print_int},
	{'D', &print_int},
	{'i', &print_int},
	{'o', &print_oct},
	{'O', &print_oct},
	{'x', &print_hex},
	{'X', &print_maj_hex},
	{'c', &print_char},
	{'C', &print_char},
	{'u', &print_uns_int},
	{'U', &print_uns_int},
	{'b', &print_bin},
	{'B', &print_bin},
	{'%', &print_percent},
	{0, NULL}
};

void		init_format(t_form *form)
{
	form->width = 0;
	form->prec = -1;
	form->length = -1;
}

int			ft_fmt(const char *str, va_list ap, t_form *form)
{
	int		i;
	int		ret;
	int 	*flags;

	i = 0;
	init_format(form);
	flags = ft_flags(str);
	width(str, form);
	precision(str, form);
	length(str, form);
	str = ft_strpbrk(str, "sSpdDioOuUxXcCBb%");
	while (g_fct_tab[i].c != '0')
	{
		if (g_fct_tab[i].c == str[0])
		{
			ret = g_fct_tab[i].f(ap, form, flags);
			return (ret);
		}
		i++;
	}
	return (0);
}
