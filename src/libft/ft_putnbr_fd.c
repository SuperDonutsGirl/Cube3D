/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:51:21 by pamartin          #+#    #+#             */
/*   Updated: 2021/12/28 00:51:23 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_div(int nb)
{
	int	i;

	i = 1;
	while (nb / 10 != 0)
	{
		i *= 10;
		nb = nb / 10;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	c;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	i = ft_div(n);
	while (i != 0)
	{
		c = (n / i) + 48;
		ft_putchar_fd(c, fd);
		n = n % i;
		i = i / 10;
	}
}
