/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:27:34 by pamartin          #+#    #+#             */
/*   Updated: 2022/12/14 11:27:36 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./src/libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

/*Error messages for argument parding*/
# define ARG "This program requires only one argument"
# define FORMAT "Invalid map format"
# define ACCESS "Failed to open map"

/*Error messages for setting*/
# define PATH_NO "Invalid path for north texture"
# define PATH_SO "Invalid path for south texture"
# define PATH_WE "Invalid path for west texture"
# define PATH_EA "Invalid path for east texture"
# define RGB_F "Floor color isn't in RGB format"
# define RGB_C "Ceiling color isn't in RGB format"
# define LOT_OF_SET "Too many settings"
# define MISSING "Missing setting informations"
# define INVALID_SET "Invalid setting's line"
/*Error message for map*/
# define INVALID_MAP "Invalid map"

/*Global error messages*/
# define MALLOC "Malloc failed"
/*Gobal define*/
# define WHITE "\t\v\r\f "

/*Define texture*/
# define TEXT_NO "../../map/bluestone.png"
# define TEXT_SO "../../map/bluestone.png"
# define TEXT_EA "../../map/bluestone.png"
# define TEXT_WE "../../map/bluestone.png"

/*enum color*/
enum e_color
{
	FLOOR,
	CEILING
};

/*enum texture*/
enum e_texture
{
	NO,
	SO,
	WE,
	EA
};

typedef struct s_struct
{
	int		*info;
	int		fd;
	int		*color;
	char	**texture;  //Quid utilité
	int		height;
	int		width;
	char	**map;
}	t_struct;

/*Parsing*/
		/*Pars arg*/
int		ft_memcmp_reverse(char *s1, char *s2);
		/*Principal functions*/
void	init_data_parsing(t_struct *data);
void	clear_after_init(t_struct *data, char *line);
void	exit_map_parsing(t_struct *data, char *msg);
void	parsing(int argc, char **argv, t_struct *data);
void	parsing_color(t_struct *data, char *line, int type);
void	parsing_texture(t_struct *data, char *line, int type);
		/*Pars line*/
int		is_empty_line(char *line);
int		cmp_setting(t_struct *data, char *line, char *type, int value);
char	*is_begin_map(t_struct *data, char *line);
int		every_info(int *info);
int		first_line(char *line, int type);
		/*Par map*/
void	get_height(t_struct *data);
char	*get_map(t_struct *data, char *line);
void 	only_good_char(t_struct *data);
void	update_with_space(t_struct *data);
void	check_border(t_struct *data);
void	check_around_space(t_struct *data);
		/*utils*/
char	**split_line_and_check(t_struct *data, char *line);
void 	get_fd(t_struct *data, char *file);

/*GNL*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	*ft_free(void *save);

/*Global utils*/
int		ft_strcmp(char *s1, char *s2);
int		msg_error(char *msg);


#endif