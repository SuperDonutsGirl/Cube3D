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

#include "../../includes/cub3d.h"

int	move_player(int keycode, t_cube *cube)
{
	mlx_clear_window(cube->mlx, cube->window);
	if (keycode == 0)
	{
		cube->player.pa -= 0.1;
		if (cube->player.pa < 0)
			cube->player.pa += 2 * PI;
		cube->player.pdx = cos(cube->player.pa) * 5;
		cube->player.pdy = sin(cube->player.pa) * 5;
	}
	else if (keycode == 1)
	{
		cube->player.px -= cube->player.pdx;
		cube->player.py -= cube->player.pdy;
	}
	else if (keycode == 2)
	{
		cube->player.pa += 0.1;
		if (cube->player.pa > 2 * PI)
			cube->player.pa -= 2 * PI;
		cube->player.pdx = cos(cube->player.pa) * 5;
		cube->player.pdy = sin(cube->player.pa) * 5;
	}
	else if (keycode == 13)
	{
		cube->player.px += cube->player.pdx;
		cube->player.py += cube->player.pdy;
	}
	mlx_put_image_to_window(cube->mlx, cube->window, cube->img, 0, 0);
	draw_player(cube, 0xFF0053, 10, 10);
	return 0;
}

int keypress(int keycode, t_cube *cube)
{
	move_player(keycode, cube);
	if (keycode == 2) //droite
		cube->keybinds.key_right = true;
	else if (keycode == 1) //bas
		cube->keybinds.key_backward = true;
	else if (keycode == 0) //gauche
		cube->keybinds.key_right = true;
	else if (keycode == 13) //haut
		cube->keybinds.key_right = true;
	else if (keycode == ESC || keycode == 12)
	{
		mlx_destroy_window(cube->mlx, cube->window);
		exit(0);
	}
	return (0);
}

int keyrelease(int keycode, t_cube *cube)
{
	if (keycode == 2) //droite
		cube->keybinds.key_right = false;
	else if (keycode == 1) //bas
		cube->keybinds.key_backward = false;
	else if (keycode == 0) //gauche
		cube->keybinds.key_left = false;
	else if (keycode == 13) //haut
		cube->keybinds.key_forward = false;
	return (0);
}