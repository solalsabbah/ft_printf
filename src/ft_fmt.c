
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

char			**flags(const char *str)
{
	int j;
	char **tab;
	
	j = 0;
	tab = malloc(sizeof(char *) * 5);
	while (j < 5)
	{
		tab[j] = ft_strnew(2);
		j++;
	}
	tab[j] = 0;
	while (str[j])
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
			tab[4][0] = '+';
	j++;
	}
	return (tab);
	// possible de faire avancer dans le pointeur pour ne pas reprendre la lecture du debut ?
}

int			ft_fmt(const char *str, va_list ap)
{
	int i;
	int j;
	int nb;

	i = 0;
	j = 0;
	if (str[j] == '%')
	{
		ft_putchar('%');
		return (0);
	}
	//flags(str);
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
