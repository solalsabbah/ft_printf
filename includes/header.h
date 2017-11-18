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

typedef	struct		s_fct
{
	char		c;
	int		(*f) (va_list ap);
}			t_fct;

int	ft_convert_oct(int nn);
int	ft_printf(const char *restrict format, ...);
char	*ft_putsign(int	nb);
char	*ft_convert_hex(int n);
int	ft_width(int ival, int nb);

#endif
