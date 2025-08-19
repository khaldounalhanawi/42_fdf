/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:15:19 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/31 12:15:27 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*record;
	t_list	*cur;

	if (!lst || !del)
		return ;
	cur = *lst;
	while (cur)
	{
		record = cur->next;
		ft_lstdelone(cur, del);
		cur = record;
	}
	*lst = NULL;
}
