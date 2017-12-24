/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 16:15:00 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/24 19:02:06 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			*init_tab(size_t n)
{
	size_t i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * n + 1);
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int			*ft_flags(const char *str)
{
	int	i;
	int	*tab;

	i = 0;
	tab = init_tab(10);
	while (str[i] != 0)
	{
		str[i] == '#' ? tab[0] = 1 : 0;
		str[i] == '-' ? tab[1] = 1 : 0;
		str[i] == '+' ? tab[2] = 1 : 0;
		((str[i] == '#' || str[i] == '-' || str[i] == '+' || str[i] == ' ') && str[i + 1] == '0') || str[0] == '0' ? tab[3] = 1 : 0;
		str[i] == ' ' ? tab[4] = 1 : 0;
		str[i] == 'h' && str[i - 1] != 'h' && str[i + 1] != 'h' ? tab[5] = 1 : 0;
		str[i] == 'h' && str[i + 1] == 'h' ? tab[6] = 1 : 0;
		str[i] == 'l' && str[i - 1] != 'l' && str[i + 1] != 'l' ? tab[7] = 1 : 0;
		str[i] == 'l' && str[i + 1] == 'l' ? tab[8] = 1 : 0;
		str[i] == 'j' ? tab[9] = 1 : 0;
		str[i] == 'z' ?	tab[10] = 1 : 0;
		i++;
	}
	return (tab);
}

int             length(const char *str, t_form *form)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		form->length = (str[i] == 'h' && form->length < H) ? H : form->length;
		form->length = !ft_strncmp(&str[i], "hh", 2) ? HH : form->length;
		form->length = (str[i] == 'l' && form->length < LL) ? L : form->length;
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
