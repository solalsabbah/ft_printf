#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>

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
	return (nb);
}

int		print_int(va_list ap, int nb, int *flags)
{
	int len;
	int ival;

	ival = va_arg(ap, int);
	len = int_len(ival);
	
	if (flags[1] != 1 && flags[2] != 1 && flags[3] != 1)
		nb =  print_width(nb, len, 0);
	if (flags[3] == 1 && flags[2] != 1)
	{
		if (ival < 0)
		{
			ft_putchar('-');
			nb--;
		}
		nb = print_width(nb, len, 1);
	}
	if (flags[2] == 1)
	{
		nb--;
		if (ival < 0)
			ft_putchar('-');
		else
			ft_putchar('+');
		if (flags[1] != 1 && flags[3] == 1)
			nb = print_width(nb, len, 1);
	}
	if (flags[3] == 1 && nb > len && flags[1] != 1)
	{
		ft_putchar(' ');
		nb--;
	}
	if (flags[4] == 1 && nb > len)
		nb = print_width(nb, len, 1);
	if (ival < 0 && flags[3] == 1)
		ft_putnbr(-ival);
	else
		ft_putnbr(ival);
	if (flags[1] == 1 && nb > len)
		print_width(nb,len, 0);
	return (len);
}
