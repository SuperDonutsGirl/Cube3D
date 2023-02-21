/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:14:50 by pamartin          #+#    #+#             */
/*   Updated: 2023/02/21 16:14:51 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	update_draw(t_struct *data, float *draw, float t[2], t_ray *ray)
{
	float	wx;

	if (data->cube->ray->ver[DIST] > data->cube->ray->hor[DIST])
		wx = data->cube->player.px + cos(ray->ra) * ray->dist;
	else
		wx = data->cube->player.py + sin(ray->ra) * ray->dist;
	t[X] = wx / 64.f;
	t[X] -= floor(t[X]);
	t[X] *= 64.f;
	ray->color = my_mlx_get_pixel(
			data->cube->ray->texture[RENDER_TEXT], t[X], t[Y]);
	my_mlx_pixel_put(data->cube, draw[X], draw[Y], ray->color);
}

void	draw3d(t_struct *data, float *draw, float end, t_ray *ray)
{
	float	dist_y;
	float	max;
	float	t[2];
	float	ty_step;

	dist_y = draw[Y + 2] - draw[Y];
	max = ft_abs(dist_y);
	t[Y] = 0;
	ty_step = 64.f / ray->line_h;
	while (ft_abs(draw[Y + 2] - draw[Y]) != 0)
	{
		if (draw[Y] > 0 && draw[X] < WIN_W && draw[Y] < WIN_H)
		{
			if (end == 0 || end == WIN_H)
				my_mlx_pixel_put(data->cube, draw[X], draw[Y], draw[4]);
			else
				update_draw(data, draw, t, ray);
		}
		if (dist_y / max < 0)
			draw[Y] -= floor(fabs(dist_y / max));
		else
			draw[Y] += floor(fabs(dist_y / max));
		t[Y] += ty_step;
	}
}
