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

void	init_img(t_struct *data)
{
	data->cube->image.img = mlx_new_image(data->cube->mlx, WIN_WIDTH,
			WIN_HEIGHT);
	data->cube->image.address = mlx_get_data_addr(data->cube->image.img,
			&data->cube->image.bits_per_pixel, &data->cube->image.line_length,
			&data->cube->image.endian);

	// printf("img = %s adr.img = %p\n", data->cube->image.address, data->cube->image.address);
	
}

void	init_textures(t_struct *data)
{
	//data->cube->image = malloc(sizeof(t_img) * 1);
	//protection malloc

	// data->cube->image.img = mlx_new_image(data->cube->mlx, WIN_WIDTH,
	// 		WIN_HEIGHT);
	// data->cube->image.address = mlx_get_data_addr(data->cube->image.img,
	// 		&data->cube->image.bits_per_pixel, &data->cube->image.line_length,
	// 		&data->cube->image.endian);

	data->cube->tex = malloc(sizeof(t_img) * 5);
	//protection malloc
	int face = NO;
	while (face < 4)
	{
		data->cube->tex[face].img = mlx_xpm_file_to_image(&data->cube->mlx, data->texture[face], &data->cube->tex[face].w_text, &data->cube->tex[face].h_text);
		if (!data->cube->tex[face].img)
			printf("bordel de merde\n");
		data->cube->tex[face].address = mlx_get_data_addr(data->cube->tex[face].img,
													&data->cube->tex[face].bits_per_pixel,
													&data->cube->tex[face].line_length,
													&data->cube->tex[face].endian);
		face++;
	}
	// printf("textNO = %s adr.No = %p\n", data->cube->tex[1].address, data->cube->tex[1].address);
	// printf("textNO = %s adr.No = %p\n", data->cube->tex[0].address, data->cube->tex[0].address);

	int	y = 0;
	int x = 0;
	int pix;
	for (int i = 0; i < 64; i++){
		//pix = x * (data->cube->tex[0].bits_per_pixel / 8);
		pix = (x * data->cube->tex[0].bits_per_pixel / 8) + (y * data->cube->tex[0].line_length);
		printf("xpm[%d] = %d\n", pix, data->cube->tex[0].address[pix]);
		x++;
	}
}

void	init_cube(t_struct *data)
{
	data->cube = malloc(sizeof(t_cube));
	if (!data->cube)
		exit_map_parsing(data, MALLOC, NULL);
	data->cube->player.px = data->player[2] * data->map_s + 28;
	data->cube->player.py = data->player[1] * data->map_s + 28;
	data->cube->player.pa = data->player[0];
	data->cube->player.pdx = cos(data->cube->player.pa) * 5;
	data->cube->player.pdy = sin(data->cube->player.pa) * 5;
	data->cube->mlx = mlx_init();
	mlx_do_key_autorepeaton(data->cube->mlx);
	data->cube->window = mlx_new_window(data->cube->mlx,
			WIN_WIDTH, WIN_HEIGHT, "cub3d");
	init_img(data);
	init_textures(data);
	// data->cube->img = mlx_new_image(data->cube->mlx, WIN_WIDTH,
	// 		WIN_HEIGHT);
	// data->cube->address = mlx_get_data_addr(data->cube->img,
	// 		&data->cube->bits_per_pixel, &data->cube->line_length,
	// 		&data->cube->endian);
}

int	move_player(int keycode, t_struct *data);

static int moving(void *arg) {
	t_struct *data = arg;
	move_player(-1, data);
	return 0;
}

int	main(int argc, char **argv)
{
	t_struct	*data;

	data = malloc(sizeof(t_struct));
	if (!data)
		exit (msg_error(MALLOC));
	parsing(argc, argv, data);
	init_cube(data);
	// draw_map_2d(data);
	// draw_player(data, 0xFF0053, 16); //Quid modif pour minimap
	draw_rays(data);
	mlx_hook(data->cube->window, 3, 3, keyrelease, data);
	mlx_hook(data->cube->window, 2, 2, keypress, data);
	mlx_hook(data->cube->window, 17, 0L, close_on_click, data->cube);
	mlx_loop_hook(data->cube->mlx, moving, data);
	mlx_loop(data->cube->mlx);
	exit(0);
}
