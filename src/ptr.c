#include <stdio.h>
#include <stdarg.h>


int myprintf(const char *format, ...)
{
	va_list ap;
	const char *p;
	int		val;
	int		*adr;
	void	*ptr;

	va_start(ap, format);
	p = format;
	while (*p != 0)
	{
		if (*p != '%')
			printf("%c", *p);
		else
		{
			p++;
			val = va_arg(ap, int);
			adr = &val;
			printf("0x7fff%x\n", val);
		}
		p++;
	}
	return (0);
}

int main(void)
{
	int age;
	int *ptr = &age;

	age = 10;

	printf("%p\n", &age); 	// la valeur que je dois trouver
	myprintf("%p", &age); 		// ce que je trouve moi
	//printf("%d\n", ptr);
	return (0);
}
