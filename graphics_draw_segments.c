#include "fdf.h"

static int	draw_body(t_data *frame, t_point **points, int w, int h)
{
	int r = 0;
	int	c;
	
	while (r + 1 < h)
	{
		c = 0;
		while (c + 1< w)
		{
			draw_line (frame, points[r][c], points[r][c + 1], 0x0000ff);
			draw_line (frame, points[r][c], points[r + 1][c], 0x0000ff);
			my_mlx_pixel_put (frame, points[r][c], 0xffff00);
			my_mlx_pixel_put (frame, points[r][c + 1], 0xffff00);
			c ++;
		}
		r ++;
	}
	return (c);
}

void	draw_segments(t_data *frame, t_point **points, int w, int h)
{
	int r = 0;
	int	c;

	c = draw_body (frame, points, w, h);
	while (r + 1< h)
	{
		draw_line (frame, points[r][c], points[r + 1][c], 0x0000ff);
		my_mlx_pixel_put (frame, points[r][c], 0xffff00);
		r ++;
	}
	c = 0;
	while (c + 1< w)
	{
		draw_line (frame, points[r][c], points[r][c + 1], 0x0000ff);
		my_mlx_pixel_put (frame, points[r][c], 0xffff00);
		c ++;
	}
	my_mlx_pixel_put (frame, points[r][c], 0xffff00);	
}