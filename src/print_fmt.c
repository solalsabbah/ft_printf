#include "../includes/header.h"
#include "../libft/libft.h"

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

/*void	print_ptr(va_list ap, int nb)
{
	int *p_ap = &ap;
	ft_put
}*/

void	print_str(va_list ap, int nb)
{
	int	len;
	const char	*sval;

	sval = va_arg(ap, char *);
	len = ft_strlen(sval);
	while (nb > len)
	{
		ft_putchar(' ');
		nb--;
	}
	ft_putstr(sval);
}
void	print_int(va_list ap, int nb)
{
	int len;
	int ival;

	ival = va_arg(ap, int);
	len = int_len(ival);
	print_width(nb, len, 0);
	ft_putnbr(ival);
}

void	print_oct(va_list ap, int nb)
{
	int len;
	int ival;
	int flag;

	flag = 0;
	ival = va_arg(ap, int);
	len = int_len(ft_convert_oct(ival));
	print_width(nb, len, flag);
	ft_putnbr(ft_convert_oct(ival));
}

void	print_hex(va_list ap, int nb)
{
	int	len;
	char	*str;
	int	flag;
	int	ival;

	flag = 0;
	ival = va_arg(ap, int);
	str = ft_convert_hex(ival);
	len = ft_strlen(str);
	print_width(nb, len, flag);
	ft_putstr(str);
}

void	print_char(va_list ap, int nb)
{
	char cval;

	while (nb - 1 > 0)
	{
		ft_putchar(' ');
		nb--;
	}
	cval = va_arg(ap, int);
	ft_putchar(cval);
}
