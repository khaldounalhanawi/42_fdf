#include "fdf.h"

static void	checker(int argc, char **argv);

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
		free (mymap); // free everything
		return (-1);
	}
	graphics_mlx (points, mymap->width, mymap->height);
}

static void	checker(int argc, char **argv)
{
	if (argc != 2)
		error_exit ("Unacceptable number of arguments");
	if (!argv | !argv[1])
		error_exit ("Unavailable fdf file");
}