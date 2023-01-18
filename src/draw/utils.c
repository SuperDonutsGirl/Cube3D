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
		if (ox >= 0 && ox < WIN_WIDTH && oy >= 0
			&& oy < WIN_HEIGHT)
		{
			i = 0;
			while (i < 8 && ox + i < WIN_WIDTH)
			{
				my_mlx_pixel_put(data->cube, ox + i, oy, color);
				i++;
			}
		}
		ox += dist_x / max;
		oy += dist_y / max;
	}
}

void	draw3d(t_struct *data, float *draw, int color, float end, t_img texture)
{
	float	dist_x;
	float	dist_y;
	float	max;
	int		i;


	dist_x = draw[X + 2] - draw[X];
	dist_y = draw[Y + 2] - draw[Y];
	if (ft_abs(dist_x) > ft_abs(dist_y))
		max = ft_abs(dist_x);
	else
		max = ft_abs(dist_y);
	while (ft_abs(draw[X + 2] - draw[X]) != 0  || ft_abs(draw[Y + 2] - draw[Y]) != 0)
	{
		if (draw[X] > 0 && draw[X] < WIN_WIDTH && draw[Y] > 0
			&& draw[Y] <= WIN_HEIGHT)
		{
			i = 0;
			while (i < 8 && draw[X] + i < WIN_WIDTH)
			{
				if (end == 0 || end == WIN_HEIGHT)
				{
					//printf("coucocu\n");
					my_mlx_pixel_put(data->cube, draw[X] + i, draw[Y], color);
				}
				else
				{
					//printf("bordel\n");
					my_mlx_pixel_text_put(data->cube, texture, draw[X] + i, draw[Y]);
					
				}
				i++;
				texture.tex_step++;
			if (texture.tex_step == 64)
			{
				texture.tex_step = 0;
				texture.tex_x++;
				if (texture.tex_x == 64)
				{
					texture.tex_x = 0;
					texture.tex_y++;
				}
			}
			}
		}
		draw[X] += dist_x / max;
		draw[Y] += dist_y / max;
	}
}

void	update_y_color(float *draw, t_struct *data, float end, t_ray ray)
{
	draw[Y + 2] = end;
	if (end == 0)
	{
		draw[Y] = ray.line_o;
		draw[4] = data->color[CEILING];
	}
	else if (end == WIN_HEIGHT)
	{
		draw[Y] = ray.line_o + ray.line_h;
		draw[4] = data->color[FLOOR];
	}
	else
	{
		draw[Y] = ray.line_o;
		draw[4] = ray.r[COLOR];
	}
}

float	update_end(float end, t_ray ray)
{
	if (end == 0)
		end = ray.line_o + ray.line_h;
	else if (end == ray.line_o + ray.line_h)
		end = WIN_HEIGHT;
	else
		end = INT_MAX;
	return (end);
}

void	draw_cwf(t_struct *data, int i, t_ray ray, t_line *line)
{
	float	*draw;
	float	end;

	(void)line;
	draw = malloc(sizeof(float) * 5);
	//protection
	draw[X] = i * 8 + 530;
	draw[X + 2] = i * 8 + 530;
	end = 0;
	while (end < INT_MAX)
	{
		//printf("draw cwf\n");
		update_y_color(draw, data, end, ray);
		draw3d(data, draw, draw[4], end, ray.texture[RENDER_TEXT]);
		end = update_end(end, ray);
	}
}















float	dist(float ax, float ay, float bx, float by)
{
	float	dist;

	dist = sqrtf((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
	return (dist);
}
