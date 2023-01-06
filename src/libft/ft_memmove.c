/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:20:25 by pamartin          #+#    #+#             */
/*   Updated: 2022/10/06 14:06:17 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*my_memcpy(void *dst, const void *src, size_t n)
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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_tempo;
	char	*src_tempo;

	dst_tempo = (char *)dst;
	src_tempo = (char *)src;
	if (!dst && !src)
		return (0);
	if (src > dst)
		my_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			dst_tempo[len - 1] = src_tempo[len - 1];
			len--;
		}
	}
	return (dst);
}
