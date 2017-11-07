/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:42:05 by ssabbah           #+#    #+#             */
/*   Updated: 2017/04/25 18:48:50 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char*)s + ft_strlen(s));
	while (i > -1)
	{
		if (s[i] == (unsigned char)c)
			return ((char*)s + i);
		i--;
	}
	return (0);
}
