/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:20:31 by pamartin          #+#    #+#             */
/*   Updated: 2022/10/06 14:06:24 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_count_words(char const *str, char c)
{
	int		count;
	int		i;
	char	**split;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	split = (char **)malloc(sizeof(char *) * (count + 1));
	return (split);
}

static int	ft_lenword(const char *str, char c, int i)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_copy(char *dest, const char *str, char c, int i)
{
	int	j;

	j = 0;
	while (str[i] && str[i] != c)
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	int		i;

	if (!s)
		return (0);
	split = ft_count_words(s, c);
	if (!split)
		return (0);
	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			split[words] = malloc(sizeof(char) * ft_lenword(s, c, i) + 1);
			if (!split[words])
				return (ft_free_split(split));
			i = ft_copy(split[words++], s, c, i);
		}
	}
	split[words] = 0;
	return (split);
}
