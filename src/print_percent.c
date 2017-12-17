#include "../includes/libft.h"

int			print_percent(va_list  ap, int nb, int prec, int *flags)
{
	ap = 0;
	if (flags[1] == 1)
	{
		ft_putchar('%');
		if (flags[3] == 1)
			print_width(nb, 1, 1);
		else
			print_width(nb, 1, 0);
	}
	else
	{
		print_width(nb, 1, 0);
		ft_putchar('%');
	}
	if (nb != 0)
		return (nb);
	else
		return (1);
}
