/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:26:25 by ssabbah           #+#    #+#             */
/*   Updated: 2017/12/28 14:27:04 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	field(const char *str, t_form *form)
{
	char c;

	c = find_char(str, "sSpdDioOuUxXcCBb%");
	form->field = c;
}
