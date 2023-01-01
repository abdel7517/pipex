/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:33:46 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/10 11:33:46 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*char_str1;
	unsigned const char	*char_str2;
	size_t				i;

	char_str1 = (unsigned const char *)s1;
	char_str2 = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if (char_str1[i] != char_str2[i])
			return (char_str1[i] - char_str2[i]);
		i++;
	}
	return (0);
}
