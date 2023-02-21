/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:14:30 by pamartin          #+#    #+#             */
/*   Updated: 2023/02/21 16:14:31 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

float	update_angle(float angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

void	update_data_ray(float *ray, float *o, int *dof)
{
	ray[X] += o[X];
	ray[Y] += o[Y];
	dof[0] += 1;
}

void	get_ray_value(t_struct *data, t_ray *ray, int *dof, int type)
{
	if (type == HORIZONTAL)
	{
		ray->hor[X] = ray->r[X];
		ray->hor[Y] = ray->r[Y];
		ray->hor[DIST] = dist(data->cube->player.px, data->cube->player.py,
				ray->r[X], ray->r[Y]);
		if ((int)ray->r[Y] % 2 == 1)
			ray->texture[HORIZONTAL] = data->cube->tex[1];
		else
			ray->texture[HORIZONTAL] = data->cube->tex[0];
	}
	else
	{
		ray->ver[X] = ray->r[X];
		ray->ver[Y] = ray->r[Y];
		ray->ver[DIST] = dist(data->cube->player.px, data->cube->player.py,
				ray->r[X], ray->r[Y]);
		if ((int)ray->r[X] % 2 == 1)
			ray->texture[VERTICAL] = data->cube->tex[3];
		else
			ray->texture[VERTICAL] = data->cube->tex[2];
	}
	dof[0] = dof[1];
}

int	is_wall(t_struct *data, float x, float y)
{
	int		m[2];

	m[Y] = ((int)y >> 6);
	m[X] = ((int)x >> 6);
	if (m[Y] >= 0 && m[X] >= 0 && m[Y] < (int)data->height
		&& m[X] < (int)data->width && data->map[m[Y]][m[X]] == '1')
		return (1);
	return (0);
}
