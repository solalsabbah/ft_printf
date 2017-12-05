/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:27:37 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/05 15:17:17 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>

int		print_ptr(va_list ap, int nb, char **flags)
{
	void *adr;
	nb = 0;
	flags[0][0] = 1;
	adr = va_arg(ap, void*);
	ft_putstr("0x");
	ft_putstr(ft_convert_long_hex((long int)adr));
	return (14);
}

int		print_uns_int(va_list ap, int nb, char **flags)
{
	int len;
	unsigned int ival;

	flags[0][0] = 1; // to change
	ival = va_arg(ap, unsigned int);
	len = int_len(ival);
	print_width(nb, len, 0); // to change
	ft_putnbr_uns(ival);
	return (len);
}

int		print_str(va_list ap, int nb, char **flags)
{
	int	len;
	const char	*sval;

	flags[0][0] = 1; // to change
	sval = va_arg(ap, char *);
	len = ft_strlen(sval);
	while (nb > len)
	{
		ft_putchar(' ');
		nb--;
	}
	ft_putstr(sval);
	return (len);
}

int		print_int(va_list ap, int nb, char **flags)
{
	int len;
	int ival;
	
	if (flags[2][0] == '1')
		nb = nb - 1;
	ival = va_arg(ap, int);
	len = int_len(ival);
	print_width(nb, len, 0); // to change
	if (flags[2][0] == '1')
	{
		if (ival < 0)
			ft_putchar('-');
		else
			ft_putchar('+');
	}
	ft_putnbr(ival);
	return (len);
}

int		print_oct(va_list ap, int nb, char **flags)
{
	int len;
	int ival;

	if (flags[0][0] == '1')
		nb = nb - 1;
	ival = va_arg(ap, int);
	len = int_len(ft_convert_oct(ival));
	print_width(nb, len, 0); // to change
	if (flags[0][0] == '1')
		ft_putchar('0');
	ft_putnbr(ft_convert_oct(ival));
	return(len);
}

int		print_hex(va_list ap, int nb, char **flags)
{
	int	len;
	char	*str;
	int	ival;

	ival = va_arg(ap, int);
	str = ft_convert_hex(ival);
	len = ft_strlen(str);
	if (flags[0][0] == '1')
	{
		ft_putstr("0x");
		nb = nb - 2;
	}
	if (flags[3][0] == '1')
		print_width(nb, len, 1);		
	ft_putstr(str);
	return (len);
}

int		print_bin(va_list ap, int nb, char **flags)
{
	int			q;
	int			r;
	int			i;
	char			*str;
	int			nbr;
	int			p;

	q = 1;
	i = 0;
	p = 0;
	nb = 0;
	nbr = va_arg(ap, int);
	str = malloc(sizeof(str) * 32 + 1);
	flags[0][0] = 1;
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
	ft_putstr(ft_strrev(str));
	return (i + p);
}

int		print_char(va_list ap, int nb, char **flags)
{
	char cval;

	flags[0][0] = 1;
	while (nb - 1 > 0)
	{
		ft_putchar(' ');
		nb--;
	}
	cval = va_arg(ap, int);
	ft_putchar(cval);
	return (1);
}
