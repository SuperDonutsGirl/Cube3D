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

// void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = cube->address + (y * cube->line_length + x
// 			* (cube->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color)
{
	int	pix;

	pix = (x * cube->bits_per_pixel / 8) + (y * cube->line_length);
	cube->address[pix] = color;
	cube->address[pix + 1] = color >> 8;
	cube->address[pix + 2] = color >> 16;
}

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
			{
				//if (i + pos[X] < (data->width * data->map_s ) / 2&& j + pos[Y] < (data->height * data->map_s) / 2)
				my_mlx_pixel_put(data->cube, i + pos[X], j + pos[Y], 0xFFFFFF);
			}
			else if (j + pos[Y] % size == 0)
			{
				//if (i + pos[X] < (data->width * data->map_s ) / 2&& j + pos[Y] < (data->height * data->map_s) / 2)
				my_mlx_pixel_put(data->cube, i + pos[X], j + pos[Y], 0xFFFFFF);
			}
			else
			{
				//if (i + pos[X] < (data->width * data->map_s ) / 2&& j + pos[Y] < (data->height * data->map_s) / 2)
					my_mlx_pixel_put(data->cube, i + pos[X], j + pos[Y], color);
			}
			j++;
		}
		i++;
	}
}

static void	put_elements(t_struct *data, int *pos, size_t x, size_t y, size_t size)
{
	if (data->map[y][x] == '1')
		draw_element(data, 0x545650, pos, size);
	else if (data->map[y][x] == '0')
		draw_element(data, 0xC5C8BD, pos, size);
	else
	{
		if (data->map[y][x] == 'S' || data->map[y][x] == 'N'
			|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			draw_element(data, 0x0000FF, pos, size);
		else
			draw_element(data, 0x00FF00, pos, size);
	}
}

size_t	find_max(size_t player)
{
	size_t	max;

	max = 0;
	while (max < 8)
	{
		player++;
		max++;
	}
	return (max);
}
void	draw_mini_map(t_struct *data)
{
	float	x;
	float	y;
	float	player[2];
	float	center[2];
	int		center_player[2];
	int		pos[2];

	pos[X] = 0;
	pos[Y] = 0;
	player[X] = (data->cube->player.px - 28) / data->map_s;
	player[Y] = (data->cube->player.py - 28) / data->map_s;

	if (player[X] > 4)
	{
		center[X] = player[X] - 4;
		center_player[X] = 5;
	}
	else
	{
		center[X] = 0;
		center_player[X] = 0;
	}
	if (player[Y] > 4)
	{
		center[Y] = player[Y] - 4;
		center_player[Y] = 5;
	}
	else
	{
		center[Y] = 0;
		center_player[Y] = 0;
	}
	
	


	y = center[Y];
	while (y < center[Y] + 8)
	{
		x = center[X];
		while (x < center[X] + 8)
		{
			put_elements(data, pos, x, y, data->mini_s);
			if (data->map[(size_t)y][(size_t)x] == 'S')
				printf("carré perso commence a x = %f et y = %f\n", x, y);
			pos[X] += data->mini_s;
			x++;
		}
		pos[Y] += data->mini_s;
		pos[X] = 0;
		y++;
	}
	printf("xplayer -map            = %f\n", data->cube->player.px);
	printf("xplayer -mini           = %f\n", player[X]);
	printf("player position x       = %f\n\n", data->player[2]);
	printf("yplayer -map            = %f\n", data->cube->player.py);
	printf("yplayer -mini           = %f\n", player[Y]);
	printf("player position y       = %f\n\n\n\n", data->player[1]);
	float	i;
	float	j;


	i = center[Y];
	while (i < center[Y] + 8)
	{
		i++;
		j = center[X];
		while (j < center[X] + 8)
		{
			mlx_pixel_put(data->cube->mlx, data->cube->window, (j + player[X] * data->mini_s) - (center[X] * data->mini_s) - center_player[X] + 12,
				(i + player[Y] * data->mini_s) - (center[Y] * data->mini_s) - center_player[Y] + 12, 0xFF0053);
			//quid du +16
			j++;
		}
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
			// if (x < 4 && y < 4)
			// {
			// 	draw_mini_map(data);
			// }
			// else
				put_elements(data, pos, x, y, data->map_s);
			pos[X] += data->map_s;
			x++;
		}
		pos[Y] += data->map_s;
		pos[X] = 0;
		mlx_put_image_to_window(data->cube->mlx, data->cube->window,
			data->cube->img, 0, 0);
		y++;
	}
}
