/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 18:49:35 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/01 19:08:54 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_wstrlen(const wchar_t *wcs)
{
	int	i;

	i = 0;
	while (*wcs)
		i += ft_wcharlen(*wcs++);
	return (i);
}

/*int	ft_wstrnlen(const wchar_t *wstr, int n)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (wstr)
	{
		while (*wstr && i + len <= n)
		{
			if ((len = ft_wcharlen(*wstr++)) == 0)
				return (-1);
			if (i + len > n)
				return (i);
			i += len;
		}
	}
	return (i);
}*/

char	*ft_getwstr(const wchar_t *wcs, int n)
{
	char	*str;
	char	*wc;
	int		len;

	if (n > (len = ft_wstrlen(wcs)))
		n = len;
	str = ft_strnew(n);
	if (!wcs || n < 0)
		return (NULL);
	while (*wcs && n--)
	{
		if (!(wc = ft_getwchar(*wcs++)))
		{
			free(str);
			return (NULL);
		}
		ft_strcat(str, wc);
		free(wc);
	}
	return (str);
}


int				print_wstr(wchar_t *wc, t_form *form, int *flags)
{
	char *str;
	str = ft_getwstr(wc, form->width);
	write(1, str, ft_strlen(str));
	return (0);
}
