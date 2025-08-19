#include "fdf.h"

static void	checker(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_map	*mymap;

	checker (argc, argv);
	mymap = mapfromfile (argv[1]);
	if (!mymap)
		return (-1);
	mymap->zoom = fmin(WIDTH / (mymap->width * 2), HEIGHT / (mymap->height * 2));
	


	// tester
	int	x = 0;
	int	y = 0;

	printf ("zoom is %f\n", mymap->zoom);
	printf ("width is %d\n", mymap->width);
	printf ("height is %d\n", mymap->height);
	printf ("min is %d\n", mymap->z_min);
	printf ("max is %d\n", mymap->z_max);

	while (y < mymap->height)
	{
		x = 0;
		while (x < mymap->width)
		{
			printf ("%d ", mymap->grid[y][x]);
			x ++;
		}
		printf ("\n");
		y ++;
	}

}

static void	checker(int argc, char **argv)
{
	if (argc != 2)
		error_exit ("Unacceptable number of arguments");
	if (!argv | !argv[1])
		error_exit ("Unavailable fdf file");
}