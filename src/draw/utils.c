/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:09:56 by pamartin          #+#    #+#             */
/*   Updated: 2023/01/05 18:09:57 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	draw3d(t_struct *data, float *draw, float end, t_ray *ray)
{
	float	dist_y;
	float	max;
	float	t[2];
	float	ty_step;
	float	wx;
	int		color;

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
			{
				if (data->cube->ray->ver[DIST] > data->cube->ray->hor[DIST])
					wx = data->cube->player.px + cos(ray->ra) * ray->dist;
				else
					wx = data->cube->player.py + sin(ray->ra) * ray->dist;
				t[X] = wx / 64.f;
				t[X] -= floor(t[X]);
				t[X] *= 64.f;
				color = my_mlx_get_pixel(
						data->cube->ray->texture[RENDER_TEXT], t[X], t[Y]);
				my_mlx_pixel_put(data->cube, draw[X], draw[Y], color);
			}
		}
		draw[Y] += dist_y / max;
		t[Y] += ty_step;
	}
}

void	update_y_color(float *draw, t_struct *data, float end, t_ray *ray)
{
	draw[Y + 2] = end;
	if (end == 0)
	{
		draw[Y] = ray->line_o;
		draw[4] = data->color[CEILING];
	}
	else if (end == WIN_H)
	{
		draw[Y] = ray->line_o + ray->line_h;
		draw[4] = data->color[FLOOR];
	}
	else
		draw[Y] = ray->line_o;
}

float	update_end(float end, t_ray *ray)
{
	if (end == 0)
		end = ray->line_o + ray->line_h;
	else if (end == ray->line_o + ray->line_h)
		end = WIN_H;
	else
		end = INT_MAX;
	return (end);
}

void	draw_cwf(t_struct *data, int i, t_ray *ray)
{
	float	*draw;
	float	end;

	draw = malloc(sizeof(float) * 5);
	//protection
	draw[X] = i + 0;
	draw[X + 2] = i + 0;
	end = 0;
	while (end < INT_MAX)
	{
		update_y_color(draw, data, end, ray);
		draw3d(data, draw, end, ray);
		end = update_end(end, ray);
	}
}

float	dist(float ax, float ay, float bx, float by)
{
	float	dist;

	dist = sqrtf((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
	return (dist);
}
