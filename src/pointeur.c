#include <stdio.h>
#include "../libft/libft.h"
int		main()
{
	char c;
	char *str = "salut";
	int	i;

	c = 'a';
	i = 4;
	ft_putstr(&str);
	printf("%p\n", &str);
	printf("%p\n", &str[0]);
	printf("%p\n", &str[1]);
	printf("%p\n", &c);
	printf("%p\n", &i);
	return (0);
}

