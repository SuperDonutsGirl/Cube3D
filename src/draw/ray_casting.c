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

void	collision(t_struct *data)
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

float	update_angle(float angle)
{
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

void	update_data_ray(float *ray, float *o, int *dof)
{
	ray[X] += o[X];
	ray[Y] += o[Y];
	dof[0] += 1;
}

void	get_ray_value(t_struct *data, t_ray ray, int *dof, int type)
{
	if (type == HORIZONTAL)
	{
		ray.hor[X] = ray.r[X];
		ray.hor[Y] = ray.r[Y];
		ray.hor[DIST] = dist(data->cube->player.px, data->cube->player.py,
			ray.r[X], ray.r[Y]);
		if ((int)ray.r[Y] % 2 == 1)
			ray.hor[COLOR] = 0xFF0000;
		else
			ray.hor[COLOR] = 0x00FF00;
	}
	else
	{
		ray.ver[X] = ray.r[X];
		ray.ver[Y] = ray.r[Y];
		ray.ver[DIST] = dist(data->cube->player.px, data->cube->player.py,
			ray.r[X], ray.r[Y]);
		if ((int)ray.r[X] % 2 == 1)
			ray.ver[COLOR] = 0x0000FF;
		else
			ray.ver[COLOR] = 0xBB39EB;
	}
	dof[0] = dof[1];
}

float	*get_data_ray(t_struct *data, t_ray ray, int type)
{
	int		*dof;
	float	o[2];
	int		m[2];

	if (type == VERTICAL)
	{
		ray.ver = malloc(sizeof(float) * 4);
		ray.ver[X] = data->cube->player.px;
		ray.ver[Y] = data->cube->player.py;
		ray.ver[DIST] = 1000000;
		dof = dof_vertical(data, ray.r, o, ray.ra);
	}
	else
	{
		ray.hor = malloc(sizeof(float) * 4);
		ray.hor[X] = data->cube->player.px;
		ray.hor[Y] = data->cube->player.py;
		ray.hor[DIST] = 1000000;
		dof = dof_horizontal(data, ray.r, o, ray.ra);
	}
	while (dof[0] < dof[1])
	{
		m[Y] = ((int)ray.r[Y] >> 6);
		m[X] = ((int)ray.r[X] >> 6);
		if (m[Y] >= 0 && m[X] >= 0 && m[Y] < (int)data->height
			&& m[X] < (int)data->width && data->map[m[Y]][m[X]] == '1')
				get_ray_value(data, ray, dof, type);
		else
			update_data_ray(ray.r, o, dof);
	}
	if (type == HORIZONTAL)
		return (ray.hor);
	else
		return (ray.ver);
}

float	check_dist(t_ray ray)
{
	if (ray.ver[DIST] < ray.hor[DIST])
	{
		ray.r[X] = ray.ver[X];
		ray.r[Y] = ray.ver[Y];
		ray.dist = ray.ver[DIST];
		ray.r[COLOR] = ray.ver[COLOR];
	}
	else
	{
		ray.r[X] = ray.hor[X];
		ray.r[Y] = ray.hor[Y];
		ray.dist = ray.hor[DIST];
		ray.r[COLOR] = ray.hor[COLOR];
	}
	return (ray.dist);
}

void	draw_rays(t_struct *data)
{
	int			i;
	t_ray		ray;

	ray.r = malloc(sizeof(float) * 3);
	//protection
	ray.ra = data->cube->player.pa - DR * 30;
	ray.ra = update_angle(ray.ra);
	i = 0;
	while (i < 60)
	{
		ray.hor = get_data_ray(data, ray, HORIZONTAL);
		ray.ver = get_data_ray(data, ray, VERTICAL);
		ray.dist = check_dist(ray);
		if (ray.dist < 20)
			collision(data);
		ray.ca = data->cube->player.pa - ray.ra;
		ray.ca = update_angle(ray.ca);
		ray.dist = ray.dist * cos(ray.ca);
		ray.line_h = data->map_s * 320 / ray.dist;
		ray.line_o = 160 - ray.line_h / 2;
		draw_cwf(data, i, ray);
		ray.ra += DR;
		ray.ra = update_angle(ray.ra);
		i++;
	}
}
