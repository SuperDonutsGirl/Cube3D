/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:06:54 by dduraku           #+#    #+#             */
/*   Updated: 2022/12/15 15:06:56 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	key_move_player(t_struct *data)
{
	if (data->key.s == 1)
	{
		
		data->cube->player.px -= data->cube->player.pdx * MOVE_SPEED;
		data->cube->player.py -= data->cube->player.pdy * MOVE_SPEED;

	}
	else if (data->key.w == 1)
	{
		data->cube->player.px += data->cube->player.pdx * MOVE_SPEED;	
		data->cube->player.py += data->cube->player.pdy * MOVE_SPEED;
	}
}

static void	key_move_cam(t_struct *data)
{
	if (data->key.a == 1)
	{
		data->cube->player.pa -= ROT_SPEED;
		if (data->cube->player.pa < 0)
			data->cube->player.pa += 2 * PI;
		data->cube->player.pdx = cos(data->cube->player.pa) * 5;
		data->cube->player.pdy = sin(data->cube->player.pa) * 5;
	}
	else if (data->key.d == 1)
	{
		data->cube->player.pa += ROT_SPEED;
		if (data->cube->player.pa > 2 * PI)
			data->cube->player.pa -= 2 * PI;
		data->cube->player.pdx = cos(data->cube->player.pa) * 5;
		data->cube->player.pdy = sin(data->cube->player.pa) * 5;
	}
}

int	move_player(int keycode, t_struct *data)
{
	mlx_clear_window(data->cube->mlx, data->cube->window);
	key_move_cam(data);
	key_move_player(data);
	if (keycode == ESC)
		exit(0); //Leaks
	data->cube->image.img = mlx_new_image(data->cube->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->cube->image.address = mlx_get_data_addr(data->cube->image.img,
			&data->cube->image.bits_per_pixel, &data->cube->image.line_length,
			&data->cube->image.endian);
	//draw_map_2d(data);
	//draw_player(data, 0xFF0053, 16);
	draw_rays(data);
	mlx_put_image_to_window(data->cube->mlx, data->cube->window,
		data->cube->image.img, 0, 0);
	return (0);
}

int keyrelease(int keycode, t_struct *data)
{
	if (keycode == KEY_W)
		data->key.w = 0;
	if (keycode == KEY_A)
		data->key.a = 0;
	if (keycode == KEY_S)
		data->key.s = 0;
	if (keycode == KEY_D)
		data->key.d = 0;
	return (0);
}

int	keypress(int keycode, t_struct *data)
{
	if (keycode == KEY_W)
		data->key.w = 1;
	if (keycode == KEY_A)
		data->key.a = 1;
	if (keycode == KEY_S)
		data->key.s = 1;
	if (keycode == KEY_D)
		data->key.d = 1;
	if (keycode == ESC)
		exit(0);
	return (0);
}
