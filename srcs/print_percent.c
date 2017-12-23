#include "../includes/libft.h"

int			print_percent(va_list ap, t_form *form, int *flags)
{
	ap = 0;
	if (flags[1] == 1)
	{
		ft_putchar('%');
		if (flags[3] == 1)
			print_width(form->width, 1, 1);
		else
			print_width(form->width, 1, 0);
	}
	else
	{
		print_width(form->width, 1, 0);
		ft_putchar('%');
	}
	if (form->width != 0)
		return (form->width);
	else
		return (1);
}
