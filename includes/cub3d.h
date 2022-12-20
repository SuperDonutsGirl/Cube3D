/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:47:56 by dduraku           #+#    #+#             */
/*   Updated: 2022/12/15 13:47:57 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "../mlx/mlx.h"

#define ESC	53
#define PI	3.141592653589793238

typedef struct s_player
{
	float 	px;
	float	py;
	float	pdx;
	float	pdy;
	float	pa;
}	t_player;

typedef struct s_key
{
	bool	key_forward;
	bool	key_backward;
	bool	key_right;
	bool	key_left;
}		t_key;

typedef struct s_cube
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*address;

	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		pos_x;
	int		pos_y;

	t_key	keybinds;
	t_player player;
}		t_cube;

//Raccourcis clavier
int	keypress(int keycode, t_cube *cube);
int keyrelease(int keycode, t_cube *cube);
int	close_on_click(int keycode);


//Draw
void	draw_player(t_cube *cube, int color, int x_size, int y_size);
void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color);
void	draw_walls(t_cube *cube, int color, int x_size, int y_size, int px, int py);
void	draw_map_2D(t_cube *cube, int color_floor, int color_wall, int *map);

void	drawline(t_cube *cube, int color);
void	draw_rays(t_cube *cube, int *map);