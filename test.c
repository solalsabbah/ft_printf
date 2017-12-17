#include <stdio.h>

int	main()
{
	int a = 3;
	int b = 5;
	char str[] = "#+-0";

	str[0] == '#' ? a = 6 :  printf("%s\n", "ca marche pas") ;
	b < a ? printf("%s\n", "ca marche") : 1 ;	
	printf("%d\n", a) ;
	return (1);
}
