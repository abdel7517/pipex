/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:13:35 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/09 20:13:35 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	result = NULL;
	i = 0;
	if (c == 0)
		return (ft_strlen(s) + (char *)s);
	while (s[i])
	{
		if (s[i] == (char)c)
			result = (char *)(&s[i]);
		i++;
	}
	return (result);
}
