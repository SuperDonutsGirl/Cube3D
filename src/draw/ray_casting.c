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

void	update_data_ray(float *ray, float *o, int *dof)
{
	ray[X] += o[X];
	ray[Y] += o[Y];
	dof[0] += 1;
}

void	get_ray_value(t_struct *data, float *data_ray, float *ray, int *dof)
{
	data_ray[X] = ray[X];
	data_ray[Y] = ray[Y];
	data_ray[DIST] = dist(data->cube->player.px, data->cube->player.py,
			data_ray[X], data_ray[Y]);
	dof[0] = dof[1];
}

float	*get_data_ray(t_struct *data, float *data_ray, float ra, int type)
{
	int		*dof;
	float	ray[2];
	float	o[2];
	int		m[2];

	data_ray = malloc(sizeof(float) * 3);
	data_ray[X] = data->cube->player.px;
	data_ray[Y] = data->cube->player.py;
	data_ray[DIST] = 1000000;
	if (type == VERTICAL)
		dof = dof_vertical(data, ray, o, ra);
	else
		dof = dof_horizontal(data, ray, o, ra);
	while (dof[0] < dof[1])
	{
		m[Y] = ((int)ray[Y] >> 6);
		m[X] = ((int)ray[X] >> 6);
		if (m[Y] >= 0 && m[X] >= 0 && m[Y] < (int)data->height
			&& m[X] < (int)data->width && data->map[m[Y]][m[X]] == '1')
			get_ray_value(data, data_ray, ray, dof);
		else
			update_data_ray(ray, o, dof);
	}
	return (data_ray);
}

float	check_dist(float *ver, float *hor, float dist_t, float *ray)
{
	if (ver[DIST] < hor[DIST])
	{
		ray[X] = ver[X];
		ray[Y] = ver[Y];
		dist_t = ver[DIST];
	}
	else
	{
		ray[X] = hor[X];
		ray[Y] = hor[Y];
		dist_t = hor[DIST];
	}
	return (dist_t);
}

void	draw_rays(t_struct *data)
{
	int		r;
	float	ra;
	float	*ray;
	float	*hor;
	float	*ver;
	float dist_t;

	ray = malloc(sizeof(float) * 2);
	ra = data->cube->player.pa - DR * 30;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	r = 0;
	while (r < 60)
	{
		float	ca;
		float line_o;
		float line_h;

		hor = get_data_ray(data, hor, ra, HORIZONTAL);
		ver = get_data_ray(data, ver, ra, VERTICAL);
		dist_t = check_dist(ver, hor, dist_t, ray);
		if (dist_t < 20)
		{
			if (data->key.s == 1)
			{
				data->cube->player.px += data->cube->player.pdx * MOVE_SPEED;
				data->cube->player.py += data->cube->player.pdy * MOVE_SPEED;
			}
			if (data->key.w == 1)
			{
				data->cube->player.px -= data->cube->player.pdx * MOVE_SPEED;	
				data->cube->player.py -= data->cube->player.pdy * MOVE_SPEED;
			}
		}
		ca = data->cube->player.pa - ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		dist_t = dist_t * cos(ca);
		line_h = data->map_s * 320 / dist_t;
		line_o = 160 - line_h / 2;
		bresenham3d(data, r * 8 + 530, line_o, r * 8 + 530, 0, data->color[CEILING]);
		bresenham3d(data, r * 8 + 530, line_o, r * 8 + 530, line_h + line_o, 0xFF0000);
		bresenham3d(data, r * 8 + 530, line_h + line_o, r * 8 + 530, 512, data->color[FLOOR]);
		ra += DR;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
		r++;
	}

}
