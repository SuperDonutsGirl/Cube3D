/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 01:11:42 by pamartin          #+#    #+#             */
/*   Updated: 2021/12/28 01:11:44 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_tempo;
	char	*src_tempo;
	size_t	i;

	if (!dst && !src)
		return (0);
	dst_tempo = (char *)dst;
	src_tempo = (char *)src;
	i = 0;
	while (i < n)
	{
		dst_tempo[i] = src_tempo[i];
		i++;
	}
	return (dst);
}
