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
	if (!draw)
		return ;
	draw[X] = i + 0;
	draw[X + 2] = i + 0;
	end = 0;
	while (end < INT_MAX)
	{
		update_y_color(draw, data, end, ray);
		draw3d(data, draw, end, ray);
		end = update_end(end, ray);
	}
	ft_free(draw);
}

float	dist(float ax, float ay, float bx, float by)
{
	float	dist;

	dist = sqrtf((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
	return (dist);
}
