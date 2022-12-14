/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:10:52 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/14 18:10:54 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	clear_after_init(t_struct *data, char *line)
{
	ft_free(line);
	ft_free(data->info);
	ft_free_split(data->color);
	ft_free_split(data->texture);
	close(data->fd);
	ft_free(data);
}
