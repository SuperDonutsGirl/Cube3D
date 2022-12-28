/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:10:03 by dduraku           #+#    #+#             */
/*   Updated: 2022/09/28 17:10:07 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spacesigne(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	return (i);
}

unsigned long int	ft_long_atoi(const char *str)
{
	long		nb;
	int			i;

	if (!str)
		return (0);
	nb = 0;
	i = ft_spacesigne(str);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
		if (nb > LONG_MAX)
			return (2);
	}
	return (nb);
}
