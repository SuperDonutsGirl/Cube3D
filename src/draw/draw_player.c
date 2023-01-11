/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:41:39 by dduraku           #+#    #+#             */
/*   Updated: 2022/12/16 15:41:40 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	draw_player(t_struct *data, int color, int size_player)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_player)
	{
		j = 0;
		while (j < size_player)
		{
			my_mlx_pixel_put(data->cube, j + data->cube->player.px, i + data->cube->player.py, color);
			j++;
		}
		i++;
	}
}

void	draw_player_mini(t_struct *data, int color, int size_player, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_player)
	{
		j = 0;
		while (j < size_player)
		{
			//my_mlx_pixel_put(data->cube, j + data->cube->mini.px - data->mini_s, i + data->cube->mini.py - data->mini_s, color);
			my_mlx_pixel_put(data->cube, j + data->cube->mini.px - data->mini_s * x - data->mini_s, i + data->cube->mini.py - data->mini_s * y - data->mini_s, color);
			j++;
		}
		i++;
	}
}