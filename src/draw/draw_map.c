/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:16:20 by dduraku           #+#    #+#             */
/*   Updated: 2022/12/16 15:16:22 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color)
{
	int	pix;

	pix = (x * cube->image.bits_per_pixel / 8) + (y * cube->image.line_length);
	cube->image.address[pix] = color;
	cube->image.address[pix + 1] = color >> 8;
	cube->image.address[pix + 2] = color >> 16;
}

unsigned int	my_mlx_get_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->address
		+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
