/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:27:12 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:07 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_printf.h"

char	find_char(const char *s1, const char *s2)
{
	int j;

	while (*s1 != 0)
	{
		j = 0;
		while (s2[j] != 0)
		{
			if (s2[j] == *s1)
				return (s2[j]);
			j++;
		}
		s1++;
	}
	return (0);
}
