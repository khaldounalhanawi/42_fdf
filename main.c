#include "fdf.h"

static void	checker(int argc, char **argv);
void clear_map(t_map *mymap);

int	main(int argc, char **argv)
{
	t_map	*mymap;
	t_point **points;
	int		h;
	int		w;

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
	w = mymap->width;
	h = mymap->height;
	clear_map (mymap);
	graphics_mlx (points, w, h);
}

// make files fix
// add hook for pressing x

static void	checker(int argc, char **argv)
{
	if (argc != 2)
		error_exit ("Unacceptable number of arguments");
	if (!argv | !argv[1])
		error_exit ("Unavailable fdf file");
}

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