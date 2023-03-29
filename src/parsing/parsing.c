/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:27:14 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/14 11:27:16 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	check_text(t_struct *data)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (data->texture[i])
	{
		j = i + 1;
		tmp = ft_strdup(data->texture[i]);
		while (data->texture[j])
		{
			if (ft_strcmp(tmp, data->texture[j]) == 0)
			{
				free(tmp);
				clear_after_init(data, NULL);
				ft_free_split(data->texture);
				ft_free_split(data->map);
				msg_error(INVALID_SET);
				exit (EXIT_FAILURE);
			}
			j++;
		}
		free(tmp);
		i++;
	}
}

static char	*check_settings(t_struct *data, char *line)
{
	if (!cmp_setting(data, line, "NO", 0))
		parsing_texture(data, line, NO);
	else if (!cmp_setting(data, line, "SO", 1))
		parsing_texture(data, line, SO);
	else if (!cmp_setting(data, line, "WE", 2))
		parsing_texture(data, line, WE);
	else if (!cmp_setting(data, line, "EA", 3))
		parsing_texture(data, line, EA);
	else if (!cmp_setting(data, line, "F", 4))
		parsing_color(data, line, FLOOR);
	else if (!cmp_setting(data, line, "C", 5))
		parsing_color(data, line, CEILING);
	else
		line = is_begin_map(data, line);
	return (line);
}

static char	*check_line(char *line, t_struct *data)
{
	if (is_empty_line(line))
		return (line);
	else
		line = check_settings(data, line);
	return (line);
}

static void	check_data(t_struct *data)
{
	char	*line;

	init_data_parsing(data);
	line = ft_strdup("");
	while (line && data)
	{
		ft_free(line);
		line = get_next_line(data->fd);
		if (!line && !every_info(data->info))
		{
			clear_after_init(data, line);
			msg_error(MISSING);
			exit (EXIT_FAILURE);
		}
		else if (!line)
		{
			ft_free(data->info);
			close(data->fd);
			return ;
		}
		line = check_line(line, data);
	}
	ft_free(line);
	check_text(data);
}

void	parsing(int argc, char **argv, t_struct *data)
{
	if (argc != 2)
		exit(msg_error(ARG));
	if (!ft_memcmp_reverse(argv[1], ".cub"))
		exit(msg_error(FORMAT));
	get_fd(data, argv[1]);
	get_height(data);
	get_fd(data, argv[1]);
	check_data(data);
	data->map_s = 64;
	data->mini_s = 32;
}
