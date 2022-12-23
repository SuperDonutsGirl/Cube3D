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

#include "../../includes/cub3d.h"

void	draw_player(t_cube *cube, int color, int x_size, int y_size)
{
	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
			mlx_pixel_put(cube->mlx, cube->window, j + cube->player.px, i + cube->player.py, color);
	}
}

void	drawline(t_cube *cube, int color, float x_max, float y_max)
{
		float x,y,x1,y1,dx,dy,step;
		int i;

		x1 = cube->player.px + 4;
		y1 = cube->player.py + 4;
		color++;
		dx = cube->player.pdx * 5;
		dy = cube->player.pdy * 5;
		step = 35; //PLus la valeur est basse, plus les pixels seront espacés
		dx = dx / step;
		dy = dy / step;
		x = x1;
		y = y1;
		i = 1;
		while(i <= 1144 && (x <= x_max || y <= y_max))
		{
		/*	printf("X : %f\nY : %f\nX_MAX : %d\nY_MAX : %d\n", x, y, x_max, y_max);*/
			mlx_pixel_put(cube->mlx, cube->window, x,y, 0xFF0000);
			x = x + dx;
			y = y + dy;
			i++;
		}
}

void	draw_rays(t_cube *cube, int *map)
{
	int r, mx, my, mp, dof;
	float rx, ry, ra, xo, yo;

	ra = cube->player.pa;
	for (r = 0; r < 1; r++)
	{
		dof = 0;
		float aTan = -1 / tan(ra);
		if (ra > PI)
		{
			ry = (((int) cube->player.py >> 6) << 6) - 0.0001;
			rx = (cube->player.py - ry) * aTan + cube->player.px;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < PI)
		{
			ry = (((int) cube->player.py >> 6) << 6) + 64;
			rx = (cube->player.py - ry) * aTan + cube->player.px;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = cube->player.px;
			ry = cube->player.py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
			mp = my * 8 + mx;
			drawline(cube, *map, rx, ry);
			if (mp < 8 * 8 && map[mp] == 1)
			{
				dof = 8;
				mlx_string_put(cube->mlx, cube->window, rx, ry, 0x0000FF, "X");
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
	}
}
