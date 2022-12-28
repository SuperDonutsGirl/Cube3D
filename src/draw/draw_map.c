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

#include "../../includes/cub.h"

void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color)
{
	char	*dst;

	dst = cube->address + (y * cube->line_length + x * (cube->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_walls(t_cube *cube, int color, int x_size, int y_size, int pos_x, int pos_y)
{
	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
		{
			if (i + pos_x % 64 == 0)
				my_mlx_pixel_put(cube, i + pos_x, j + pos_y, 0xFFFFFF);
			else if (j + pos_y % 64 == 0)
				my_mlx_pixel_put(cube, i + pos_x, j + pos_y, 0xFFFFFF);
			else
				my_mlx_pixel_put(cube, i + pos_x, j + pos_y, color);
		}

	}
}

void	draw_map_2D(t_struct *data, int color_floor, int color_wall)
{
	size_t mapS = 64;
	int	pos_x = 0, pos_y = 0;
	size_t x, y;
	for (y = 0; y < data->height; y++)
	{
		for (x = 0; x < data->width; x++)
		{
			if (data->map[y][x] == '1')
				draw_walls(data->cube, color_wall, mapS, mapS, pos_x, pos_y);
			else if (data->map[y][x] == '0')
				draw_walls(data->cube, color_floor, mapS, mapS, pos_x, pos_y);
			else
			{
				if (data->map[y][x] == 'S' || data->map[y][x] == 'N' || data->map[y][x] == 'E' || data->map[y][x] == 'W')
					draw_walls(data->cube, 0x0000FF, mapS, mapS, pos_x, pos_y);
				else
					draw_walls(data->cube, 0x00FF00, mapS, mapS, pos_x, pos_y);
			}
			pos_x += 64;
		}
		pos_y += 64;
		pos_x = 0;
		mlx_put_image_to_window(data->cube->mlx, data->cube->window, data->cube->img, 0, 0);
	}
}
