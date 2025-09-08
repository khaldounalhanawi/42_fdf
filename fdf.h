/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:48:13 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/09/01 14:48:06 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ANGLE 40
# define WIDTH 1500
# define HEIGHT 800
# define HEIGHT_SCALE 1
# define ESC_KEY 65307
# define M_PI 3.14159265358979323846

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}			t_point;

typedef struct s_map
{
	int		width;
	int		height;
	int		**grid;
	int		z_min;
	int		z_max;
	float	zoom;
}			t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	int		height;
	void	*mlx;
	void	*window;
	void	*img;
	t_point	**points;
}			t_vars;

typedef struct s_lmath
{
	int		dx;
	int		dy;
	int		dir;
	int		p;
}			t_lmath;

void		free_str_arr(char **str);
void		perror_exit(t_map *map);
void		error_exit(char *str);
int			str_arr_size(char **arr);
void		*free_null(void *p);
t_map		*mapfromfile(char *path);
int			fill_map(int fd, t_map *my_map);
t_point		**clear_points_array(t_point **points, int h);
t_point		**grid_to_points(t_point **points, t_map *my_map);
int			graphics_mlx(t_point **points, int w, int h);
void		my_mlx_pixel_put(t_data *frame, t_point a, int color);
void		flip(t_point *a, t_point *b);
void		draw_line(t_data *frame, t_point a, t_point b, int color);
void		initial_zoom(t_point **points, int w, int h);
void		iso_all(t_point **points, int w, int h);
void		draw_segments(t_data *frame, t_point **points, int w, int h);
int			**int_clear_int_array(int **grid, int h);
void		free_grid(t_map *my_map);
void		center_points(t_point **points, int w, int h);
void		zoom_extents(t_point **points, int w, int h);
void		x_get_min_max(int *minmax, t_point **points, int w, int h);
void		y_get_min_max(int *minmax, t_point **points, int w, int h);
void		drain_gnl(int fd, char *p);
t_list		*lstclear_nfree(t_list **head_row, t_list *p);

#endif
