/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_draw_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:06:08 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/26 18:06:10 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_math_h(t_lmath *lmath, t_point a, t_point b)
{
	lmath->dx = b.x - a.x;
	lmath->dy = b.y - a.y;
	lmath->dir = 1;
	if (lmath->dy < 0)
		lmath->dir = -1;
	lmath->dy *= lmath->dir;
	lmath->p = 2 * lmath->dy - lmath->dx;
}

static void	draw_line_h(t_data *frame, t_point a, t_point b, int color)
{
	int		i;
	t_lmath	lmath;
	t_point	temp;

	if (a.x > b.x)
		flip(&a, &b);
	get_math_h(&lmath, a, b);
	i = 0;
	while (i < lmath.dx)
	{
		temp.x = a.x + i;
		temp.y = a.y;
		my_mlx_pixel_put(frame, temp, color);
		if (lmath.p > 0)
		{
			a.y += lmath.dir;
			lmath.p -= 2 * lmath.dx;
		}
		lmath.p += 2 * lmath.dy;
		i++;
	}
	my_mlx_pixel_put(frame, b, color);
}

static void	get_math_v(t_lmath *lmath, t_point a, t_point b)
{
	lmath->dx = b.x - a.x;
	lmath->dy = b.y - a.y;
	lmath->dir = 1;
	if (lmath->dx < 0)
		lmath->dir = -1;
	lmath->dx *= lmath->dir;
	lmath->p = 2 * lmath->dx - lmath->dy;
}

static void	draw_line_v(t_data *frame, t_point a, t_point b, int color)
{
	int		i;
	t_lmath	lmath;
	t_point	temp;

	if (a.y > b.y)
		flip(&a, &b);
	get_math_v(&lmath, a, b);
	i = 0;
	while (i < lmath.dy)
	{
		temp.y = a.y + i;
		temp.x = a.x;
		my_mlx_pixel_put(frame, temp, color);
		if (lmath.p > 0)
		{
			a.x += lmath.dir;
			lmath.p -= 2 * lmath.dy;
		}
		lmath.p += 2 * lmath.dx;
		i++;
	}
	my_mlx_pixel_put(frame, b, color);
}

void	draw_line(t_data *frame, t_point a, t_point b, int color)
{
	if (abs(b.x - a.x) > abs(b.y - a.y))
	{
		if (a.z > 0 && b.z > 0)
			draw_line_h(frame, a, b, color);
		else
			draw_line_h(frame, a, b, color);
	}
	else
	{
		if (a.z > 0 && b.z > 0)
			draw_line_v(frame, a, b, color);
		else
			draw_line_v(frame, a, b, color);
	}
}
