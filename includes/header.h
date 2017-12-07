/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:18:22 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/07 10:56:06 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <unistd.h>

typedef	struct		s_fct
{
	char		c;
	int			(*f) (va_list ap, int nb, int *flags);
}			t_fct;

int			ft_convert_oct(int nn);
int			ft_printf(const char *restrict format, ...);
int			ft_putsign(int	nb);
char		*ft_convert_hex(int n);
char const	*ft_convert_long_hex(long int n);
int			ft_width(int ival, int nb);
int			print_char(va_list ap, int nb, int *flags);
int			print_hex(va_list ap, int nb, int *flags);
int			print_oct(va_list ap, int nb, int *flags);
int			print_int(va_list ap, int nb, int *flags);
int			print_str(va_list ap, int nb, int *flags);
int			print_ptr(va_list ap, int nb, int *flags);
int			print_blank(va_list ap, int nb, int *flags);
int			print_bin(va_list ap, int nb, int *flags);
int			print_uns_int(va_list ap, int nb, int *flags);
int			ft_fmt(const char *str, va_list ap);
int			print_width(int nb, int len, int flag);

#endif
