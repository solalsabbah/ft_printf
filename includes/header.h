/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:18:22 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/16 17:20:02 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <unistd.h>

t_fct        g_fct_tab[] =
{
	{'s', &print_str},
	{'S', &print_str},
	{'p', &print_ptr},
	{'d', &print_int},
	{'D', &print_int},
	{'b', &print_bin},
	{'B', &print_bin},
	{'i', &print_int},
	{'o', &print_oct},
	{'O', &print_oct},
	{'u', &print_uns_int},
	{'U', &print_uns_int},
	{'x', &print_hex},
	{'X', &print_hex},
	{'c', &print_char},
	{'C', &print_char},
	{'n', &get_len},
	{0, NULL}
};

typedef	struct		s_fct
{
	char			c;
	int				(*f) (va_list ap, t_form* form, t_data* data);
}					t_fct;

void	ft_minprintf(const char *fmt, ...);
int		ft_convert_oct(int nn);
int		ft_printf(const char *restrict format, ...);
char	*ft_putsign(int	nb);
char	*ft_convert_hex(int n);
int		ft_width(int ival, int nb);

#endif
