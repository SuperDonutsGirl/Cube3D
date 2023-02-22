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
		exit (msg_error(INVALID_SET));
	}
	return (split);
}

static void	print_msg_exit(int type)
{
	if (type == CEILING)
		exit(msg_error(RGB_C));
	else
		exit(msg_error(RGB_F));
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
		// ft_free_split(split);
		exit (msg_error(MALLOC));
	}
	while (rgb[i])
		i++;
	if (i != 3 || rgb[2][0] == '\n')
	{
		clear_after_init(data, line);
		ft_free_split(rgb);
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
	if (!rgb)
		exit (msg_error(MALLOC));
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
