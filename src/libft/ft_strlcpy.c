/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 19:27:40 by pamartin          #+#    #+#             */
/*   Updated: 2021/12/31 19:27:42 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	y;

	if (!dst)
		return (NULL);
	y = 0;
	while (src[y] && y < (dstsize - 1))
	{
		dst[y] = src[y];
		y++;
	}
	dst[y] = '\0';
	return (dst);
}
