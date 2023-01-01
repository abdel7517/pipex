/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:49:48 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/16 09:49:48 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_sign(char *str)
{
	while (*str)
	{
		if (*str == '-' || *str == '+')
			return (0);
		str++;
	}
	return (1);
}

void	ft_convert_hexa(int nbr, char *base, t_printf *data)
{
	int				base_len;
	long long int	long_nbr;

	long_nbr = nbr;
	base_len = 16;
	if (long_nbr < 0)
	{
		long_nbr = long_nbr + (4294967296);
	}
	if (long_nbr > base_len -1)
		ft_convert_hexa(long_nbr / base_len, base, data);
	ft_putchar_len(base[long_nbr % base_len], data);
}
