/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 12:20:41 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/26 16:41:42 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int	ft_putstr_prec(char const *s, int prec)
{
	int i;

	i = 0;
	if (prec == -1)
	{
		ft_putstr(s);
		return (0);
	}
	while (s[i] != 0 && prec > 0)
	{
		ft_putchar(s[i]);
		prec--;
		i++;
	}
	return (0);
}

int				print_str(va_list ap, t_form *form, int *flags)
{
	int			len;
	int			ret;
	const char	*sval;
	
	sval = va_arg(ap, char *);
	if (sval == NULL)
	{
		sval = ft_strdup("(null)");
		len = 6;
	}
	else
		len = ft_strlen(sval);	
	if (form->prec < len && form->prec != -1)
		len = form->prec;
	ret = form->width > len ? form->width : len;
	if (flags[1] != 1)
		flags[3] == 1 ? print_width(form->width, len, 1) : print_width(form->width, len, 0);
	ft_putstr_prec(sval, form->prec);
	if (flags[1] == 1)
		print_width(form->width, len, 0);
	return (ret);
}
