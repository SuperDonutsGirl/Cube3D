/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_set_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:00:09 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/15 15:00:13 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

char	**split_line_and_check(t_struct *data, char *line)
{
	char	**split;
	int		i;

	split = ft_split_charset(line, WHITE);
	if (!split)
	{
		clear_after_init(data, line);
		exit (msg_error(MALLOC));
	}
	i = 0;
	while (split[i])
		i++;
	if (i > 2)
	{
		clear_after_init(data, line);
		ft_free(split);
		ft_free_split(data->texture);
		exit (msg_error(INVALID_SET));
	}
	return (split);
}

static int	is_char(char **rgb)
{
	int	i;
	int	j;

	j = 0;
	while (rgb[j])
	{
		i = 0;
		while (rgb[j][i] && rgb[j][i] != '\n')
		{
			while (rgb[j][i] && ((rgb[j][i] >= 9 && rgb[j][i] <= 13)
			|| rgb[j][i] == 32))
				i++;
			if (!ft_isdigit(rgb[j][i]))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

static char	**split_rgb(t_struct *data, char *line, int type)
{
	char	**rgb;
	int		i;

	rgb = ft_split_charset(line + 1, ",");
	i = 0;
	if (!rgb)
	{
		clear_after_init(data, line);
		exit (msg_error(MALLOC));
	}
	while (rgb[i])
		i++;
	if (i != 3 || rgb[2][0] == '\n' || is_char(rgb))
	{
		clear_after_init(data, line);
		ft_free_split(rgb);
		ft_free_split(data->texture);
		print_msg_exit(type);
	}
	return (rgb);
}

static int	get_hexa(char **rgb)
{
	int	hexa;

	hexa = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
	return (hexa);
}

void	parsing_color(t_struct *data, char *line, int type)
{
	char	**rgb;
	int		i;
	int		nb;

	rgb = split_rgb(data, line, type);
	i = 0;
	while (rgb[i])
	{
		nb = ft_atoi(rgb[i]);
		if (nb < 0 || nb > 255)
		{
			clear_after_init(data, line);
			ft_free_split(rgb);
			print_msg_exit(type);
		}
		else
			data->color[type] = get_hexa(rgb);
		i++;
	}
	ft_free_split(rgb);
}
