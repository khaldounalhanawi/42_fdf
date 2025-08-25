#include "fdf.h"

int		key_exe(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		mlx_destroy_image(vars->mlx, vars->img);
		clear_points_array (vars->points, vars->height);
		exit (0);
	}
	return (0);
}	

void init_frame(t_data *frame, void *mymlx)
{
	frame->img = mlx_new_image(mymlx, WIDTH, HEIGHT);
	frame->addr = mlx_get_data_addr(frame->img,
							&frame->bits_per_pixel,
							&frame->line_length,
							&frame->endian);
}

void get_min_max(int *minmax, t_point **points, int w, int h)
{
	int	i;
	int	y;

	minmax[0] = points[0][0].x;
	minmax[1] = points[0][0].x;
	i = 0;
	while (i < h)
	{
		y = 0;
		while (y < w)
		{
			if (points[i][y].x < minmax[0])
				minmax[0] = points[i][y].x;
			if (points[i][y].x > minmax[1])
				minmax[1] = points[i][y].x;
			y++;
		}
		i ++;
	}
}

void center_points(t_point **points, int w, int h)
{
	int	i;
	int	y;
	int minmax[2];
	
	get_min_max (minmax, points, w, h);
	int offset = 0;
	i = 0;
		while (i < h)
	{
		y = 0;
		while (y < w)
		{
			offset = (WIDTH / 2) - ((minmax[0] + minmax[1]) / 2);
			points[i][y].x += offset;
			y++;
		}
		i ++;
	}
}

int		graphics_mlx(t_point **points, int w, int h)
{
	void	*mymlx;
	void	*mlx_window;
	t_data	frame;
	t_vars	vars;
	
	mymlx = mlx_init();
	mlx_window = mlx_new_window (mymlx, WIDTH, HEIGHT, "khaldoun");
	init_frame (&frame, mymlx);
	vars.mlx = mymlx;
	vars.window = mlx_window;
	vars.img = frame.img;
	vars.height = h;
	vars.points = points;
	initial_zoom (points, w, h);
	iso_all (points, w, h);
	center_points (points, w, h);
	draw_segments (&frame, points, w, h);
	mlx_put_image_to_window (mymlx, mlx_window, frame.img, 0, 0);
	mlx_key_hook (vars.window, key_exe, &vars);
	mlx_loop (mymlx);
	return (0);
}