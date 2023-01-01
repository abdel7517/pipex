/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:15:19 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/15 15:15:19 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_str(const char *s, t_printf *data, va_list parameters_infos)
{
	t_type	type;

	if (*s == 'c')
	{
		type.char_value = (char)va_arg(parameters_infos, int);
		ft_putchar_len(type.char_value, data);
	}
	else if (*s == 's')
	{
		type.str_value = (char *)va_arg(parameters_infos, char *);
		if (type.str_value)
			ft_putstr(type.str_value, data);
		else
			ft_putstr("(null)", data);
	}
	else if (*s == '%')
		ft_putchar_len('%', data);
}
