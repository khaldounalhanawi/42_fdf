/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:07:38 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/26 18:15:10 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	mlx_destroy_image(vars->mlx, vars->img);
	clear_points_array(vars->points, vars->height);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	key_exe(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		mlx_destroy_image(vars->mlx, vars->img);
		clear_points_array(vars->points, vars->height);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	return (0);
}

void	init_frame(t_data *frame, void *mymlx)
{
	frame->img = mlx_new_image(mymlx, WIDTH, HEIGHT);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bits_per_pixel,
			&frame->line_length, &frame->endian);
}

void	project_points(t_point **points, int w, int h)
{
	initial_zoom(points, w, h);
	iso_all(points, w, h);
	center_points(points, w, h);
	zoom_extents(points, w, h);
	center_points(points, w, h);
}

int	graphics_mlx(t_point **points, int w, int h)
{
	void	*mymlx;
	void	*mlx_window;
	t_data	frame;
	t_vars	vars;

	mymlx = mlx_init();
	mlx_window = mlx_new_window(mymlx, WIDTH, HEIGHT, "khaldoun");
	init_frame(&frame, mymlx);
	vars.mlx = mymlx;
	vars.window = mlx_window;
	vars.img = frame.img;
	vars.height = h;
	vars.points = points;
	project_points(points, w, h);
	draw_segments(&frame, points, w, h);
	mlx_put_image_to_window(mymlx, mlx_window, frame.img, 0, 0);
	mlx_key_hook(vars.window, key_exe, &vars);
	mlx_hook(vars.window, 17, 0L, close_window, &vars);
	mlx_loop(mymlx);
	return (0);
}
