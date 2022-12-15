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

#include "../../cub.h"

void	clear_after_init(t_struct *data, char *line)
{
	ft_free(line);
	ft_free(data->info);
	ft_free(data->color);
	ft_free_split(data->texture);
	close(data->fd);
	ft_free(data);
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

int	map_line_pattern(char *line) //Penser aà tous les white space
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9')
			|| (line[i] >= 'A' && line[i] <= 'Z')
			|| line[i] == '\n' || line[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}
