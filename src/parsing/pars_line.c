/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:42:22 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/15 14:42:23 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	ft_memcmp_reverse(char *s1, char *s2)
{
	int	len;
	int	i;
	int	y;

	len = ft_strlen(s2);
	i = ft_strlen(s1) - len;
	if (i < 0)
		return (0);
	y = 0;
	while (s1[i] && s2[y])
	{
		if (s1[i] != s2[y])
			return (0);
		i++;
		y++;
	}
	return (1);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '\t') || (line[i] == '\v')
			|| (line[i] == '\r') || (line[i] == '\f') || (line[i] == ' '))
			i++;
		else
			break ;
	}
	if (line[i] == '\n')
		return (1);
	else
		return (0);
}

int	cmp_setting(t_struct *data, char *line, char *type, int value)
{
	char	**split;

	split = ft_split_charset(line, WHITE);
	if (!split)
	{
		clear_after_init(data, line);
		exit (msg_error(MALLOC));
	}
	if (!ft_strcmp(split[0], type))
	{
		if (data->info[value] == 0)
			data->info[value] = 1;
		else
		{
			clear_after_init(data, line);
			ft_free_split(split);
			exit (msg_error(LOT_OF_SET));
		}
		ft_free_split(split);
		return (0);
	}
	ft_free_split(split);
	return (1);
}

char	*is_begin_map(t_struct *data, char *line)
{
	if (!first_line(line, 0))
	{
		clear_after_init(data, line);
		exit (msg_error(INVALID_SET));
	}
	else
	{
		if (!every_info(data->info))
		{
			clear_after_init(data, line);
			exit (msg_error(MISSING));
		}
		line = get_map(data, line);
		only_good_char(data);
		if (!first_line(data->map[data->height -1], 1))
			exit_map_parsing(data, INVALID_MAP, line);
		check_border(data);
		update_with_space(data);
		// check_around_space(data);
	}
	return (line);
}
