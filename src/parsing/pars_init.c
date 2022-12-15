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

#include "../../cub.h"

static void	init_info(t_struct *data)
{
	int	i;

	i = 0;
	data->info = malloc(sizeof(int) * 6);
	if (!data->info)
	{
		ft_free(data);
		exit (EXIT_FAILURE);
	}
	while (i < 6)
	{
		data->info[i] = 0;
		i++;
	}
}

static void	init_color(t_struct *data)
{
	int		i;

	data->color = malloc(sizeof(char *) * 2 + 1);
	if (!data->color)
	{
		ft_free(data->info);
		ft_free(data);
		exit (EXIT_FAILURE);
	}
	i = 0;
	while (data->color[i])
	{
		data->color[i] = ft_strdup("\0");
		if (!data->color[i])
		{
			ft_free(data->info);
			ft_free_split(data->color);
			ft_free(data);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

static void	init_texture(t_struct *data)		//Quid utilité
{
	int	i;

	data->texture = malloc(sizeof(char *) * 4 + 1);
	if (!data->texture)
	{
		ft_free(data->info);
		ft_free_split(data->color);
		ft_free(data);
		exit (EXIT_FAILURE);
	}
	i = 0;
	while (data->texture[i])
	{
		data->texture[i] = ft_strdup("\0");
		if (!data->texture[i])
		{
			ft_free(data->info);
			ft_free_split(data->color);
			ft_free_split(data->texture);
			ft_free(data);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

void	init_data_parsing(t_struct *data)
{
	init_info(data);
	init_color(data);
	init_texture(data);
}
