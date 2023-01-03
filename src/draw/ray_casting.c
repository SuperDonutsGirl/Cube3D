/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:00:13 by pamartin          #+#    #+#             */
/*   Updated: 2023/01/03 17:00:15 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"


float	dist(float ax, float ay, float bx, float by)
{
	float	dist;

	dist = sqrtf((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
	return (dist);
}

int	check_ra_horizontal(t_struct *data, float *ray, float *o, float ra, float tang)
{
	int	dof;

	dof = 0;
if (ra > PI)
	{
		ray[Y] = (((int)data->cube->player.py >> 6) << 6) - 0.0001;
		ray[X] = (data->cube->player.py - ray[Y]) * tang + data->cube->player.px;
		o[Y] = -data->map_s;
		o[X] = -o[Y] * tang;
	}
	if (ra < PI)
	{
		ray[Y] = (((int) data->cube->player.py >> 6) << 6) + data->map_s;
		ray[X] = (data->cube->player.py - ray[Y]) * tang + data->cube->player.px;
		o[Y] = data->map_s;
		o[X] = -o[Y] * tang;
	}
	if (ra == 0 || ra == PI)
	{
		ray[X] = data->cube->player.px;
		ray[Y] = data->cube->player.py;
		dof = 8;
	}
	return (dof);
}

int	check_ra_vertical(t_struct *data, float *ray, float *o, float ra, float tang)
{
	int	dof;

	dof = 0;
	if (ra > P2 && ra < P3)
	{
		ray[X] = (((int)data->cube->player.px >> 6) << 6) - 0.0001;
		ray[Y] = (data->cube->player.px - ray[X]) * tang + data->cube->player.py;
		o[X] = -data->map_s;
		o[Y] = -o[X] * tang;
	}
	if (ra < P2 || ra > P3)
	{
		ray[X] = (((int) data->cube->player.px >> 6) << 6) + data->map_s;
		ray[Y] = (data->cube->player.px - ray[X]) * tang + data->cube->player.py;
		o[X] = data->map_s;
		o[Y] = -o[X] * tang;
	}
	if (ra == 0 || ra == PI)
	{
		ray[X] = data->cube->player.px;
		ray[Y] = data->cube->player.py;
		dof = 8;
	}
	return (dof);
}

float	*get_data_ray(t_struct *data, float *data_ray, float ra, int type)
{
	int		dof;
	int		m[2];
	float	ray[2];
	float	o[2];
	float	tang;

	data_ray = malloc(sizeof(float) * 3);
	dof = 0;
	data_ray[X] = data->cube->player.px;
	data_ray[Y] = data->cube->player.py;
	data_ray[DIST] = 1000000;
	if (type == VERTICAL)
	{
		tang = -tan(ra);
		dof = check_ra_vertical(data, ray, o, ra, tang);
	}
	else
	{
		tang = -1 / tan(ra);
		dof = check_ra_horizontal(data, ray, o, ra, tang);
	}
	while (dof < 8)
	{
		m[X] = (int)ray[X] >> 6;
		m[Y] = (int)ray[Y] >> 6;
		if (m[Y] >= 0 && m[X] >= 0 && m[Y] < (int)data->height && m[X] < (int)data->width && data->map[m[Y]][m[X]] == '1')
		{
			data_ray[X] = ray[X];
			data_ray[Y] = ray[Y];
			data_ray[DIST] = dist(data->cube->player.px, data->cube->player.py, data_ray[X], data_ray[Y]);
			dof = 8;
		}
		else
		{
			ray[X] += o[X];
			ray[Y] += o[Y];
			dof += 1;
		}
	}
	return (data_ray);
}

void	draw_rays(t_struct *data)
{
	int		r;
	float	rx;
	float	ry;
	float	ra;
	float	*hor;
	float	*ver;

	ra = data->cube->player.pa - DR * 360;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	r = 0;
	while (r < 380)
	{
		hor = get_data_ray(data, hor, ra, HORIZONTAL);
		ver = get_data_ray(data, ver,ra, VERTICAL);
		if (ver[DIST] < hor[DIST])
		{
			rx = ver[X];
			ry = ver[Y];
		}
		if (hor[DIST] < ver[DIST])
		{
			rx = hor[X];
			ry = hor[Y];
		}
		mlx_string_put(data->cube->mlx, data->cube->window, rx, ry, 0xFF0000, ".");
		ra += DR;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
		r++;
	}
}
