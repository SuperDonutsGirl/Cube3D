/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:57:53 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/15 14:57:56 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	init_info(t_struct *data)
{
	int	i;

	i = 0;
	data->info = malloc(sizeof(int) * 6);
	if (!data->info)
	{
		close(data->fd);
		ft_free(data);
		exit (msg_error(MALLOC));
	}
	while (i < 6)
	{
		data->info[i] = 0;
		i++;
	}
}

static void	init_color(t_struct *data)
{
	int	i;

	i = 0;
	data->color = malloc(sizeof(int) * 2);
	if (!data->color)
	{
		ft_free(data->info);
		close(data->fd);
		ft_free(data);
		exit (msg_error(MALLOC));
	}
	while (i < 2)
	{
		data->color[i] = 0;
		i++;
	}
}

static void	init_player(t_struct *data)
{
	int	i;

	i = 0;
	data->player = malloc(sizeof(double) * 3);
	if (!data->player)
	{
		ft_free(data->info);
		ft_free(data->color);
		close(data->fd);
		ft_free(data);
		exit (msg_error(MALLOC));
	}
	while (i < 3)
	{
		data->player[i] = -1;
		i++;
	}
}

static void	init_texture(t_struct *data)
{
	int	i;

	data->texture = malloc(sizeof(char *) * 4);
	if (!data->texture)
	{
		ft_free(data->info);
		ft_free(data->color);
		close(data->fd);
		ft_free(data);
		exit (msg_error(MALLOC));
	}
	i = 0;
	while (i < 4)
	{
		data->texture[i] = ft_strdup("\0");
		if (!data->texture[i])
		{
			clear_after_init(data, NULL);
			exit (msg_error(MALLOC));
		}
		i++;
	}
	data->texture[i] = 0;
}

void	init_data_parsing(t_struct *data)
{
	init_info(data);
	init_color(data);
	init_player(data);
	init_texture(data);
}
