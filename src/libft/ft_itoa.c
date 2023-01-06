/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:34:58 by pamartin          #+#    #+#             */
/*   Updated: 2022/10/06 14:06:08 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i++;
	}
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		i;
	long	nb;

	nb = n;
	i = ft_intlen(nb);
	itoa = (char *)malloc(sizeof(char) * i + 1);
	if (!itoa)
		return (0);
	itoa[i] = '\0';
	if (nb < 0)
	{
		itoa[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		itoa[0] = '0';
	while (nb > 0)
	{
		i--;
		itoa[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (itoa);
}
