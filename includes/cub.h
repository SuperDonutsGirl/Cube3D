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
# include "../src/libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <math.h>
//# include "../mlx/mlx.h"
# include </usr/X11/include/mlx.h> //Path de la minilibx Pauline
# include "keycodes.h"

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

/*Define MATH */
# define PI	3.141592653589793238
# define P2  1.57079632679
# define P3  4.71238898038
# define DR  0.0174533

# define SOUTH  1.57079632679
# define NORTH  4.71238898038
# define WEST	PI
# define EAST	6.28318530718

/*Enum pos*/
enum e_position
{
	X,
	Y,
	DIST
};

/*Enum type*/
enum e_type
{
	HORIZONTAL,
	VERTICAL
};

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

typedef struct s_key
{
	int w;
	int	a;
	int s;
	int d;
	int right;
	int left;
}	t_key;

typedef struct s_player
{
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	float	pa;
}	t_player;

typedef struct s_cube
{
	void		*mlx;
	void		*window;

	void		*img;
	char		*address;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	int			pos_x;
	int			pos_y;

	t_player	player;
}	t_cube;

typedef struct s_struct
{
	int		*info;
	int		fd;
	int		*color;
	char	**texture;
	double	*player;
	size_t	height;
	size_t	width;
	float	map_s;
	size_t	mini_s;
	char	**map;
	int		*int_map;
	t_cube	*cube;
	t_key	key;
}	t_struct;

/*Parsing*/
		/*Pars arg*/
int		ft_memcmp_reverse(char *s1, char *s2);
		/*Principal functions*/
void	init_data_parsing(t_struct *data);
void	clear_after_init(t_struct *data, char *line);
void	exit_map_parsing(t_struct *data, char *msg, char *line);
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
void	only_good_char(t_struct *data);
int		good_char(char c);
void	update_with_space(t_struct *data);
void	check_border(t_struct *data);
void	check_around_space(t_struct *data);
void	check_player(t_struct *data, char elmt, int y, int x);
		/*utils*/
char	**split_line_and_check(t_struct *data, char *line);
void	get_fd(t_struct *data, char *file);

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

//Raccourcis clavier
int		close_on_click(int keycode);
int		keypress(int keycode, t_struct *data);

//Draw
void	draw_player(t_struct *data, int color, int size_player);
void	draw_mini_map(t_struct *data);
void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color);
void	draw_map_2d(t_struct *data);
void	drawline(t_cube *cube, int color, float x, float y);

//Raycasting
void	bresenham(t_struct *data, float ox, float oy, float *r);
float	dist(float ax, float ay, float bx, float by);
int		*dof_vertical(t_struct *data, float *ray, float *o, float ra);
int		*dof_horizontal(t_struct *data, float *ray, float *o, float ra);
void	draw_rays(t_struct *data);

//3D
void	bresenham3d(t_struct *data, float ox, float oy, float rx, float ry, int color);



int keyrelease(int keycode, t_struct *data);
int	keypress(int keycode, t_struct *data);

#endif
