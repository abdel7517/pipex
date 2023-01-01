/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:03:59 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/15 16:03:59 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr(uintptr_t ptr, t_printf *data)
{
	const char	*base_hexa = "0123456789abcdef";

	if (ptr >= 16)
		ft_put_ptr(ptr / 16, data);
	ft_putchar_len(base_hexa[ptr % 16], data);
}

void	ft_convert_ptr(t_printf *data, va_list parameters_infos)
{
	t_type	type;

	type.ptr_value = (uintptr_t)va_arg(parameters_infos, uintptr_t);
	if (type.ptr_value == 0)
		ft_putstr("(nil)", data);
	else
	{
		ft_putstr("0x", data);
		ft_put_ptr(type.ptr_value, data);
	}
}
