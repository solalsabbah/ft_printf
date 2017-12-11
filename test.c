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
	int a = -1;

	ft_putnbr_uns((unsigned int)a);
	printf("\n%u\n", -1);
	printf("%x\n", -1);
	printf("%u\n", -2);
	printf("%x\n", -2);
	//printf("%d\n", printf("%#4o\n", -2));
	
	//printf("%d\n", printf("%#4o\n", -10));
//	printf("===========\n");
//	printf("%d\n", printf("%d\n", 23));
//	printf("===========\n");
//	printf("%d\n", printf("%-d\n", 23));
//	printf("===========\n");
//	printf("%d\n", printf("%+d\n", 23));
//	printf("==== test 4  ======\n");
//	printf("%d\n", printf("%10d", 230000000));
//	printf("%d\n", printf("<%+-5d>\n", 23));
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
//	printf("<%%0005d>\n", 3);
//	printf("<%d>\n", 3);
//	printf("%d\n", 3);
//	printf("%-f\n", 3.300);
//	printf("%-f\n", 3.3);
	return(0);
}
