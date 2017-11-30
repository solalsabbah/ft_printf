/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@&2.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 1&:12:18 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/30 17:37:04 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>



t_fct	g_fct_tab[] = // is it ok to leave this like this ?
{
	{'S', &print_str},
	{'s', &print_str},
	{'d', &print_int},
	{'D', &print_int},
	{'i', &print_int},
	{'o', &print_oct},
	{'O', &print_oct},
	{'x', &print_hex},
	{'X', &print_hex},
	{'c', &print_char},
	{'C', &print_char},
	{'n', &print_blank},
	{'u', &print_uns_int},
	{'U', &print_uns_int},
	{'b', &print_bin},
	{'B', &print_bin},
	{0, NULL}
};

int			flags(const char *str)
{
	int f;
	int j;
	char tab[5][1];

	while (str[i])
	{
		if (str[j] == '#')
			tab[0][0] = 1;	
		if (str[j] == '-')
			tab[1][0] = 1;	
		if (str[j] == '+')
			tab[2][0] = 1;	
		if (str[j] == '0')
			tab[3][0] = 1;	
		if (str[j] == ' ')
			tab[4][0] == '+';
	}
	return (tab);
	// possible de faire avancer dans le pointeur pour ne pas reprendre la lecture du debut ?
}

int			ft_fmt(const char *str, va_list ap)
{
	int i;
	int j;
	int f;
	int nb;

	i = 0;
	j = 0;
	if (str[j] == '%')
	{
		ft_putchar('%');
		return (0);
	}
	f = flags(str);
	nb = ft_atoi(str);
	while (g_fct_tab[i].c != str[j])
	{
		i = 0;
		while (g_fct_tab[i].c != 0)
		{
			if (g_fct_tab[i].c == str[j])
			{
				g_fct_tab[i].f(ap, nb);
				return (j);
			}
			i++;
		}
		j++;
	}
	return (j);
}
