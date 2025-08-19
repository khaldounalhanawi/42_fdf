#include "fdf.h"

void	get_minmax(t_map *my_map)
{
	int	w;
	int	h;

	my_map->z_min = my_map->grid[0][0];
	my_map->z_max = my_map->grid[0][0];
	h = 0;
	while (h < my_map->height)
	{
		w = 0;
		while (w < my_map->width)
		{
			if (my_map->grid[h][w] > my_map->z_max)
				my_map->z_max = my_map->grid[h][w];
			else if (my_map->grid[h][w] < my_map->z_min)
				my_map->z_min = my_map->grid[h][w];
			w ++;
		}
		h ++;
	}
}