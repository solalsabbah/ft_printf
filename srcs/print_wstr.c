/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 18:49:35 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:32:53 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				print_wstr(wchar_t *wc, t_form *form)
{
	static char		*str;
	int				i;
	int				ret;
	int				prec;

	i = 0;
	ret = 0;
	prec = 0;
	while (wc[i] != 0)
	{
		if (!(str = ft_getwchar((wchar_t)wc[i])))
			return (0);
		prec = prec + ft_strlen(str);
		free(str);
		if (form->prec != -1 && form->prec < prec)
			return (ret);
		ret = ret + print_wchar(wc[i], form);
		i++;
	}
	return (ret);
}
