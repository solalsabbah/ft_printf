#include "../includes/libft.h"

int             length(const char *str, t_form *form)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		form->length = (str[i] == 'h' && form->length < H) ? H : form->length;
		form->length = !ft_strncmp(&str[i], "hh", 2) ? HH : form->length;
		form->length = !ft_strncmp(&str[i], "l", 1) ? L : form->length;
		form->length = !ft_strncmp(&str[i], "ll", 2) ? LL : form->length;
		form->length = !ft_strncmp(&str[i], "z", 1) ? Z : form->length;
		form->length = !ft_strncmp(&str[i], "j", 1) ? J : form->length;
		i++;
	}
	return (0);
}

int		width(const char *str, t_form *form)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (0);
		if (str[i] > '0' && str[i] <= '9' )
		{
			form->width = ft_atoi(&str[i]);
			return (1);
		}
		i++;
	}
	form->width = 0;
	return (0);
}

int		precision(const char *str, t_form *form)
{
	int i;
	i = 0;
	while (*str)
	{
		if (*str == '.')
		{
			str++;
			form->prec = ft_atoi(str);
			return (0);
		}
		str++;
	}
	form->prec = -1;
	return (-1);
}
