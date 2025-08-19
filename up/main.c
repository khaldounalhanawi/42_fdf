#include "minilibx_macos/mlx.h"
#include "stdio.h"
#include <stdlib.h>
#include "unistd.h"
#include <math.h>


#define width 400
#define height 400

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

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
	if (dx == 0)
	{
		write (1, "V line as H", 13);
		return ;
	}
	y = a.y;
	p = 2 * dy - dx;
	i = 0;
	while (i <= dx)
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
	if (dy == 0)
	{
		write (1, "V line as H", 13);
		return ;
	}
	x = a.x;
	p = 2 * dx - dy;
	i = 0;
	while (i <= dy)
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

void	iso(t_point *a)
{
	t_point	c;
	float	angle_rad;

	angle_rad = 30 * M_PI / 180.0;

	c.x = a->x;
	c.y = a->y;

	a->x = (c.x - c.y) * cos (angle_rad);
	a->y = (c.x + c.y) * sin (angle_rad) - a->z;

	a->x += width / 2;
	a->y += height / 4;
	
}

int	main()
{
	void	*mlx_connection;
	void	*mlx_window;
	t_data	frame;
	t_point	a;
	t_point	b;
	t_point	c;
	t_point	d;


	mlx_connection = mlx_init();
	mlx_window = mlx_new_window (mlx_connection, width, height, "khaldoun");
	frame.img = mlx_new_image(mlx_connection, width, height);
	frame.addr = mlx_get_data_addr(frame.img,
							&frame.bits_per_pixel,
							&frame.line_length,
							&frame.endian);

	a.x = 100;
	a.y = 100;
	a.z = 0;

	b.x = 200;
	b.y = 100;
	b.z = 0;
	
	c.x = 100;
	c.y = 200;
	c.z = 0;
	
	d.x = 200;
	d.y = 200;
	d.z = 0;

	iso (&a);
	iso (&b);
	iso (&c);
	iso (&d);

	draw_line (&frame, a, b, 0x0000ff);
	draw_line (&frame, b, d, 0x0000ff);
	draw_line (&frame, d, c, 0x0000ff);
	draw_line (&frame, c, a, 0x0000ff);

	my_mlx_pixel_put (&frame, a, 0xffff00);
	my_mlx_pixel_put (&frame, b, 0xffff00);
	my_mlx_pixel_put (&frame, c, 0xffff00);
	my_mlx_pixel_put (&frame, d, 0xffff00);


	mlx_put_image_to_window (mlx_connection, mlx_window, frame.img, 0, 0);
	mlx_loop (mlx_connection);

	
}