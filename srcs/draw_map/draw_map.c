/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:16:20 by dduraku           #+#    #+#             */
/*   Updated: 2022/12/16 15:16:22 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color)
{
	char	*dst;

	dst = cube->address + (y * cube->line_length + x * (cube->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_player(t_cube *cube, int color, int x_size, int y_size)
{
	for (int i = 0; i < y_size; i++) {
		for (int j = 0; j < x_size; j++)
			mlx_pixel_put(cube->mlx, cube->window, j + cube->pos_x, i + cube->pos_y, color);
	}
}

void	draw_walls(t_cube *cube, int color, int x_size, int y_size, int pos_x, int pos_y)
{
	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
			my_mlx_pixel_put(cube, i + pos_x, j + pos_y, color);
	}
}

void	draw_map_2D(t_cube *cube, int color_floor, int color_wall, int *map)
{
	int mapX = 8, mapY = 8, mapS = 64;
	int pos_x = 0, pos_y = 0;
	int x, y;
	for (y = 0; y < mapY; y++)
	{
		for (x = 0; x < mapX; x++)
		{
			if (map[y * mapX + x] == 1)
				draw_walls(cube, color_wall, mapS, mapS, pos_x, pos_y);
			else
				draw_walls(cube, color_floor, mapS, mapS, pos_x, pos_y);
			pos_x += 64;
		}
		pos_y += 64;
		pos_x = 0;
		mlx_put_image_to_window(cube->mlx, cube->window, cube->img, 0, 0);
	}
}
