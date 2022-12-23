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

void	drawline(t_cube *cube, int color, float x_col, float y_col)
{
		float x,y,x1,y1,dx,dy,step;
		int i;
		x1 = cube->player.px + 4;
		y1 = cube->player.py + 4;

		dx = cube->player.pdx * 5;
		dy = cube->player.pdy * 5;
		step = 100; //PLus la valeur est basse, plus les pixels seront espacés
		dx = dx / step;
		dy = dy / step;
		x = x1;
		y = y1;
		i = 1;
		
		printf("x     = %f\nx_col = %f\n", x, x_col);
		printf("y     = %f\ny_col = %f\n\n\n", y, y_col);
		if (y > y_col)
		{
			while(i <= 150000 &&  y-y_col > 0 && x_col)
			{
				mlx_pixel_put(cube->mlx, cube->window, x,y, color);
			// mlx_string_put(cube->mlx, cube->window, 550, 10, 0xFF0000, ft_itoa((int)x));
			// mlx_string_put(cube->mlx, cube->window, 550, 50, 0xFF0000, ft_itoa((int)x_col));
			// mlx_string_put(cube->mlx, cube->window, 550, 90, 0xFF0000, ft_itoa((int)y));
			// mlx_string_put(cube->mlx, cube->window, 550, 130, 0xFF0000, ft_itoa((int)y_col));

			//printf("y = %f\n avec y_col = %f\n ", y, y_col);
			x = x + dx;
			y = y + dy;
			i++;
			}
		}
		else if (y < y_col)
		{
			while(i <= 150000 && y_col-y > 0  && x_col)
			{
				mlx_pixel_put(cube->mlx, cube->window, x,y, color);
			// mlx_string_put(cube->mlx, cube->window, 550, 10, 0xFF0000, ft_itoa((int)x));
			// mlx_string_put(cube->mlx, cube->window, 550, 50, 0xFF0000, ft_itoa((int)x_col));
			// mlx_string_put(cube->mlx, cube->window, 550, 90, 0xFF0000, ft_itoa((int)y));
			// mlx_string_put(cube->mlx, cube->window, 550, 130, 0xFF0000, ft_itoa((int)y_col));

			//printf("y = %f\n avec y_col = %f\n ", y, y_col);
				x = x + dx;
				y = y + dy;
				i++;
			}
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
			drawline(cube, 16711680, rx, ry);

			//drawline(cube, 16711680, mx, my);
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
			mp = my * 8 + mx;
			if (mp < 8 * 8 && map[mp] == 1)
			{
				dof = 8;
				//printf("Je touche une ligne sur X\n");
				mlx_string_put(cube->mlx, cube->window, rx, ry, 0xFF0000, "ICI");
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
