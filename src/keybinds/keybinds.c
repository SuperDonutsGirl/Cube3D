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

static void	key_move_player_x(t_struct *data)
{
	float	px;
	float	py;
	float	npx;
	float	npy;

	px = data->cube->player.px;
	py = data->cube->player.py;
	if (data->key.a == 1)
	{
		npx = px + data->cube->player.pdy * MOVE_SPEED;
		npy = py - data->cube->player.pdx * MOVE_SPEED;
		if (!is_wall(data, npx, py))
			data->cube->player.px = npx;
		if (!is_wall(data, px, npy))
			data->cube->player.py = npy;
	}
	else if (data->key.d == 1)
	{
		npx = px - data->cube->player.pdy * MOVE_SPEED;
		npy = py + data->cube->player.pdx * MOVE_SPEED;
		if (!is_wall(data, npx, py))
			data->cube->player.px = npx;
		if (!is_wall(data, px, npy))
			data->cube->player.py = npy;
	}
}

static void	key_move_player_y(t_struct *data)
{
	float	px;
	float	py;
	float	npx;
	float	npy;

	px = data->cube->player.px;
	py = data->cube->player.py;
	if (data->key.s == 1)
	{
		npx = px - data->cube->player.pdx * MOVE_SPEED;
		npy = py - data->cube->player.pdy * MOVE_SPEED;
		if (!is_wall(data, npx, py))
			data->cube->player.px = npx;
		if (!is_wall(data, px, npy))
			data->cube->player.py = npy;
	}
	else if (data->key.w == 1)
	{
		npx = px + data->cube->player.pdx * MOVE_SPEED;
		npy = py + data->cube->player.pdy * MOVE_SPEED;
		if (!is_wall(data, npx, py))
			data->cube->player.px = npx;
		if (!is_wall(data, px, npy))
			data->cube->player.py = npy;
	}
}

static void	key_move_cam(t_struct *data)
{
	if (data->key.left == 1)
	{
		data->cube->player.pa -= ROT_SPEED;
		if (data->cube->player.pa < 0)
			data->cube->player.pa += 2 * M_PI;
		data->cube->player.pdx = cos(data->cube->player.pa) * 5;
		data->cube->player.pdy = sin(data->cube->player.pa) * 5;
	}
	else if (data->key.right == 1)
	{
		data->cube->player.pa += ROT_SPEED;
		if (data->cube->player.pa > 2 * M_PI)
			data->cube->player.pa -= 2 * M_PI;
		data->cube->player.pdx = cos(data->cube->player.pa) * 5;
		data->cube->player.pdy = sin(data->cube->player.pa) * 5;
	}
}

int	move_player(int keycode, t_struct *data)
{
	mlx_clear_window(data->cube->mlx, data->cube->window);
	key_move_cam(data);
	key_move_player_y(data);
	key_move_player_x(data);
	if (keycode == ESC)
	{
		//system("leaks cub3d");
		exit(0);
	}
	data->cube->image.img = mlx_new_image(data->cube->mlx, WIN_W, WIN_H);
	data->cube->image.address = mlx_get_data_addr(data->cube->image.img,
			&data->cube->image.bits_per_pixel,
			&data->cube->image.line_length, &data->cube->image.endian);
	draw_rays(data);
	mlx_put_image_to_window(data->cube->mlx, data->cube->window,
		data->cube->image.img, 0, 0);
	return (0);
}

int	keyrelease(int keycode, t_struct *data)
{
	if (keycode == KEY_W)
		data->key.w = 0;
	if (keycode == KEY_A)
		data->key.a = 0;
	if (keycode == KEY_S)
		data->key.s = 0;
	if (keycode == KEY_D)
		data->key.d = 0;
	if (keycode == KEY_RIGHT)
		data->key.right = 0;
	if (keycode == KEY_LEFT)
		data->key.left = 0;
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
	if (keycode == KEY_RIGHT)
		data->key.right = 1;
	if (keycode == KEY_LEFT)
		data->key.left = 1;
	if (keycode == ESC)
		exit(0);
	return (0);
}
