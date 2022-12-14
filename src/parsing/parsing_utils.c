/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:54:39 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/14 17:54:44 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

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

int	every_info(int *info)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 6)
	{
		if (info[i] == 1)
			count++;
		i++;
	}
	if (count < 6)
		return (0);
	else
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
		exit (EXIT_FAILURE);
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

int	map_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9') || (line[i] >= 'A' && line[i] <= 'Z') || line[i] == '\n' || line[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}


void	is_map(t_struct *data, char *line)
{
	if (!map_line(line))
	{
		printf("coucou\n");
		clear_after_init(data, line);
		msg_error(INVALID_SET);
		exit (EXIT_FAILURE);
	}
	else
	{
		if (!every_info(data->info))
		{
			clear_after_init(data, line);
			msg_error(MISSING);
			exit (EXIT_FAILURE);
		}
		printf("map\n");
	}
}
