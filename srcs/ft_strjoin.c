/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:26:00 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:12 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 && s2)
	{
		str = malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2)));
		i = 0;
		j = 0;
		if (str == NULL)
			return (NULL);
		while (s1[i] != 0)
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j] != 0)
		{
			str[i + j] = s2[j];
			j++;
		}
		str[i + j] = '\0';
		return (str);
	}
	return (NULL);
}
