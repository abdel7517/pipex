/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:15:44 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/10 15:15:44 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strs(char const *str, char separator)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == separator))
			i++;
		if (str[i])
			count++;
		while (str[i] && (str[i] != separator))
			i++;
	}
	return (count);
}

static int	ft_strlen_word(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
			i++;
	return (i);
}

static char	*store_word(char const *str, char c)
{
	char	*word;
	int		len_word;
	int		i;

	i = 0;
	len_word = ft_strlen_word(str, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		strs_len;
	int		i;

	i = 0;
	strs_len = count_strs(s, c) + 1;
	strs = (char **)malloc(sizeof(char *) * strs_len);
	if (!strs)
		return (NULL);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			strs[i] = store_word(s, c);
			i++;
		}
		while (*s && (*s != c))
			s++;
	}
	strs[i] = 0;
	return (strs);
}
