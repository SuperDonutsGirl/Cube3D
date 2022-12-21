/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:27:13 by pamartin          #+#    #+#             */
/*   Updated: 2021/11/30 22:47:15 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_check_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && ft_check_charset(charset, str[i]) == 1)
			i++;
		else
		{
			words++;
			while (str[i] && ft_check_charset(charset, str[i]) == 0)
				i++;
		}
	}
	return (words);
}

static int	len_set(char *charset, char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_check_charset(charset, str[i]) == 0)
		i++;
	return (i);
}

int	ft_copy(char *dest, char *str, char *charset, int i)
{
	int	j;

	j = 0;
	while (str[i] && ft_check_charset(charset, str[i]) != 1)
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (i);
}

char	**ft_split_charset(char *str, char *set)
{
	char	**matrice;
	int		words;
	int		i;

	words = ft_count_words(str, set);
	matrice = malloc(sizeof(char *) * (words + 1));
	if (!matrice)
		return (NULL);
	words = 0;
	i = 0;
	while (str[i])
	{
		if (ft_check_charset(set, str[i]) == 1)
			i++;
		else
		{
			matrice[words] = malloc(sizeof(char) * len_set(set, &str[i]) + 1);
			if (!matrice[words])
				return (ft_free_split(matrice));
			i = ft_copy(matrice[words], str, set, i);
			words++;
		}
	}
	matrice[words] = 0;
	return (matrice);
}
