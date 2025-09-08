/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_projections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:09:34 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/26 18:09:37 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(t_point *a)
{
	t_point	c;
	float	angle_rad;

	angle_rad = ANGLE * M_PI / 180.0;
	c.x = a->x;
	c.y = a->y;
	a->x = (c.x - c.y) * cos(angle_rad);
	a->y = (c.x + c.y) * sin(angle_rad) - (a->z * HEIGHT_SCALE);
	a->x += WIDTH / 2;
	a->y += HEIGHT / 4;
}

void	initial_zoom(t_point **points, int w, int h)
{
	int	i;
	int	y;
	int	zoom;

	zoom = fmin(WIDTH / (w * 2), HEIGHT / (h * 2));
	if (zoom < 1)
		zoom = 1;
	i = 0;
	while (i < h)
	{
		y = 0;
		while (y < w)
		{
			points[i][y].x *= zoom;
			points[i][y].y *= zoom;
			y++;
		}
		i++;
	}
}

void	iso_all(t_point **points, int w, int h)
{
	int	i;
	int	y;

	i = 0;
	while (i < h)
	{
		y = 0;
		while (y < w)
		{
			iso(&points[i][y]);
			y++;
		}
		i++;
	}
}
