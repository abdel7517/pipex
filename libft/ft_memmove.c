/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:42:00 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/08 19:42:00 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*char_dest;
	char	*char_src;
	int		i;

	char_dest = (char *) dest;
	char_src = (char *) src;
	i = (int)n - 1;
	if (src < dest)
	{
		while (i >= 0)
		{
			char_dest[i] = char_src[i];
			i--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (char_dest);
}
