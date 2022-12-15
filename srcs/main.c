/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:55:00 by dduraku           #+#    #+#             */
/*   Updated: 2022/12/15 13:55:01 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_player(t_cube *cube, int color, int x_size, int y_size)
{
	for (int i = 0; i < y_size; i++) {
		for (int j = 0; j < x_size; j++)
			mlx_pixel_put(cube->mlx, cube->window, j + cube->pos_x, i + cube->pos_y, color);
	}
}

int	move_player(int keycode, t_cube *cube)
{
	mlx_clear_window(cube->mlx, cube->window);
	if (keycode == 0)
		cube->pos_x -= 5;
	else if (keycode == 1)
		cube->pos_y += 5;
	else if (keycode == 2)
		cube->pos_x += 5;
	else if (keycode == 13)
		cube->pos_y -= 5;
	else
		printf("Keycode : %d\n", keycode);
	mlx_put_image_to_window(cube->mlx, cube->window, cube->img, 0, 0);
	draw_player(cube, 0xFF0053, 10, 10);
	return 0;
}

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

int	main(void)
{
	t_cube	*cube;
	int map[] =
			{
					1, 1, 1, 1, 1, 1, 1, 1,
					1, 0, 0, 0, 0, 0, 0, 1,
					1, 0, 0, 0, 0, 0, 0, 1,
					1, 0, 0, 0, 0, 0, 0, 1,
					1, 0, 0, 0, 0, 0, 0, 1,
					1, 0, 0, 0, 0, 0, 0, 1,
					1, 0, 0, 0, 0, 0, 0, 1,
					1, 1, 1, 1, 1, 1, 1, 1
			};

	cube = malloc(sizeof(t_cube));
	if (!cube)
		return 1;
	cube->pos_x = 50;
	cube->pos_y = 50;
	cube->mlx = mlx_init();
	cube->window = mlx_new_window(cube->mlx, 1024, 512, "cub3d");
	cube->img = mlx_new_image(cube->mlx, 1024, 512);
	cube->address = mlx_get_data_addr(cube->img, &cube->bits_per_pixel,
									  	&cube->line_length, &cube->endian);
	draw_map_2D(cube, 0x00FF00, 0x00FFFF, map);
	draw_player(cube, 0xFF0053, 10, 10);
	mlx_hook(cube->window, 3, 1L<<0, move_player, cube);
	mlx_hook(cube->window, 2, 1L<<0, keybinds, cube);
	mlx_hook(cube->window, 17, 0L, close_on_click, cube);
	mlx_loop(cube->mlx);
}
