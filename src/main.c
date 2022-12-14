/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:27:01 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/14 11:27:03 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	main(int argc, char **argv)
{
	int			error;
	t_struct	*data;

	data = malloc(sizeof(t_struct));
	if (!data)
		exit (EXIT_FAILURE);
	error = parsing(argc, argv, data);
	if (error)
	{
		free(data);
		exit(1);
	}
	exit(0);
}
