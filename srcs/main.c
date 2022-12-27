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

int	main(void)
{
	t_cube	*cube;
	int map[] =
			{
					1, 1, 1, 1, 1, 1, 1, 1,
					1, 0, 0, 1, 0, 0, 0, 1,
					1, 0, 0, 1, 1, 1, 0, 1,
					1, 0, 0, 0, 0, 0, 0, 1,
					1, 0, 0, 0, 0, 0, 0, 1,
					1, 0, 0, 0, 0, 0, 0, 1,
					1, 0, 0, 0, 0, 0, 0, 1,
					1, 1, 1, 1, 1, 1, 1, 1
			};
	cube = malloc(sizeof(t_cube));
	if (!cube)
		return 1;
	cube->player.px = 300;
	cube->player.py = 300;
	cube->player.pdx = cos(cube->player.pa) * 5;
	cube->player.pdy = sin(cube->player.pa) * 5;
	cube->mlx = mlx_init();
	cube->window = mlx_new_window(cube->mlx, 1024 /2, 512, "cub3d");
	cube->img = mlx_new_image(cube->mlx, 1024, 512);
	cube->address = mlx_get_data_addr(cube->img, &cube->bits_per_pixel,
									  	&cube->line_length, &cube->endian);
	draw_map_2D(cube, 0xC5C8BD, 0x545650, map);
	draw_player(cube, 0xFF0053, 10, 10);
	//drawline(cube, 0xFF0000);
	mlx_hook(cube->window, 3, 3, keyrelease, cube);
	mlx_hook(cube->window, 2, 1L<<0, keypress, cube);
	mlx_hook(cube->window, 17, 0L, close_on_click, cube);
	mlx_loop(cube->mlx);
}