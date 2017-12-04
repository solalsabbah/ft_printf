
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

char			**ft_flags(const char *str)
{
	int j;
	char **tab;
	
	j = 0;
	tab = malloc(sizeof(char *) * 6);
	while (j < 5)
	{
		tab[j] = ft_strnew(2);
		j++;
	}
	tab[j] = 0;
	j = 0;
	while (str[j] != 0)
	{
		if (str[j] == '#')
			ft_strcpy(tab[0], "1"); 	
		if (str[j] == '-')
			ft_strcpy(tab[1], "1"); 	
		if (str[j] == '+')
			ft_strcpy(tab[2], "1"); 	
		if (str[j] == '0')
			ft_strcpy(tab[3], "1"); 	
		 if (str[j] == ' ')
			ft_strcpy(tab[4], "1");	
		if (str[j] == ' ')
			ft_strcpy(tab[4], "1");
		if (str[j] == ' ')
			ft_strcpy(tab[4], "1");
j++;
	}
	return (tab);
}

int		find_numb(const char *str)
{
	int i;
	i = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			return (ft_atoi(str));
		str++;
	}
	return (0);
}

int			ft_fmt(const char *str, va_list ap)
{
	int i;
	int j;
	int nb;
	char **flags;

	i = 0;
	j = 0;
	if (str[j] == '%')
	{
		ft_putchar('%');
		return (0);
	}
	flags = ft_flags(str);
	nb = find_numb(str);
	//str = ft_strpbrk(str, "sSpdDioOuUxXcCBb"); // Natan est ce que j'ai le droit de faire ca ou je perds mon pointeur ? // je veux avancer dans mon pointeur // un peu redondant avec ce qu'il y a après. // Attention ca cause un pbm avec mon curseur j
	while (g_fct_tab[i].c != str[j])
	{
		i = 0;
		while (g_fct_tab[i].c != 0)
		{
			if (g_fct_tab[i].c == str[j])
			{
				g_fct_tab[i].f(ap, nb, flags);
				return (j);
			}
			i++;
		}
		j++;
	}
	return (j);
}
