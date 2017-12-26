#include <stdlib.h>
#include "../includes/libft.h"
char	find_char(const char *s1, const char *s2)
{
	int j;
	
	while(*s1 != 0)
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
