/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_helpers_I.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:05:26 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/26 18:05:29 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	perror_exit(t_map *map)
{
	if (map)
		free(map);
	perror("");
	exit(EXIT_FAILURE);
}

void	error_exit(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

int	str_arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] && *arr[i] != '\n')
		i++;
	return (i);
}

void	free_str_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

void	*free_null(void *p)
{
	if (p)
		free(p);
	return (NULL);
}
