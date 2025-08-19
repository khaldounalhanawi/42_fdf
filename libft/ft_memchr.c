/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:33:19 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/20 15:34:01 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	pc;

	p = (unsigned char *)s;
	pc = (unsigned char)c;
	while (n--)
	{
		if (*p == pc)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "sd áasd";
	char a = 'd';
	size_t N = 8;

	printf("my:      %s\n", (char *)ft_memchr(str,a,N));
	printf("default: %s\n", (char *)memchr(str,a,N));
}*/
