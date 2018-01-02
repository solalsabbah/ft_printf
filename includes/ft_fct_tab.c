#ifndef FT_FCT_TAB_H
# define FT_FCT_TAB_H
# include "ft_printf.h"

t_fct	g_fct_tab[] =
{
	{'S', &print_str},
	{'s', &print_str},
	{'p', &print_ptr},
	{'d', &print_int},
	{'D', &print_int},
	{'i', &print_int},
	{'o', &print_oct},
	{'O', &print_oct},
	{'x', &print_hex},
	{'X', &print_hex},
	{'c', &print_char},
	{'C', &print_char},
	{'u', &print_uns_int},
	{'U', &print_uns_int},
	{'b', &print_bin},
	{'B', &print_bin},
	{'%', &print_percent},
	{0, NULL}
};

#endif
