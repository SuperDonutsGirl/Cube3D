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


		data->cube->mini.px = data->cube->player.px / 2 + data->mini_s;
		data->cube->mini.py = data->cube->player.py / 2 + data->mini_s;
	}
	else if (keycode == KEY_W)
	{
		
		data->cube->player.px += data->cube->player.pdx;
		data->cube->player.py += data->cube->player.pdy;

		data->cube->mini.px = data->cube->player.px / 2 + data->mini_s;
		data->cube->mini.py = data->cube->player.py / 2 + data->mini_s;
	}


}

static void	key_move_cam(int keycode, t_struct *data)
{
	if (keycode == KEY_LEFT)
	{
		data->cube->player.pa -= 0.1;
		if (data->cube->player.pa < 0)
			data->cube->player.pa += 2 * PI;
		data->cube->player.pdx = cos(data->cube->player.pa) * 5;
		data->cube->player.pdy = sin(data->cube->player.pa) * 5;
	}
	else if (keycode == KEY_RIGHT)
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
	data->cube->img = mlx_new_image(data->cube->mlx, 1024,
			512);
	data->cube->address = mlx_get_data_addr(data->cube->img,
			&data->cube->bits_per_pixel, &data->cube->line_length,
			&data->cube->endian);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		key_move_cam(keycode, data);
	else if (keycode == KEY_S || keycode == KEY_W)
		key_move_player(keycode, data);
	else if (keycode == ESC)
		exit(0); //Leaks

	



	//draw_map_2d(data);	
	//draw_player(data, 0xFF0053, 16);
	draw_mini_map(data);
	draw_rays(data);
	mlx_put_image_to_window(data->cube->mlx, data->cube->window,
		data->cube->img, 0, 0);
	return (0);
}

int	keypress(int keycode, t_struct *data)
{
	move_player(keycode, data);
	return (0);
}
