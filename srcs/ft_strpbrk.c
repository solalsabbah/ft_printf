/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:59:03 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:12 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int j;

	while (*s1 != 0)
	{
		j = 0;
		while (s2[j] != 0)
		{
			if (s2[j] == *s1)
				return ((char *)s1);
			j++;
		}
		s1++;
	}
	return (NULL);
}
