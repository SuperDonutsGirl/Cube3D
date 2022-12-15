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
#include "../mlx/mlx.h"

#define ESC 53

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
}		t_cube;

//Raccourcis clavier
int	keybinds(int keycode, t_cube *cube);
int	close_on_click(int keycode);