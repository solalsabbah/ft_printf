/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:28:13 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/29 13:13:01 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../libft/libft.h"
#include <stdio.h>

char	*append_char(char const *s1, char c)
{
	char	*str;
	int		i;
	int		j;

	if (s1 && c)
	{
		str = malloc(sizeof(*str) * (ft_strlen(s1) + 1));
		i = 0;
		j = 0;
		if (str == NULL)
			return (NULL);
		while (s1[i] != 0)
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = c;
		i++;
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char	convert(i)
{
	if (i > 9)
		return (i + 55);
	else
		return (i + 48);
	return (0);
}

char	*ft_convert_hex(int n)
{
	int	r;
	int q;
	char *str;

	q = 1;
	str = malloc(sizeof(char *) * 1);
	while (q != 0)
	{
		q = n / 16;
		r = n % 16;
		str = append_char(str, convert(r));
		n = q;
	}
	ft_strrev(str);
	return (str);
}

int		ft_convert_oct(int n)
{
	int o;
	int nb;
	int j;

	o = 0;

	nb = 0;
	j = n;
	while (j > 0)
	{
		nb = nb * 10 + (j % 8);
		j = j / 8;
	}
	while (nb > 0)
	{
		o = o * 10 + (nb % 10);
		nb = nb / 10;
	}
	return (o);
}
