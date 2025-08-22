#include "fdf.h"

void	my_mlx_pixel_put(t_data *frame, t_point a, int color)
{
	void	*target;

	target = frame->addr + (a.y * (frame->line_length) +
							a.x * (frame->bits_per_pixel / 8));
	*(int *)target = color;
}

void	flip(t_point *a, t_point *b)
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
