#include "fdf.h"

int		key_exe(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(vars->mlx, vars->window);
		exit (0);
	}
	return (0);
}	

int		graphics_mlx(t_point **points, int w, int h)
{
	void	*mlx_connection;
	void	*mlx_window;
	t_data	frame;
	t_vars	vars;
	
	mlx_connection = mlx_init();
	mlx_window = mlx_new_window (mlx_connection, WIDTH, HEIGHT, "khaldoun");
	frame.img = mlx_new_image(mlx_connection, WIDTH, HEIGHT);
	frame.addr = mlx_get_data_addr(frame.img,
							&frame.bits_per_pixel,
							&frame.line_length,
							&frame.endian);
	vars.mlx = mlx_connection;
	vars.window = mlx_window;
	initial_zoom (points, w, h);
	iso_all (points, w, h);
	draw_segments (&frame, points, w, h);
	mlx_put_image_to_window (mlx_connection, mlx_window, frame.img, 0, 0);
	mlx_key_hook (vars.window, key_exe, &vars);
	mlx_loop (mlx_connection);
	return (0);
}