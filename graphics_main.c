#include "fdf.h"

void	my_mlx_pixel_put(t_data *frame, t_point a, int color)
{
	void	*target;

	target = frame->addr + (a.y * (frame->line_length) +
							a.x * (frame->bits_per_pixel / 8));
	*(int *)target = color;
}

void flip(t_point *a, t_point *b)
{
	t_point	c;

	c.x = a->x;
	c.y = a->y;
	a->x = b->x;
	a->y = b->y;
	b->x = c.x;
	b->y = c.y;
	return ;
}

void	draw_line_h(t_data *frame, t_point a, t_point b, int color)
{
	int	dx;
	int	dy;
	int	dir;
	int	y;
	int	p;
	int	i;
	t_point temp;

	if (a.x > b.x)
		flip (&a, &b);
	dx = b.x - a.x;
	dy = b.y - a.y;
	dir = 1;
	if (dy < 0)
		dir = -1;
	dy *= dir;
	// if (dx == 0)
	// {
	// 	// write (1, "V line as H", 13);
	// 	return ;
	// }
	y = a.y;
	p = 2 * dy - dx;
	i = 0;
	while (i < dx)
	{
		temp.x = a.x + i;
		temp.y = y;
		my_mlx_pixel_put (frame, temp, color);
		if (p > 0)
		{
			y += dir;
			p -= 2 * dx;
		}
		p += 2 * dy;

		i ++;
	}
	my_mlx_pixel_put (frame, b, color);

}

void	draw_line_v(t_data *frame, t_point a, t_point b, int color)
{
	int	dx;
	int	dy;
	int	dir;
	int	x;
	int	p;
	int	i;
	t_point temp;

	if (a.y > b.y)
		flip (&a, &b);
	dx = b.x - a.x;
	dy = b.y - a.y;
	dir = 1;
	if (dx < 0)
		dir = -1;
	dx *= dir;
	// if (dy == 0)
	// {
	// 	// write (1, "V line as H", 13);
	// 	return ;
	// }
	x = a.x;
	p = 2 * dx - dy;
	i = 0;
	while (i < dy)
	{
		temp.y = a.y + i;
		temp.x = x;
		my_mlx_pixel_put (frame, temp, color);
		if (p > 0)
		{
			x += dir;
			p -= 2 * dy;
		}
		p += 2 * dx;

		i ++;
	}
	my_mlx_pixel_put (frame, b, color);

}

void	draw_line(t_data *frame, t_point a, t_point b, int color)
{
	if (abs (b.x - a.x) > abs (b.y - a.y))
		draw_line_h (frame, a, b, color);
	else
		draw_line_v (frame, a, b, color);
}

int key_exe(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(vars->mlx, vars->window);
		exit (0);
	}
	return (0);
}	

void	iso(t_point *a)
{
	t_point	c;
	float	angle_rad;

	angle_rad = ANGLE * M_PI / 180.0;
	c.x = a->x;
	c.y = a->y;
	a->x = (c.x - c.y) * cos (angle_rad);
	a->y = (c.x + c.y) * sin (angle_rad) - (a->z * HEIGHT_SCALE);
	a->x += WIDTH / 2;
	a->y += HEIGHT / 4;
}

void initial_zoom(t_point **points, int w, int h, int zoom)
{
	int	i;
	int	y;

	i = 0;
	while (i < h)
	{
		y = 0;
		while (y < w)
		{
			points[i][y].x *= zoom;
			points[i][y].y *= zoom;
			y ++;
		}
		i ++;
	}
}

void iso_all(t_point **points, int w, int h)
{
	int	i;
	int	y;

	i = 0;
	while (i < h)
	{
		y = 0;
		while (y < w)
		{
			iso (&points[i][y]);
			y ++;
		}
		i ++;
	}
}

int	graphics_mlx(t_point **points, int w, int h)
{
	void	*mlx_connection;
	void	*mlx_window;
	int		zoom;
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


	zoom = fmin(WIDTH / (w * 2), HEIGHT / (h * 2));
	if (zoom < 1)
		zoom = 1;
	initial_zoom (points, w, h, zoom);
	iso_all (points, w, h);

	int r = 0;
	int	c;
	
	// grid body
	while (r + 1< h)
	{
		c = 0;
		while (c + 1< w)
		{
			draw_line (&frame, points[r][c], points[r][c + 1], 0x0000ff);
			draw_line (&frame, points[r][c], points[r + 1][c], 0x0000ff);

			my_mlx_pixel_put (&frame, points[r][c], 0xffff00);
			my_mlx_pixel_put (&frame, points[r][c + 1], 0xffff00);
			c ++;
		}
		r ++;
	}

	// h edge
	r = 0;
	while (r + 1< h)
	{
		draw_line (&frame, points[r][c], points[r + 1][c], 0x0000ff);
		my_mlx_pixel_put (&frame, points[r][c], 0xffff00);

		r ++;
	}

	// r edge
	c = 0;
	while (c + 1< w)
	{
		draw_line (&frame, points[r][c], points[r][c + 1], 0x0000ff);
		my_mlx_pixel_put (&frame, points[r][c], 0xffff00);
		c ++;
	}

	// last point
	my_mlx_pixel_put (&frame, points[r][c], 0xffff00);





	mlx_put_image_to_window (mlx_connection, mlx_window, frame.img, 0, 0);
	mlx_key_hook (vars.window, key_exe, &vars);
	mlx_loop (mlx_connection);
	
	printf ("test point = %d\n", (points[2][2]).z);
	return (0);
	
}