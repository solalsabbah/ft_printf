/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:06:02 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/30 17:34:11 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int		main(void)
{
	int *tab;
	int i;
	i = 0;	
	tab = malloc(sizeof(int) * 5);
	while (i < 5)
	{
		tab[i] = 1 + i;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		printf("tab %d\n", (tab[i]));
		i++;
	}
//	int a = 3;
//	char c = 'A';
//	printf("< ca rentre %#S>\n", "salut");
//	printf("<%d>\n", printf("%p", &a));
//	printf("<%d>\n", printf("%p", &c));
//	printf("<%32d>\n", 3);
//	printf("<%#p>\n", &a);
//	printf("<%i>\n", 43);
//	printf("<%x>\n", 43);
//	printf("<%u>\n", 43);
//	printf("<%#c>\n", 'A');
//	printf("%d\n", atoi("  -43"));
//	printf("<%%0005d>\n", 3);
//	printf("<%d>\n", 3);
//	printf("%d\n", 3);
//	printf("%-f\n", 3.300);
//	printf("%-f\n", 3.3);
	return(0);
}
