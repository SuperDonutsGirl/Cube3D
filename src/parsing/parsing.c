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

#include "../../cub.h"

static void	check_settings(t_struct *data, char *line)
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
		is_begin_map(data, line);
}

static int	*check_line(char *line, t_struct *data)
{
	if (is_empty_line(line))
		return (data->info);
	else
		check_settings(data, line);
	return (data->info);
}

static void	check_data(t_struct *data)
{
	char	*line;

	init_data_parsing(data);
	line = ft_strdup("");
	while (line && data)
	{
		free(line);
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
		data->info = check_line(line, data);
	}
}

int	parsing(int argc, char **argv, t_struct *data)
{
	if (argc != 2)
		return (msg_error(ARG));
	if (!ft_memcmp_reverse(argv[1], ".cub"))
		return (msg_error(FORMAT));
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
		return (msg_error(ACCESS));
	check_data(data);
	return (0);
}
