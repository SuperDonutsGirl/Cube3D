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

static void	draw_orientation_player(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			j++;
			mlx_pixel_put(cube->mlx, cube->window,
				j + cube->player.px + cube->player.pdx * 5,
				i + cube->player.py + cube->player.pdy * 5, 0x000000);
		}
		i++;
	}
}

void	draw_player(t_struct *data, int color, int size_player)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_player)
	{
		i++;
		j = 0;
		while (j < size_player)
		{
			mlx_pixel_put(data->cube->mlx, data->cube->window, j + data->cube->player.px,
				i + data->cube->player.py, color);
			j++;
		}
	}
	draw_orientation_player(data->cube);
}

float	dist(float ax, float ay, float bx, float by)
{
	float	dist;

	dist = sqrtf((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
	return (dist);
}

//void	draw_rays(t_struct *data)
//{
//	int r, mx, my, mp, dof;
//	float rx, ry, ra, xo, yo;
//
//	ra = data->cube->player.pa - DR * 360;
//    if (ra < 0)
//        ra += 2 * PI;
//    if (ra > 2 * PI)
//        ra -= 2 * PI;
//	for (r = 0; r < 360; r++)
//	{
//        //----------------HORIZONTALES----------------
//		dof = 0;
//        float disH = 1000000, hx = data->cube->player.px, hy = data->cube->player.py;
//		float aTan = -1 / tan(ra);
//		if (ra > PI)
//		{
//			ry = (((int) data->cube->player.py >> 6) << 6) - 0.0001;
//			rx = (data->cube->player.py - ry) * aTan + data->cube->player.px;
//			yo = -64;
//			xo = -yo * aTan;
//		}
//		if (ra < PI)
//		{
//			ry = (((int) data->cube->player.py >> 6) << 6) + 64;
//			rx = (data->cube->player.py - ry) * aTan + data->cube->player.px;
//			yo = 64;
//			xo = -yo * aTan;
//		}
//		if (ra == 0 || ra == PI)
//		{
//			rx = data->cube->player.px;
//			ry = data->cube->player.py;
//			dof = 8;
//		}
//		while (dof < 8)
//		{
//			mx = (int) (rx) >> 6;
//			my = (int) (ry) >> 6;
//			mp = my * 8 + mx;
//			if (mp > 0 && mp < 8 * 8 && map[mp] == 1)
//			{
//                hx = rx;
//                hy = ry;
//                disH = dist(data->cube->player.px, data->cube->player.py, hx, hy);
//				dof = 8;
//			}
//			else
//			{
//				rx += xo;
//				ry += yo;
//				dof += 1;
//			}
//		}
//        //----------------VERTICALES
//        dof = 0;
//        float disV = 1000000, vx = data->cube->player.px, vy = data->cube->player.py;
//		float nTan = -tan(ra);
//		if (ra > P2 && ra < P3)
//		{
//			rx = (((int) data->cube->player.px >> 6) << 6) - 0.0001;
//			ry = (data->cube->player.px - rx) * nTan + data->cube->player.py;
//			xo = -64;
//			yo = -xo * nTan;
//		}
//		if (ra < P2 || ra > P3)
//		{
//			rx = (((int) data->cube->player.px >> 6) << 6) + 64;
//			ry = (data->cube->player.px - rx) * nTan + data->cube->player.py;
//			xo = 64;
//			yo = -xo * nTan;
//		}
//		if (ra == 0 || ra == PI)
//		{
//			rx = data->cube->player.px;
//			ry = data->cube->player.py;
//			dof = 8;
//		}
//		while (dof < 8)
//		{
//			mx = (int) (rx) >> 6;
//			my = (int) (ry) >> 6;
//			mp = my * 8 + mx;
//			if (mp > 0 && mp < 8 * 8 && map[mp] == 1)
//			{
//                vx = rx;
//                vy = ry;
//                disV = dist(data->cube->player.px, data->cube->player.py, vx, vy);
//				dof = 8;
//			}
//			else
//			{
//				rx += xo;
//				ry += yo;
//				dof += 1;
//			}
//		}
//        if (disV < disH)
//        {
//            rx = vx;
//            ry = vy;
//        }
//        if (disH < disV)
//        {
//            rx = hx;
//            ry = hy;
//        }
//        mlx_string_put(data->cube->mlx, data->cube->window, rx, ry, 0xFF0000, ".");
//        ra += DR;
//        if (ra < 0)
//            ra += 2 * PI;
//        if (ra > 2 * PI)
//            ra -= 2 * PI;
//	}
//}
