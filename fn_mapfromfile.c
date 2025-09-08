/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_mapfromfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:05:43 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/26 18:12:38 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*initiate_map(void);
void			free_grid(t_map *my_map);

t_map	*mapfromfile(char *path)
{
	int		fd;
	t_map	*my_map;

	my_map = initiate_map();
	fd = open(path, O_RDONLY);
	if (fd == -1)
		perror_exit(my_map);
	if (fill_map(fd, my_map) != 0)
	{
		free_grid(my_map);
		free(my_map);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (my_map);
}

static t_map	*initiate_map(void)
{
	t_map	*my_map;

	my_map = malloc(sizeof(t_map));
	if (!my_map)
		perror_exit(NULL);
	my_map->grid = NULL;
	my_map->height = -1;
	my_map->width = -1;
	my_map->z_min = 0;
	my_map->z_max = 0;
	my_map->zoom = 1.0;
	return (my_map);
}

void	free_grid(t_map *my_map)
{
	int	i;

	i = 0;
	if (my_map->grid)
	{
		while (i < my_map->height)
		{
			free((my_map->grid)[i]);
			i++;
		}
		free((my_map->grid));
	}
}
