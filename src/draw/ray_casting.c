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

float	*init_data_ray(t_struct *data, float *element)
{
	if (element)
		ft_free(element);
	element = malloc(sizeof(float) * 3);
	if (!element)
		exit(msg_error(MALLOC));
	element[X] = data->cube->player.px;
	element[Y] = data->cube->player.py;
	element[DIST] = 1000000;
	return (element);
}

float	*get_data_ray(t_struct *data, t_ray *ray, int type)
{
	int		*dof;
	float	o[2];

	if (type == VERTICAL)
	{
		ray->ver = init_data_ray(data, ray->ver);
		dof = dof_vertical(data, ray->r, o, ray->ra);
	}
	else
	{
		ray->hor = init_data_ray(data, ray->hor);
		dof = dof_horizontal(data, ray->r, o, ray->ra);
	}
	while (dof[0] < dof[1])
	{
		if (is_wall(data, ray->r[X], ray->r[Y]))
			get_ray_value(data, ray, dof, type);
		else
			update_data_ray(ray->r, o, dof);
	}
	ft_free(dof);
	if (type == HORIZONTAL)
		return (ray->hor);
	else
		return (ray->ver);
}

float	check_dist(t_ray *ray)
{
	if (ray->ver[DIST] < ray->hor[DIST])
	{
		ray->r[X] = ray->ver[X];
		ray->r[Y] = ray->ver[Y];
		ray->dist = ray->ver[DIST];
		ray->texture[RENDER_TEXT] = ray->texture[VERTICAL];
	}
	else
	{
		ray->r[X] = ray->hor[X];
		ray->r[Y] = ray->hor[Y];
		ray->dist = ray->hor[DIST];
		ray->texture[RENDER_TEXT] = ray->texture[HORIZONTAL];
	}
	return (ray->dist);
}

void	draw_rays(t_struct *data)
{
	int				i;
	static t_ray	ray;
	float			small;

	i = 0;
	small = -FOV / 2;
	ray.r = malloc(sizeof(float) * 3);
	if (!ray.r)
		exit(1);
	while (i < WIN_W)
	{
		ray.ra = data->cube->player.pa + atan(small);
		ray.ra = update_angle(ray.ra);
		ray.hor = get_data_ray(data, &ray, HORIZONTAL);
		ray.ver = get_data_ray(data, &ray, VERTICAL);
		ray.dist = check_dist(&ray);
		ray.ca = data->cube->player.pa - ray.ra;
		ray.ca = update_angle(ray.ca);
		ray.line_h = data->map_s * 320 / (ray.dist * cos(ray.ca));
		ray.line_o = 160 - ray.line_h / 2;
		data->cube->ray = &ray;
		draw_cwf(data, i, &ray);
		small += FOV / WIN_W;
		i++;
	}
	ft_free(ray.r);
}
