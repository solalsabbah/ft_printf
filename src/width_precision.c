#include "../includes/libft.h"

int		find_width(const char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (0);
		if (str[i] > '0' && str[i] <= '9' )
			return (ft_atoi(&str[i]));
		i++;
	}
	return (0);
}



int		find_precision(const char *str)
{
	int i;
	i = 0;
	while (*str)
	{
		if (*str == '.')
		{
			str++;
			return (ft_atoi(str));
		}
		str++;
	}
	return (0);
}
