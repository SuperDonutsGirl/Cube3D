/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_set_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:51:17 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/15 14:51:19 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	print_error(int type)
{
	char	*msg;

	if (type == NO)
		msg = ft_strdup(PATH_NO);
	else if (type == SO)
		msg = ft_strdup(PATH_SO);
	else if (type == WE)
		msg = ft_strdup(PATH_WE);
	else
		msg = ft_strdup(PATH_EA);
	msg_error(msg);
	ft_free(msg);
}

void	parsing_texture(t_struct *data, char *line, int type)
{
	char	**split;
	char	*path;

	split = split_line_and_check(data, line);
	path = ft_strdup(split[1]);
	if (path[ft_strlen(path) - 1] == '\n')
		path[ft_strlen(path) - 1] = '\0';
	if (type == NO){
		free(data->texture[NO]);
		data->texture[NO] = ft_strdup(path);
	}
	else if (type == SO){
		free(data->texture[SO]);
		data->texture[SO] = ft_strdup(path);
	}
	else if (type == WE){
		free(data->texture[WE]);
		data->texture[WE] = ft_strdup(path);
	}
	else{
		free(data->texture[EA]);
		data->texture[EA] = ft_strdup(path);
	}
	if (!path || !ft_memcmp_reverse(path, ".xpm"))
	{
		clear_after_init(data, line);
		ft_free_split(split);
		ft_free(path);
		print_error(type);
		exit (EXIT_FAILURE);
	}
	ft_free_split(split);
	ft_free(path);
}
