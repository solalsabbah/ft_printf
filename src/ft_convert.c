/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:28:13 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/14 16:09:00 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
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

char	convert(int i, int maj)
{
	int a;

	if (maj == 1)
		a = 0;
	else
		a = 32;
	if (i > 9)
		return (i + 55 + a);
	else
		return (i + 48);
	return (0);
}

char	*ft_convert_hex(unsigned int n, int maj)
{
	int		r;
	int 	q;
	char 	*str;
	char 	*c;

	q = 1;
	str = malloc(sizeof(char) * 1);
	while (q != 0)
	{
		q = n / 16;
		r = n % 16;
		c = malloc(sizeof(char) * 2);
		c[0] = convert(r, maj);
		c[1] = 0;
		str = ft_strcat(str, c);
		n = q;
	}
	ft_strrev(str);
	return (str);
}

long int		ft_convert_oct(unsigned int n)
{
	long int	res;
	long int 	nb;
	long int 	j;
	long int 	base;

	res = 0;
	nb = 0;
	j = (long int)n;
	base = 1;
	while (j > 0)
	{	
		nb = nb * 10 + (j % 8);
		res = res + (j % 8) * base;
		j = j / 8;
		base = base * 10;
	}
	return (res);
}
