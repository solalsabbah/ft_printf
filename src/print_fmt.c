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
	return (0);
}

void	print_ptr(va_list ap, int nb)
{
	void *adr;
	nb = 0;

	adr = va_arg(ap, void*);
	ft_putstr(ft_convert_long_hex((long int)adr));
}

void	print_blank(va_list ap, int nb)
{
	nb = 0;
	ap = 0;
}

void	ft_putnbr_uns(long int n)
{
	long int nb;
	int p;

	p = 0;
	nb = n;
	if (nb < 0 && p == 0)
	{	
		write(1, "-1", 2);
		p = 1;
	}
	if (nb > 9)
	{
		ft_putnbr_uns(nb / 10);
		ft_putnbr_uns(nb % 10);
	}
	else 
		ft_putchar(nb + '0');
}

void	print_uns_int(va_list ap, int nb)
{
	int len;
	unsigned int ival;

	ival = va_arg(ap, unsigned int);
	len = int_len(ival);
	print_width(nb, len, 0);
	ft_putnbr_uns(ival);
}

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

void	print_bin(va_list ap, int nb)
{
	int			q;
	int			r;
	int			i;
	char		*str;
	int			nbr;
	int			p;

	q = 1;
	i = 0;
	p = 0;
	nb = 0;
	nbr = va_arg(ap, int);
	str = malloc(sizeof(str) * 32 + 1);
	if (nbr < 0)
	{
		nbr = -nbr;
		p = 1;
	}
	while (q != 0)
	{
		q = nbr / 2;
		r = nbr % 2;
		str[i] = r + '0';
		nbr = q;
		i++;
	}
	if (p == 1)
		str[i] = '-';
	ft_strrev(str);
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
