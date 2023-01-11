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

void	bresenham(t_struct *data, float ox, float oy, float *r)
{
	float	dist_x;
	float	dist_y;
	float	max;

	dist_x = r[X] - ox;
	dist_y = r[Y] - oy;
	if (ft_abs(dist_x) > ft_abs(dist_y))
		max = ft_abs(dist_x);
	else
		max = ft_abs(dist_y);
	while (ft_abs(r[X] - ox) != 0 || ft_abs(r[Y] - oy) != 0)
	{
		if (ox >= 0 && ox < data->width * data->map_s && oy >= 0
			&& oy < data->height * data->map_s)
			my_mlx_pixel_put(data->cube, ox, oy, 0xFF0000);
		ox += dist_x / max;
		oy += dist_y / max;
	}
}

void	bresenham3d(t_struct *data, float ox, float oy, float rx, float ry, int color)
{
	float	dist_x;
	float	dist_y;
	float	max;
	int		i;

	dist_x = rx - ox;
	dist_y = ry - oy;
	if (ft_abs(dist_x) > ft_abs(dist_y))
		max = ft_abs(dist_x);
	else
		max = ft_abs(dist_y);
	while (ft_abs(rx - ox) != 0 || ft_abs(ry - oy) != 0)
	{
		if (ox >= 0 && ox < 1024 && oy >= 0
			&& oy < 512)
		{
			i = 0;
			while (i < 8 && ox + i < 1024)
			{
				my_mlx_pixel_put(data->cube, ox + i, oy, color);
				i++;
			}
		}
		ox += dist_x / max;
		oy += dist_y / max;
	}
}

float	dist(float ax, float ay, float bx, float by)
{
	float	dist;

	dist = sqrtf((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
	return (dist);
}
