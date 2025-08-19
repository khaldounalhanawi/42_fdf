/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:29:06 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/24 12:16:48 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	unsigned char	*v;
	size_t			all_bytes;

	if (count == 0 || size == 0)
		return (malloc(1));
	if (size > SIZE_MAX / count)
		return (NULL);
	all_bytes = count * size;
	p = malloc(all_bytes);
	if (!p)
		return (NULL);
	v = (unsigned char *)p;
	while (all_bytes--)
	{
		*v = 0;
		v++;
	}
	return (p);
}
/*
#include <stdio.h>


int main()
{
	// size_t size = 0;
	size_t size = 0;
	size_t count = 10;

	int *a = ft_calloc(count,size);
	int *b = calloc(count,size);

	int *start_a = a;
	int *start_b = b;

	a[1] = 4;
	b[1] = 4;

	int i = 0;
	while (i < count)
	{
		printf("my:      %d\t", *((int *)a));
		printf("%p, %zu\n", a, sizeof(a));
		a++;
		i++;
	}
	printf("\n\n");
	i = 0;
	while (i < count)
	{
		printf("default: %d\t", *((int *)b));
		printf("%p, %zu\n", b, sizeof(b));
		b++;
		i++;
	}

	free(start_a);
	free(start_b);
	return (0);
}
 */
