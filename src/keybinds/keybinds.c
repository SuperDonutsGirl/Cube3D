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
		data->cube->player.px -= data->cube->player.pdx;
		data->cube->player.py -= data->cube->player.pdy;
	}
	else if (data->key.w == 1)
	{
		data->cube->player.px += data->cube->player.pdx;
		data->cube->player.py += data->cube->player.pdy;
	}
}

static void	key_move_cam(t_struct *data)
{
	if (data->key.a == 1)
	{
		data->cube->player.pa -= 0.1;
		if (data->cube->player.pa < 0)
			data->cube->player.pa += 2 * PI;
		data->cube->player.pdx = cos(data->cube->player.pa) * 5;
		data->cube->player.pdy = sin(data->cube->player.pa) * 5;
	}
	else if (data->key.d == 1)
	{
		data->cube->player.pa += 0.1;
		if (data->cube->player.pa > 2 * PI)
			data->cube->player.pa -= 2 * PI;
		data->cube->player.pdx = cos(data->cube->player.pa) * 5;
		data->cube->player.pdy = sin(data->cube->player.pa) * 5;
	}
}

int	move_player(int keycode, t_struct *data)
{
	mlx_clear_window(data->cube->mlx, data->cube->window);
	if (data->key.a == 1 || data->key.d == 1)
		key_move_cam(data);
	if (data->key.s == 1 || data->key.w == 1)
		key_move_player(data);
	else if (keycode == ESC)
		exit(0); //Leaks
	data->cube->img = mlx_new_image(data->cube->mlx, 1024, 512);
	data->cube->address = mlx_get_data_addr(data->cube->img,
			&data->cube->bits_per_pixel, &data->cube->line_length,
			&data->cube->endian);
	draw_map_2d(data);
	draw_player(data, 0xFF0053, 16);
	draw_rays(data);
	mlx_put_image_to_window(data->cube->mlx, data->cube->window,
		data->cube->img, 0, 0);
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
	move_player(keycode, data);
	return (0);
}
