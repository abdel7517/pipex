/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:22:12 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/15 15:22:12 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_nbr(const char *s, t_printf *data, va_list parameters_infos)
{
	if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(parameters_infos, int), data);
	else if (*s == 'u')
		ft_putnbr_unsigned(va_arg(parameters_infos, unsigned int), data);
}
