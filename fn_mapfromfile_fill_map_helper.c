/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_mapfromfile_fill_map_helper.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:06:01 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/09/01 14:48:05 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drain_gnl(int fd, char *p)
{
	char	*str;

	str = NULL;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
	if (p)
		free(p);
	return ;
}

t_list	*lstclear_nfree(t_list **head_row, t_list *p)
{
	ft_lstclear(head_row, free);
	if (p)
		free(p);
	return (NULL);
}
