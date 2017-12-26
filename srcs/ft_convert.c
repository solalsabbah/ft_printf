/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:28:13 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/26 13:17:47 by ssabbah          ###   ########.fr       */
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

char	*ft_convert_hex(unsigned long long n, int maj)
{
	long long	r;
	long long 	q;
	char 		*str;
	char 		*c;

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

unsigned long long		ft_convert_oct(unsigned long long n)
{
	long long			res;
	long long  			nb;
	long long			base;
	unsigned long long	j;

	res = 0;
	nb = 0;
	j = (long long)n;
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
