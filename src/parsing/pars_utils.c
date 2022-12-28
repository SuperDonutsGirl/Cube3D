/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:01:15 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/15 15:01:19 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	clear_after_init(t_struct *data, char *line)
{
	if (line)
		ft_free(line);
	ft_free(data->info);
	ft_free(data->color);
	ft_free(data->player);
	ft_free_split(data->texture);
	if (data->fd)
		close(data->fd);
	ft_free(data);
}

void	exit_map_parsing(t_struct *data, char *msg, char *line)
{
	clear_after_init(data, line);
	ft_free_split(data->map);
	exit (msg_error(msg));
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

int	first_line(char *line, int type)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1' || line[i] == ' ')
			i++;
		else
			return (0);
	}
	if (type == 0 && line[i] == '\n' && i > 0)
		return (1);
	if (type == 1)
		return (1);
	return (0);
}

void	get_fd(t_struct *data, char *file)
{
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
		exit(msg_error(ACCESS));
}
