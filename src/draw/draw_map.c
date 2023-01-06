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

	dst = cube->address + (y * cube->line_length + x
			* (cube->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color)
// {
// 	int	pix;

// 	pix = (x * cube->bits_per_pixel / 8) + (y * cube->line_length);
// 	cube->address[pix] = color;
// 	cube->address[pix + 1] = color >> 8;
// 	cube->address[pix + 2] = color >> 16;
// }

static void	draw_element(t_struct *data, int color, int *pos, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i + pos[X] % size == 0)
				my_mlx_pixel_put(data->cube, i + pos[X], j + pos[Y], 0xFFFFFF);
			else if (j + pos[Y] % size == 0)
				my_mlx_pixel_put(data->cube, i + pos[X], j + pos[Y], 0xFFFFFF);
			else
				my_mlx_pixel_put(data->cube, i + pos[X], j + pos[Y], color);
			j++;
		}
		i++;
	}
}

static void	put_elements(t_struct *data, int *pos, size_t x, size_t y)
{
	if (data->map[y][x] == '1')
		draw_element(data, 0x545650, pos, data->map_s);
	else if (data->map[y][x] == '0')
		draw_element(data, 0xC5C8BD, pos, data->map_s);
	else
	{
		if (data->map[y][x] == 'S' || data->map[y][x] == 'N'
			|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			draw_element(data, 0x0000FF, pos, data->map_s);
		else
			draw_element(data, 0x00FF00, pos, data->map_s);
	}
}

void	draw_map_2d(t_struct *data)
{
	size_t	x;
	size_t	y;
	int		pos[2];

	pos[X] = 0;
	pos[Y] = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			put_elements(data, pos, x, y);
			pos[X] += data->map_s;
			x++;
		}
		pos[Y] += data->map_s;
		pos[X] = 0;
		y++;
	}
		mlx_put_image_to_window(data->cube->mlx, data->cube->window,
			data->cube->img, 0, 0);
}
