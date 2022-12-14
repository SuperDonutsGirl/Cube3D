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
