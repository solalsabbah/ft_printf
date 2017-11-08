/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:31:52 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/08 16:50:28 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

char	*ft_putsign(int	nb)
{
	char	*str;
	
	if (nb > 0) 
		str = ft_strcat("+", ft_itoa(nb));
	else 
		str = ft_strcat("-", ft_itoa(nb));
	return (str);
}

int		main(void)
{
	printf("%s\n", ft_putsign(+345));
	return (0);
}
