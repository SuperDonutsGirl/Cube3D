/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:55:01 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/20 11:55:05 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	only_good_char(t_struct *data)
{
	size_t	i;
	size_t	y;
	size_t	len;

	i = 0;
	data->width = 0;
	while (i < data->height - 1)
	{
		len = ft_strlen(data->map[i]);
		if (len > data->width)
			data->width = len;
		y = 0;
		while (data->map[i][y])
		{
			if (!good_char(data->map[i][y]))
				exit_map_parsing(data, INVALID_MAP, NULL);
			check_player(data, data->map[i][y], i, y);
			y++;
		}
		i++;
	}
	if (data->player[0] == -1)
		exit_map_parsing(data, INVALID_MAP, NULL);
}

void	update_with_space(t_struct *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) < data->width)
			data->map[i] = realloc_set(data->map[i], data->width, ' ');
		if (!data->map[i])
			exit_map_parsing(data, MALLOC, NULL);
		i++;
	}
	i = 0;
	while (data->map[i])
	{
		printf("-%s-\n", data->map[i]);
		i++;
	}
}

void	check_border(t_struct *data)
{
	int	i;
	int	start;

	i = 0;
	while (data->map[i])
	{
		start = 0;
		while (data->map[i][start] && data->map[i][start] == ' ')
			start++;
		if ((data->map[i][start] && data->map[i][start] != '1')
			|| !data->map[i][start])
			exit_map_parsing(data, INVALID_MAP, NULL);
		while (data->map[i][start])
			start++;
		if (data->map[i][start -1] != '1')
			exit_map_parsing(data, INVALID_MAP, NULL);
		i++;
	}
}

static void	check(t_struct *data, size_t x, size_t y)
{
	if (y > 0 && y < data->height - 1)
	{
		if (data->map[y - 1][x] != ' ' && data->map[y - 1][x] != '1')
			exit_map_parsing(data, INVALID_MAP, NULL);
		if (data->map[y + 1][x] != ' ' && data->map[y + 1][x] != '1')
			exit_map_parsing(data, INVALID_MAP, NULL);
	}
	if (x > 0 && x < data->width - 1)
	{
		if (data->map[y][x - 1] != ' ' && data->map[y][x - 1] != '1')
			exit_map_parsing(data, INVALID_MAP, NULL);
		if (data->map[y][x + 1] != ' ' && data->map[y][x + 1] != '1')
			exit_map_parsing(data, INVALID_MAP, NULL);
	}	
}

void	check_around_space(t_struct *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == ' ')
				check(data, x, y);
			x++;
		}
		y++;
	}
}
