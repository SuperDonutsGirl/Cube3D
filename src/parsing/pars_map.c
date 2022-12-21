/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:03:11 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/15 15:03:16 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

char	*get_map(t_struct *data, char *line)
{
	int	i;

	i = 0;
	data->map = malloc(sizeof(char *) * data->height);
	if (!data->map)
	{
		clear_after_init(data, line);
		exit (msg_error(MALLOC));
	}
	while (line && i < data->height)
	{
		data->map[i] = ft_strdup(line);
		if (data->map[i][ft_strlen(data->map[i]) - 1] == '\n')
			data->map[i][ft_strlen(data->map[i]) - 1] = '\0';
		if (!data->map[i])
		{
			ft_free_split(data->map);
			clear_after_init(data, line);
			exit (msg_error(MALLOC));
		}
		ft_free(line);
		line = get_next_line(data->fd);
		i++;
	}
	close(data->fd);
	data->fd = 0;
	return (line);
}

void	get_height(t_struct *data)
{
	char *line;

	data->height = 0;
	line = ft_strdup("");
	while (line)
	{
		ft_free(line);
		line = get_next_line(data->fd);
		if (first_line(line, 0))
		{
			while (line)
			{
				data->height++;
				ft_free(line);
				line = get_next_line(data->fd);
			}
		}
	}
	close(data->fd);
	data->fd = 0;
	if (data->height < 3)
		exit (msg_error(INVALID_MAP));
}
