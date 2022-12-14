/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:52:07 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/14 17:52:09 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

static char	**split_line_and_check(t_struct *data, char *line)
{
	char	**split;
	int		i;

	split = ft_split_charset(line, WHITE);
	if (!split)
	{
		clear_after_init(data, line);
		exit (EXIT_FAILURE);
	}
	i = 0;
	while (split[i])
		i++;
	if (i > 2)
	{
		clear_after_init(data, line);
		msg_error(INVALID_SET);
		exit (EXIT_FAILURE);
	}
	return (split);
}

char	**split_rgb(t_struct *data, char *line, char **split)
{
	char	**rgb;

	rgb = ft_split_charset(split[1], ",");
	if (!rgb)
	{
		clear_after_init(data, line);
		ft_free_split(split);
		exit (EXIT_FAILURE);
	}
	return (rgb);
}

static void	print_msg_exit(int type)
{
	if (type == CEILING)
		exit(msg_error(RGB_C));
	else
		exit(msg_error(RGB_F));
}

void	parsing_color(t_struct *data, char *line, int type)
{
	char	**split;
	char	**rgb;
	int		i;
	int		nb;

	split = split_line_and_check(data, line);
	rgb = split_rgb(data, line, split);
	i = 0;
	while (rgb[i])
	{
		nb = ft_atoi(rgb[i]);
		if (nb < 0 || nb > 255)
		{
			clear_after_init(data, line);
			ft_free_split(split);
			ft_free_split(rgb);
			print_msg_exit(type);
		}
		else
			data->color[type] = ft_strdup(split[1]);
		i++;
	}
	ft_free_split(rgb);
	ft_free_split(split);
}

void	parsing_texture(t_struct *data, char *line, int type)
{
	char	**split;
	int		fd;

	split = split_line_and_check(data, line);
	if (!ft_strcmp(split[1], TEXT_EA))
	{
		clear_after_init(data, line);
		ft_free_split(split);
		msg_error(PATH_EA);
		exit (EXIT_FAILURE);
	}
}
