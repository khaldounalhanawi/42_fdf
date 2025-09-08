/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:08:54 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/09/01 14:26:02 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	checker(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_map	*mymap;
	t_point	**points;
	int		h;
	int		w;

	checker(argc, argv);
	mymap = mapfromfile(argv[1]);
	if (!mymap)
		return (-1);
	points = NULL;
	points = grid_to_points(points, mymap);
	if (!points)
	{
		free_grid(mymap);
		free(mymap);
		return (-1);
	}
	w = mymap->width;
	h = mymap->height;
	free_grid(mymap);
	free(mymap);
	graphics_mlx(points, w, h);
}

static void	checker(int argc, char **argv)
{
	if (argc != 2)
		error_exit("Unacceptable number of arguments");
	if (!argv | !argv[1])
		error_exit("Unavailable fdf file");
}
