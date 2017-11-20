/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:18:22 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/20 16:10:52 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <unistd.h>

typedef	struct		s_fct
{
	char		c;
	void		(*f) (va_list ap, int nb);
}			t_fct;

int	ft_convert_oct(int nn);
int	ft_printf(const char *restrict format, ...);
char	*ft_putsign(int	nb);
char	*ft_convert_hex(int n);
int	ft_width(int ival, int nb);
void	print_char(va_list ap, int nb);
void	print_hex(va_list ap, int nb);
void	print_oct(va_list ap, int nb);
void	print_int(va_list ap, int nb);
void	print_str(va_list ap, int nb);
void	print_ptr(va_list ap, int nb);
void	print_blank(va_list ap, int nb);

#endif
