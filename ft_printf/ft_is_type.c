/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:13:51 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/14 12:13:51 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_type(char c)
{
	const char	*type = "cspdiuxX%";
	int			i;

	i = 0;
	while (type[i])
	{
		if (type[i] == c)
			return (1);
		i++;
	}
	return (0);
}
