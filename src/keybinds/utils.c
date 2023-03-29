/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:27:27 by dduraku           #+#    #+#             */
/*   Updated: 2023/03/29 15:27:33 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

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
