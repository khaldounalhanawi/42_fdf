/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:12:08 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/31 12:12:19 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*ft_lstclear2(t_list **lst, void (*del)(void*))
{
	t_list	*record;
	t_list	*cur;

	if (!lst || !del)
		return (NULL);
	cur = *lst;
	while (cur)
	{
		record = cur->next;
		ft_lstdelone(cur, del);
		cur = record;
	}
	*lst = NULL;
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*f_content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		f_content = f(lst->content);
		if (!f_content)
			return (ft_lstclear2(&new_list, del));
		new_node = ft_lstnew(f_content);
		if (!new_node)
		{
			del(f_content);
			return (ft_lstclear2(&new_list, del));
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
