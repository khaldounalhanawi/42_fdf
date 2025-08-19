/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:06:02 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/29 18:06:30 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_item)
{
	t_list	*cur;

	if (!new_item || !lst)
		return ;
	if (!(*lst))
	{
		*lst = new_item;
		return ;
	}
	cur = (*lst);
	while (cur->next)
		cur = cur->next;
	cur->next = new_item;
}
