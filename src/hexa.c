#include <stdio.h>


int	convert(i)
{
	if (i > 9) 
	 printf("%c", i + 55);
	else 
	printf("%d", i); 
	return (0);
}
int main(void)
{
	int n = 320;
	int	r;
	int q = 1;

	while (q != 0)
	{
		q = n / 16;
		r = n % 16;
		convert(r);
		n = q;
	}
	return (0);	
}
