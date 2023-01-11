/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:27:01 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/14 11:27:03 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_cube(t_struct *data)
{
	data->cube = malloc(sizeof(t_cube));
	if (!data->cube)
		exit_map_parsing(data, MALLOC, NULL);
	data->cube->player.px = data->player[2] * data->map_s;
	data->cube->player.py = data->player[1] * data->map_s;
	data->cube->player.pa = data->player[0];
	data->cube->player.pdx = cos(data->cube->player.pa) * 5;
	data->cube->player.pdy = sin(data->cube->player.pa) * 5;
	data->cube->mini.px = data->cube->player.px / 2 + data->mini_s;
	data->cube->mini.py = data->cube->player.py / 2 + data->mini_s;
	data->cube->mlx = mlx_init();
	mlx_do_key_autorepeaton(data->cube->mlx);
	data->cube->window = mlx_new_window(data->cube->mlx,
			1024, 512, "cub3d");
	data->cube->img = mlx_new_image(data->cube->mlx, 1024,
			512);
	data->cube->address = mlx_get_data_addr(data->cube->img,
			&data->cube->bits_per_pixel, &data->cube->line_length,
			&data->cube->endian);
	//data->cube->mini = mlx_new_image(data->cube->img, 300, 300);
	//data->cube->address = mlx_get_data_addr(data->cube->mini, &data->cube->bpp_mini, &data->cube->ll_mini, &data->cube->end_mini);
}

int	main(int argc, char **argv)
{
	t_struct	*data;

	data = malloc(sizeof(t_struct));
	if (!data)
		exit (msg_error(MALLOC));
	parsing(argc, argv, data);
	init_cube(data);
	//draw_map_2d(data);
	//draw_player(data, 0xFF0053, 16); //Quid modif pour minimap
	draw_rays(data);
	draw_mini_map(data);
	mlx_put_image_to_window(data->cube->mlx, data->cube->window,
			data->cube->img, 0, 0);
	mlx_hook(data->cube->window, 3, 3, keypress, data);
	mlx_hook(data->cube->window, 17, 0L, close_on_click, data->cube);
	mlx_loop(data->cube->mlx);
	exit(0);
}
