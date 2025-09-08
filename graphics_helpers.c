/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:07:35 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/26 18:14:32 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *frame, t_point a, int color)
{
	void	*target;

	if (a.x > WIDTH || a.y > HEIGHT || a.x < 0 || a.y < 0)
		return ;
	target = frame->addr + (a.y * (frame->line_length) + a.x
			* (frame->bits_per_pixel / 8));
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

void	x_get_min_max(int *minmax, t_point **points, int w, int h)
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
		i++;
	}
}

void	y_get_min_max(int *minmax, t_point **points, int w, int h)
{
	int	i;
	int	y;

	minmax[0] = points[0][0].y;
	minmax[1] = points[0][0].y;
	i = 0;
	while (i < h)
	{
		y = 0;
		while (y < w)
		{
			if (points[i][y].y < minmax[0])
				minmax[0] = points[i][y].y;
			if (points[i][y].y > minmax[1])
				minmax[1] = points[i][y].y;
			y++;
		}
		i++;
	}
}
