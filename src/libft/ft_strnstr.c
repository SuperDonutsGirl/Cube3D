/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:44:26 by pamartin          #+#    #+#             */
/*   Updated: 2022/10/06 14:06:44 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		y = 0;
		while ((haystack[i + y] == needle[y]) && (i + y) < len)
		{
			if (needle[y + 1] == '\0')
				return ((char *)(haystack + i));
			y++;
		}
		i++;
	}
	return (0);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		y = 0;
		while ((haystack[i + y] == needle[y]))
		{
			if (needle[y + 1] == '\0')
				return ((char *)(haystack + i));
			y++;
		}
		i++;
	}
	return (0);
}

int	ft_strpstr(const char *haystack, const char *needle)
{
	int	i;
	int	y;

	i = 0;
	if (needle[i] == '\0')
		return (-1);
	while (haystack[i])
	{
		y = 0;
		while ((haystack[i + y] == needle[y]))
		{
			if (needle[y + 1] == '\0')
				return (i - y);
			y++;
		}
		i++;
	}
	return (-1);
}

int	ft_strqstr(const char *haystack, const char *needle)
{
	int	i;
	int	y;

	i = 0;
	if (needle[i] == '\0')
		return (-1);
	while (haystack[i])
	{
		y = 0;
		while ((haystack[i + y] == needle[y]))
		{
			if (needle[y + 1] == '\0')
				return (i + y);
			y++;
		}
		i++;
	}
	return (-1);
}
