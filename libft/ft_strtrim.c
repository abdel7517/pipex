/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:12:00 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/11 11:12:00 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_first_sep(char const *str, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_separator(str[i], set) == 1)
			count++;
		else
			break ;
		i++;
	}
	return (count);
}

static int	count_last_sep(char const *str, char const *set)
{
	int	count;
	int	str_len;

	count = 0;
	str_len = ft_strlen(str) - 1;
	while (str[str_len])
	{
		if (is_separator(str[str_len], set) == 1)
			count++;
		else
			break ;
		str_len--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		j;
	char	*str;
	int		len_without_sep;
	int		first_count;
	int		str_len;

	str_len = ft_strlen(s1);
	j = 0;
	len_without_sep = 0;
	first_count = count_first_sep(s1, set);
	if (str_len != first_count)
		len_without_sep = str_len - first_count - count_last_sep(s1, set);
	str = (char *)malloc(sizeof(char) * (len_without_sep + 1));
	if (!str)
		return (0);
	str[len_without_sep] = '\0';
	while (s1[first_count] && (first_count < str_len - count_last_sep(s1, set)))
	{
		str[j] = s1[first_count];
		first_count++;
		j++;
	}
	return (str);
}

// int main() {
//   ft_strtrim("   xxxtripouille   xxx", " x");
//   return 0;
// }