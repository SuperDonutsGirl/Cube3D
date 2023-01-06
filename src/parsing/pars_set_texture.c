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
	if (type == NO)
		path = ft_strdup(TEXT_NO);
	else if (type == SO)
		path = ft_strdup(TEXT_SO);
	else if (type == WE)
		path = ft_strdup(TEXT_WE);
	else
		path = ft_strdup(TEXT_EA);
	if (!path)
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
