/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:27:49 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/14 14:31:45 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

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

	tab = init_tab(10);
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
		if (str[i] == 'h' && str[i - 1] != 'h' && str[i + 1] != 'h')
			tab[5] = 1;
		if (str[i] == 'h' && str[i + 1] == 'h')
			tab[6] = 1;
		if (str[i] == 'l' && str[i - 1] != 'l' && str[i + 1] != 'l')
			tab[7] = 1;
		if (str[i] == 'l' && str[i + 1] == 'l')
			tab[8] = 1;
		if (str[i] == 'j')
			tab[9] = 1;
		if (str[i] == 'z')
			tab[10] = 1;
		i++;
	}
	return (tab);
}


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
	{'n', &print_blank},
	{'u', &print_uns_int},
	{'U', &print_uns_int},
	{'b', &print_bin},
	{'B', &print_bin},
	{0, NULL}
};

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

int			print_percent(int nb, int *flags)
{
			if (flags[1] == 1)
			{
				ft_putchar('%');
				if (flags[3] == 0)
					print_width(nb, 1, 1);
				else 
					print_width(nb, 1, 0);
			}
			else
			{
					print_width(nb, 1, 1);
					ft_putchar('%');
			}
			if (nb != 0)
				return (nb);
			else 
				return (1);
}

int			ft_fmt(const char *str, va_list ap)
{
	int		i;
	int 	len;
	int 	nb;
	int		ret;
	int 	*flags;
	char	*fmt;

	i = 0;
	len = ft_strpbrk(str, "sSpdDioOuUxXcCBb") - str;
	fmt = ft_strsub(str, 0, len);
	flags = ft_flags(fmt);
	nb = find_numb(fmt);
	if (ft_strpbrk(str, "sSpdDioOuUxXcCBb%") == '%')
	{
		ret = print_percent(nb, flags);
		return (ret);
	}
	str = ft_strpbrk(str, "sSpdDioOuUxXcCBb");
	while (g_fct_tab[i].c != '0')
	{
		if (g_fct_tab[i].c == str[0])
		{
			ret = g_fct_tab[i].f(ap, nb, flags);
			return (ret);
		}
		i++;
	}
	return (len);
}
