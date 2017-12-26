#include "../includes/libft.h"

void	field(const char *str, t_form *form)
{
	char c;
	
	c = find_char(str, "sSpdDioOuUxXcCBb%");
	form->field = c;
}
