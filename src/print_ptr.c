#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>

int		print_ptr(va_list ap, int nb, int *flags)
{
	void *adr;
	char *str;

	nb = 0;
	flags[0] = 1;
	adr = va_arg(ap, void*);
	str = ft_strjoin("0x", ft_convert_long_hex((long int)adr));
	ft_putstr(str);
	return (14);
}
