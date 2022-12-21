/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:54:41 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/07 21:54:43 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	*ft_realloc_int(int *tab, int len_tab, int add_len)
{
	int	*new_tab;
	int	i;

	if (len_tab == 0)
		len_tab++;
	new_tab = malloc(sizeof(int) * (len_tab + add_len));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (i < len_tab)
	{
		new_tab[i] = tab[i];
		i++;
	}
	free(tab);
	return (new_tab);
}

char	**ft_realloc_one(char **old, int len, char *new_line)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	ft_free_split(old);
	new[i] = ft_strdup(new_line);
	free(new_line);
	new[++i] = 0;
	return (new);
}

char	*realloc_set(char *line, int new_len, char charset)
{
	char	*new_line;

	new_line = malloc(sizeof(char) * new_len + 1);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	ft_strcpy_complete(new_line, line, charset, new_len);
	return (new_line);
}
