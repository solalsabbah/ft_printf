#include <stdlib.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int j;
	
	while(*s1)
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
