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

// static void	draw_orientation_player(t_cube *cube)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < 5)
// 	{
// 		j = 0;
// 		while (j < 5)
// 		{
// 			j++;
// 			my_mlx_pixel_put(cube, j  + cube->player.pdx * 15,
// 				i +  cube->player.pdy * 15, 0x000000);
// 			// mlx_pixel_put(cube->mlx, cube->window,
// 			// 	j + cube->player.px + cube->player.pdx * 5,
// 			// 	i + cube->player.py + cube->player.pdy * 5, 0x000000);
// 		}
// 		i++;
// 	}
// }

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
			//mlx_pixel_put(data->cube->mlx, data->cube->window,
			//	j + data->cube->player.px, i + data->cube->player.py, color);
			// mlx_pixel_put(data->cube->mlx, data->cube->window,
			// 	j + data->cube->player.px, i + data->cube->player.py, color);
			j++;
		}
		i++;
		// while (j < size_player)
		// {
		// 	my_mlx_pixel_put(data->cube, j + data->cube->mini.px - data->mini_s, i + data->cube->mini.py - data->mini_s, color);
		// 	// mlx_pixel_put(data->cube->mlx, data->cube->window,
		// 	// 	j + data->cube->player.px, i + data->cube->player.py, color);
		// 	j++;
		// }
		// i++;
	}
	//draw_orientation_player(data->cube);
	//draw_rays(data);
}
