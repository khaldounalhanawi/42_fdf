/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:42:28 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/24 12:42:53 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd (*s, fd);
		s++;
	}
	ft_putchar_fd ('\n', fd);
}
/*
int main()
{

	char str[] = "asd";

	ft_putendl_fd(str,1);
}*/
