/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:27:49 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/23 15:59:36 by ssabbah          ###   ########.fr       */
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

int			*init_tab(size_t n)
{
	size_t i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * n + 1);
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int			*ft_flags(const char *str)
{
	int	i;
	int	*tab;

	i = 0;
	tab = init_tab(10);
	while (str[i] != 0)
	{
		str[i] == '#' ? tab[0] = 1 : 0;
		str[i] == '-' ? tab[1] = 1 : 0;
		str[i] == '+' ? tab[2] = 1 : 0;
		((str[i] == '#' || str[i] == '-' || str[i] == '+' || str[i] == ' ') && str[i + 1] == '0') || str[0] == '0' ? tab[3] = 1 : 0;
		str[i] == ' ' ? tab[4] = 1 : 0;
		str[i] == 'h' && str[i - 1] != 'h' && str[i + 1] != 'h' ? tab[5] = 1 : 0;
		str[i] == 'h' && str[i + 1] == 'h' ? tab[6] = 1 : 0;
		str[i] == 'l' && str[i - 1] != 'l' && str[i + 1] != 'l' ? tab[7] = 1 : 0;
		str[i] == 'l' && str[i + 1] == 'l' ? tab[8] = 1 : 0;
		str[i] == 'j' ? tab[9] = 1 : 0;
		str[i] == 'z' ?	tab[10] = 1 : 0;
		i++;
	}
	return (tab);
}

int			ft_fmt(const char *str, va_list ap, t_form *form)
{
	int		i;
	int		ret;
	int 	*flags;

	i = 0;
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
