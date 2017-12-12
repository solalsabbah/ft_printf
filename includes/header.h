/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:18:22 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/12 16:59:57 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <unistd.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define COLOR_NORMAL    "\033[m"
#define COLOR_BLACK     "\033[30m"
#define COLOR_RED       "\033[31m"
#define COLOR_GREEN     "\033[32m"
#define COLOR_YELLOW    "\033[33m"
#define COLOR_BLUE      "\033[34m"
#define COLOR_MAGENTA   "\033[35m"
#define COLOR_CYAN      "\033[36m"
#define COLOR_WHITE     "\033[37m"
#define COLOR_RESET     "\033[0m"

typedef	struct		s_fct
{
	char		c;
	int			(*f) (va_list ap, int nb, int *flags);
}			t_fct;

long int		ft_convert_oct(long int n);
long int		ft_convert_uns_oct(long int n);
int				ft_printf(const char *restrict format, ...);
int				ft_putsign(int	nb);
char			*ft_convert_hex(int n);
char const		*ft_convert_long_hex(long int n);
int				ft_width(int ival, int nb);
int				print_char(va_list ap, int nb, int *flags);
int				print_hex(va_list ap, int nb, int *flags);
int				print_oct(va_list ap, int nb, int *flags);
int				print_int(va_list ap, int nb, int *flags);
int				print_str(va_list ap, int nb, int *flags);
int				print_ptr(va_list ap, int nb, int *flags);
int				print_blank(va_list ap, int nb, int *flags);
int				print_bin(va_list ap, int nb, int *flags);
int				print_uns_int(va_list ap, int nb, int *flags);
int				ft_fmt(const char *str, va_list ap);
int				print_width(int nb, int len, int flag);
long int		negtounsigned(int nb);
#endif
