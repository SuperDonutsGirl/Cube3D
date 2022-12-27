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

float   dist(float ax, float ay, float bx, float by)
{
    return (sqrtf((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	draw_rays(t_cube *cube, int *map)
{
	int r, mx, my, mp, dof;
	float rx, ry, ra, xo, yo;

	ra = cube->player.pa - DR * 360;
    if (ra < 0)
        ra += 2 * PI;
    if (ra > 2 * PI)
        ra -= 2 * PI;
	for (r = 0; r < 360; r++)
	{
        //----------------HORIZONTALES----------------
		dof = 0;
        float disH = 1000000, hx = cube->player.px, hy = cube->player.py;
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
			if (mp > 0 && mp < 8 * 8 && map[mp] == 1)
			{
                hx = rx;
                hy = ry;
                disH = dist(cube->player.px, cube->player.py, hx, hy);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
        //----------------VERTICALES
        dof = 0;
        float disV = 1000000, vx = cube->player.px, vy = cube->player.py;
		float nTan = -tan(ra);
		if (ra > P2 && ra < P3)
		{
			rx = (((int) cube->player.px >> 6) << 6) - 0.0001;
			ry = (cube->player.px - rx) * nTan + cube->player.py;
			xo = -64;
			yo = -xo * nTan;
		}
		if (ra < P2 || ra > P3)
		{
			rx = (((int) cube->player.px >> 6) << 6) + 64;
			ry = (cube->player.px - rx) * nTan + cube->player.py;
			xo = 64;
			yo = -xo * nTan;
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
			if (mp > 0 && mp < 8 * 8 && map[mp] == 1)
			{
                vx = rx;
                vy = ry;
                disV = dist(cube->player.px, cube->player.py, vx, vy);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
        if (disV < disH)
        {
            rx = vx;
            ry = vy;
        }
        if (disH < disV)
        {
            rx = hx;
            ry = hy;
        }
        mlx_string_put(cube->mlx, cube->window, rx, ry, 0xFF0000, ".");
        ra += DR;
        if (ra < 0)
            ra += 2 * PI;
        if (ra > 2 * PI)
            ra -= 2 * PI;
	}
}
