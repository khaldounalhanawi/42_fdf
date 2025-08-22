#include "fdf.h"

static void	checker(int argc, char **argv);
void clear_map(t_map *mymap)
{
	int	i;

	i = 0;
	while (mymap->grid[i])
	{
		free (mymap->grid[i]);
		i ++;
	}
	free (mymap);
}

int	main(int argc, char **argv)
{
	t_map	*mymap;
	t_point **points;

	checker (argc, argv);
	mymap = mapfromfile (argv[1]);
	if (!mymap)
		return (-1);
	points = NULL;
	points = grid_to_points (points, mymap);
	if (!points)
	{
		clear_map (mymap);
		return (-1);
	}
	graphics_mlx (points, mymap->width, mymap->height);
	clear_points_array (points, mymap->height);
	clear_map (mymap);
}

static void	checker(int argc, char **argv)
{
	if (argc != 2)
		error_exit ("Unacceptable number of arguments");
		// check if it is executable ??
	if (!argv | !argv[1])
		error_exit ("Unavailable fdf file");
}