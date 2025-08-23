#include "fdf.h"

int	**clear_int_array(int **grid, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		free (grid[i]);
		i ++;
	}
	free (grid);
	return (NULL);
}