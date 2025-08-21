#include "fdf.h"

static void assign_point(t_point *points, int h, int w, t_map *my_map)
{
	points->x = w;
	points->y = h;
	points->z = (my_map->grid)[h][w];
}

t_point	**clear_points_array(t_point **points, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		free (points[i]);
		i ++;
	}
	free (points);
	return (NULL);
}

t_point **grid_to_points(t_point **points, t_map *my_map)
{
	int	w;
	int	h;

	points = malloc (sizeof (t_point *) * my_map->height);
	if (!points)
		return (NULL);
	h = 0;
	while (h < my_map->height)
	{
		w = 0;
		points[h] = malloc (sizeof (t_point) * my_map->width);
		if (!points[h])
			return (clear_points_array(points, h));
		while (w < my_map->width)
		{
			assign_point (&points[h][w], h, w, my_map);
			w ++;
		}
		h ++;
	}
	return (points);
}
