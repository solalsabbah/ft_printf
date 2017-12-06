#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>

int		print_oct(va_list ap, int nb, int *flags)
{
	int len;
	int ival;

	if (flags[0] == 1)
		nb = nb - 1;
	ival = va_arg(ap, int);
	len = int_len(ft_convert_oct(ival));
	print_width(nb, len, 0); // to change
	if (flags[0] == 1)
		ft_putchar('0');
	ft_putnbr(ft_convert_oct(ival));
	return(len);
}

int		print_hex(va_list ap, int nb, int *flags)
{
	int	len;
	char	*str;
	int	ival;

	ival = va_arg(ap, int);
	str = ft_convert_hex(ival);
	len = ft_strlen(str);
	if (flags[0] == 1)
	{
		ft_putstr("0x");
		nb = nb - 2;
	}
	if (flags[3] == 1)
		print_width(nb, len, 1);
	ft_putstr(str);
	return (len);
}
