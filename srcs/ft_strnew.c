/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:29:33 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/13 15:41:23 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (void *)malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (0);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str[size] = '\0';
	return (str);
}
