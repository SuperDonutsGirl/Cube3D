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

int	main(int argc, char **argv)
{
	t_struct	*data;

	data = malloc(sizeof(t_struct));
	if (!data)
		exit (msg_error(MALLOC));
	parsing(argc, argv, data);
	data->cube = malloc(sizeof(t_cube));
	if (!data->cube)
		exit (msg_error(MALLOC)); //Prendre en compte leaks parsing
	data->cube->player.px = data->player[2] * data->mapS + 28; // a quoi correspond le 28 ?
	data->cube->player.py = data->player[1] * data->mapS + 28;
	data->cube->player.pa = data->player[0];
	data->cube->player.pdx = cos(data->cube->player.pa) * 5;
	data->cube->player.pdy = sin(data->cube->player.pa) * 5;
	data->cube->mlx = mlx_init();
	mlx_do_key_autorepeaton(data->cube->mlx);
	data->cube->window = mlx_new_window(data->cube->mlx, data->width * data->mapS, data->height * data->mapS, "cub3d");
	data->cube->img = mlx_new_image(data->cube->mlx, data->width * data->mapS, data->height * data->mapS);
	data->cube->address = mlx_get_data_addr(data->cube->img, &data->cube->bits_per_pixel,
									  &data->cube->line_length, &data->cube->endian);
	draw_map_2d(data);
	draw_player(data->cube, 0xFF0053, 10); //10 pourrait etre modifié pour la minimap
	mlx_hook(data->cube->window, 3, 3, keypress, data);
	mlx_hook(data->cube->window, 17, 0L, close_on_click, data->cube);
	mlx_loop(data->cube->mlx);
	exit(0);
}
