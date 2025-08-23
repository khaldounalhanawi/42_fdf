#include "fdf.h"


int	*atoi_arr(char **str_arr, t_map *my_map);
int	fill_row_vals(int fd, t_list *head_row, t_map *my_map);
t_list *create_row_llist(int fd, t_map *my_map);
int	**populate_grid(t_list *row_list, t_map *my_map);

int fill_map (int fd, t_map *my_map)
{
	t_list *row_list;

	row_list = create_row_llist (fd, my_map);
	if (!row_list)
		return (-1);
	my_map->height = ft_lstsize (row_list);
	my_map->grid = populate_grid (row_list, my_map);
	if (!my_map->grid)
	{
		ft_lstclear (&row_list, free);
		return (-1);
	}
	ft_lstclear (&row_list, free);
	get_minmax (my_map);
	return (0);
}

int	*atoi_arr(char **str_arr, t_map *my_map)
{
	int	i;
	int	size;
	int	*int_array;

	size = str_arr_size (str_arr);
	if (my_map->width == -1)
		my_map->width = size;
	else if (size != my_map->width)
	{
		write (2, "fdf lines do not match in width\n", 32);
		return (NULL);
	}
	int_array = malloc (sizeof (int) * size);
	if (!int_array)
		return (NULL);
	i = 0;
	while (str_arr[i] && *str_arr[i] != '\n')
	{
		int_array[i] = ft_atoi (str_arr[i]);
		i ++;
	}
	return (int_array);
}

int fill_row_vals(int fd, t_list *head_row, t_map *my_map)
{
	char	*row_str;
	char	**temp_str_arr;

	row_str = get_next_line (fd);
	if (!row_str)
		return (-1);
	temp_str_arr = ft_split (row_str, ' ');
	if (!temp_str_arr)
		{
			free (row_str);
			return (-1);
		}
	head_row->content = atoi_arr (temp_str_arr, my_map);
	if (!head_row->content)
		{
			free_str_arr (temp_str_arr);
			free (row_str);
			return (-1);
		}
	free_str_arr (temp_str_arr);
	free (row_str);
	return (0);
}

t_list *create_row_llist(int fd, t_map *my_map)
{
	t_list *head_row;
	t_list *next_row;

	head_row = NULL;
	while (1)
	{
		next_row = ft_lstnew (NULL);
		if (!next_row)
		{
			ft_lstclear (&head_row, free);
			return (NULL);
		}
		if (fill_row_vals (fd, next_row, my_map) != 0)
		{
			free (next_row);
			break;
		}
		else
			ft_lstadd_back (&head_row, next_row);
	}
	return (head_row);
}

int	**populate_grid(t_list *row_list, t_map *my_map)
{
	int	**grid;
	int	x;
	int	y;

	grid = malloc (sizeof (int *) * my_map->height);
	if (!grid)
		return (NULL);
	x = 0;
	while (x < my_map->height)
	{
		grid[x] = malloc (sizeof (int) * my_map->width);
		if (!grid[x])
			return (clear_int_array (grid, x));
		y = -1;
		while (++y < my_map->width)
			grid[x][y] = ((int *)row_list->content)[y];
		row_list = row_list->next;
		x ++;
	}
	return (grid);
}
