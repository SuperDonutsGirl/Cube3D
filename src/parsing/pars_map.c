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

#include "../../includes/cub.h"

char	*get_map(t_struct *data, char *line)
{
	size_t	i;

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
			exit_map_parsing(data, MALLOC, line);
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
	char	*line;

	data->height = 0;
	line = ft_strdup("");
	while (line)
	{
		ft_free(line);
		line = get_next_line(data->fd);
		if (line && first_line(line, 0))
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

void	check_player(t_struct *data, char elmt, int y, int x)
{
	if (elmt == 'N' || elmt == 'S' || elmt == 'E' || elmt == 'W')
	{
		if (data->player[0] == -1)
		{
			data->player[1] = y;
			data->player[2] = x;
			if (elmt == 'N')
				data->player[0] = NORTH;
			if (elmt == 'S')
				data->player[0] = SOUTH;
			if (elmt == 'E')
				data->player[0] = EAST;
			if (elmt == 'W')
				data->player[0] = WEST;
		}
		else
			exit_map_parsing(data, INVALID_MAP, NULL);
	}
}
