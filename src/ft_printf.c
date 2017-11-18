/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:04:17 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/16 17:20:03 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../includes/header.h"
#include "../libft/libft.h"

/*t_fct        g_fct_tab[] =
{
	{'s', &print_str},
	{'S', &print_str},
	{'p', &print_ptr},
	{'d', &print_int},
	{'D', &print_int},
	{'b', &print_bin},
	{'B', &print_bin},
	{'i', &print_int},
	{'o', &print_oct},
	{'O', &print_oct},
	{'u', &print_uns_int},
	{'U', &print_uns_int},
	{'x', &print_hex},
	{'X', &print_hex},
	{'c', &print_char},
	{'C', &print_char},
	{'n', &get_len},
	{0, NULL}
};*/

int		print_width(int nb, int len, int flag)
{
	char c;
	
	c = ' ';
	if (flag == 1)
		c = '0';
	while (nb > len)
	{
		ft_putchar(c);
		nb--;
	}
	return (0);
}

void	print_str(const char *sval, int nb)
{
		int	len;

		len = ft_strlen(sval);
		while (nb > len)
		{
			ft_putchar(' ');
			nb--;
		}
		ft_putstr(sval);
}

void	ft_print_number(const char p, int ival, int nb, int flag)
{
	int		len;
	char	*str;
	
	if (p == 'd')
	{
		len = int_len(ival);
		print_width(nb, len, flag);
		ft_putnbr(ival);
	}
	if (p == 'X')
	{
		str = ft_convert_hex(ival);
		len = ft_strlen(str);
		print_width(nb, len, flag);
		ft_putstr(str);
		
	}	
	if (p == 'o')
	{
		len = int_len(ft_convert_oct(ival));	
		print_width(nb, len, flag);	
		ft_putnbr(ft_convert_oct(ival));
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*p;
	const char	*sval;
	int		ival;
	char		cval;
	int			nb;
	int			flag;

	va_start(ap, format);
	p = format;
	flag = 0;
	while (*p != 0) 
	{
		if (*p != '%')
			ft_putchar(*p);
		else if (*p == '%')
		{
			p++;
			while (g_fct_tab[i].p && g_fct_tab[i].p)
				i++;
			if (g_fct_tab[i].f != NULL)
			/*nb = ft_atoi(p);
			while (*p >= '0' && *p <= '9')
			{
				if (*p == '0')
					flag = 1;	
				p++;
			}
			if (*p == 'd' || *p == 'X' || *p == 'o' )
			{
				ival = va_arg(ap, int);
				ft_print_number(*p, ival, nb, flag);
			}
			else if (*p == 's')
			{
				sval = va_arg(ap, char *);
				print_str(sval, nb);
			}
			else if (*p == 'c')
			{	
				cval = va_arg(ap, int);	
				ft_putchar(cval);
			}*/
		}
		p++;
	}
	va_end(ap);
	return (0);
}

int main(void)
{
	ft_printf("%0023d\n", 511390);
	printf("%023d\n", 511390);
	printf("===============\n");
	ft_printf("%23s\n", "511390");
	printf("%23s\n", "511390");
	printf("===============\n");
	ft_printf("%0023X\n", 511390);
	printf("%023X\n", 511390);
	printf("===============\n");
	ft_printf("%0023o\n", 511390);
	printf("%023o\n", 511390);
	printf("===============\n");
	ft_printf(" Je m'apelle %12s, j'ai %11o ans\n", "Solal", 23);
	printf(" Je m'apelle %12s, j'ai %11o ans\n", "Solal", 23);
	//ft_printf("Je m'appelle %s, j'ai %42d ans\n", "Solal", 23);
	//ft_printf("J'ai %x ans en hexadecimal\n", 23);
	//printf("%6s\n", "chien");
	//printf("%d\n", ft_atoi("005d\n"));
	return (0);
}
