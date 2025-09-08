/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_zooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:09:19 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/26 18:09:21 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	center_y(t_point **points, int w, int h)
{
	int	i;
	int	y;
	int	yminmax[2];
	int	offset;

	y_get_min_max(yminmax, points, w, h);
	offset = 0;
	i = 0;
	while (i < h)
	{
		y = 0;
		while (y < w)
		{
			offset = (HEIGHT / 2) - ((yminmax[0] + yminmax[1]) / 2);
			points[i][y].y += offset;
			y++;
		}
		i++;
	}
}

static void	center_x(t_point **points, int w, int h)
{
	int	i;
	int	y;
	int	xminmax[2];
	int	offset;

	x_get_min_max(xminmax, points, w, h);
	offset = 0;
	i = 0;
	while (i < h)
	{
		y = 0;
		while (y < w)
		{
			offset = (WIDTH / 2) - ((xminmax[0] + xminmax[1]) / 2);
			points[i][y].x += offset;
			y++;
		}
		i++;
	}
}

void	center_points(t_point **points, int w, int h)
{
	center_x(points, w, h);
	center_y(points, w, h);
}

static void	zoom_factor(t_point **points, int w, int h)
{
	int		i;
	int		y;
	float	zoom;
	int		yminmax[2];
	int		xminmax[2];

	y_get_min_max(yminmax, points, w, h);
	x_get_min_max(xminmax, points, w, h);
	zoom = fmin((float)HEIGHT / (yminmax[1] - yminmax[0]) / 2, (float)WIDTH
			/ (xminmax[1] - xminmax[0]) / 2);
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

void	zoom_extents(t_point **points, int w, int h)
{
	int	i;
	int	y;
	int	flag;

	flag = 0;
	i = 0;
	while (i < h)
	{
		y = 0;
		while (y < w)
		{
			if (points[i][y].x > WIDTH || points[i][y].y > HEIGHT)
			{
				flag = 1;
				break ;
			}
			y++;
		}
		i++;
	}
	if (flag == 1)
		zoom_factor(points, w, h);
}
