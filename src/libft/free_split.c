/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:52:04 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/11 22:52:14 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_clear_split(char **split)
{
	unsigned int	i;

	i = 0;
	if (!split)
		return (NULL);
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	return (NULL);
}

void	*ft_free_split(char **split)
{
	if (split)
	{
		ft_clear_split(split);
		free(split);
	}
	return (NULL);
}
