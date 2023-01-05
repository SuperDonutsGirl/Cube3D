/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:06:40 by pamartin          #+#    #+#             */
/*   Updated: 2023/01/05 18:06:41 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	update_data(t_struct *data, float *ray)
{
	ray[X] = data->cube->player.px;
	ray[Y] = data->cube->player.py;
	return (data->height * data->width);
}

static int	check_ra_horizontal(t_struct *data, float *ray, float *o, float ra)
{
	int		dof;
	float	tang;

	dof = 0;
	tang = -1 / tan(ra);
	if (ra > PI)
	{
		ray[Y] = (((int)data->cube->player.py >> 6) << 6) - 0.0001;
		ray[X] = (data->cube->player.py - ray[Y]) * tang
			+ data->cube->player.px;
		o[Y] = -data->map_s;
		o[X] = -o[Y] * tang;
	}
	if (ra < PI)
	{
		ray[Y] = (((int) data->cube->player.py >> 6) << 6) + data->map_s;
		ray[X] = (data->cube->player.py - ray[Y]) * tang
			+ data->cube->player.px;
		o[Y] = data->map_s;
		o[X] = -o[Y] * tang;
	}
	if (ra == 0 || ra == PI)
		dof = update_data(data, ray);
	return (dof);
}

static int	check_ra_vertical(t_struct *data, float *ray, float *o, float ra)
{
	int		dof;
	float	tang;

	dof = 0;
	tang = -tan(ra);
	if (ra > P2 && ra < P3)
	{
		ray[X] = (((int)data->cube->player.px >> 6) << 6) - 0.0001;
		ray[Y] = (data->cube->player.px - ray[X]) * tang
			+ data->cube->player.py;
		o[X] = -data->map_s;
		o[Y] = -o[X] * tang;
	}
	if (ra < P2 || ra > P3)
	{
		ray[X] = (((int) data->cube->player.px >> 6) << 6) + data->map_s;
		ray[Y] = (data->cube->player.px - ray[X]) * tang
			+ data->cube->player.py;
		o[X] = data->map_s;
		o[Y] = -o[X] * tang;
	}
	if (ra == 0 || ra == PI)
		dof = update_data(data, ray);
	return (dof);
}

int	*dof_vertical(t_struct *data, float *ray, float *o, float ra)
{
	int	*dof;

	dof = malloc(sizeof(int) * 2);
	dof[0] = check_ra_vertical(data, ray, o, ra);
	dof[1] = data->width;
	return (dof);
}

int	*dof_horizontal(t_struct *data, float *ray, float *o, float ra)
{
	int	*dof;

	dof = malloc(sizeof(int) * 2);
	dof[0] = check_ra_horizontal(data, ray, o, ra);
	dof[1] = data->height;
	return (dof);
}
