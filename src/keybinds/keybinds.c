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

static void	key_move_player(int keycode, t_struct *data)
{
	if (keycode == KEY_S)
	{
		data->cube->player.px -= data->cube->player.pdx;
		data->cube->player.py -= data->cube->player.pdy;
	}
	else if (keycode == KEY_W)
	{
		data->cube->player.px += data->cube->player.pdx;
		data->cube->player.py += data->cube->player.pdy;
	}
}

static void	key_move_cam(int keycode, t_struct *data)
{
	if (keycode == KEY_A)
	{
		data->cube->player.pa -= 0.1;
		if (data->cube->player.pa < 0)
			data->cube->player.pa += 2 * PI;
		data->cube->player.pdx = cos(data->cube->player.pa) * 5;
		data->cube->player.pdy = sin(data->cube->player.pa) * 5;
	}
	else if (keycode == KEY_D)
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
	if (keycode == KEY_A || keycode == KEY_D)
		key_move_cam(keycode, data);
	else if (keycode == KEY_S || keycode == KEY_W)
		key_move_player(keycode, data);
	else if (keycode == ESC)
		exit(0); //Leaks
	mlx_put_image_to_window(data->cube->mlx, data->cube->window,
		data->cube->img, 0, 0);
	draw_player(data->cube, 0xFF0053, 10);
//	draw_rays(data);
	return (0);
}

int	keypress(int keycode, t_struct *data)
{
	move_player(keycode, data);
	return (0);
}
