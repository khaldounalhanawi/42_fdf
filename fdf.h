#ifndef FDF_H
# define FDF_H
# define ANGLE 40
# define WIDTH 800
# define HEIGHT 600
# define HEIGHT_SCALE 2
#define ESC_KEY 53	// ESC keycode on macOS

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	int		**grid;
	int		z_min;
	int		z_max;
	float	zoom;
} t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*window;
}	t_vars;

void	free_str_arr(char **str);
void	perror_exit(t_map *map);
void	error_exit(char *str);
int		str_arr_size (char	**arr);
void *free_null(void *p);
t_map	*mapfromfile(char *path);
int		fill_map (int fd, t_map *my_map);
void	get_minmax(t_map *my_map);
t_point	**clear_points_array(t_point **points, int h);
t_point **grid_to_points(t_point **points, t_map *my_map);
int		graphics_mlx(t_point **points, int w, int h);



#endif