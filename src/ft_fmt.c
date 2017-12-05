/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:27:49 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/05 15:45:14 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>

t_fct	g_fct_tab[] = // is it ok to leave this like this ?
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

int				*ft_flags(const char *str)
{
	int 	i;
	int		*tab;

	i = 0;
	tab = malloc(sizeof(int) * 6);
	while (j < 5)
	{
		tab[i] = 0;
		i++;
	}
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '#')
			tab[0] = 1;
		if (str[i] == '-')
			tab[1] = 1;
		if (str[i] == '+')
			tab[2] = 1;
		if (((str[i] == '#' || str[i] == '-' || str[i] == '+' || str[i] == ' ') && str[i + 1] == '0') || str[0] == '0')
			tab[3] = 1;
		if (str[i] == ' ')
			tab[4] = 1;
		i++;
	}
	return (tab);
}

int		find_numb(const char *str)
{
	int i;
	i = 0;
	while (*str)
	{
		if (*str > '0' && *str <= '9')
			return (ft_atoi(str));
		str++;
	}
	return (0);
}

int			ft_fmt(const char *str, va_list ap)
{
	int i;
	int len;
	int nb;
	int *flags;
	char *fmt;

	i = 0;
	if (str[0] == '%')
	{
		ft_putchar('%');
		return (0);
	}
	len  = ft_strpbrk(str,"sSpdDioOuUxXcCBb") - str;
	fmt = ft_strsub(str, 0, len);
	flags = ft_flags(fmt);
	nb = find_numb(fmt);
	str = ft_strpbrk(str,"sSpdDioOuUxXcCBb");
	while (g_fct_tab[i].c != str[0])
	{
			if (g_fct_tab[i].c == str[0])
			{
				g_fct_tab[i].f(ap, nb, flags);
				return (len);
			}
		i++;
	}
	return (len);
}
