/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:34:26 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/20 15:35:34 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *) s1;
	b = (const unsigned char *) s2;
	while (n--)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}
/*

#include <string.h>
#include <stdio.h>

int main()
{
	char a[] = "obc";
	char b[] = "óbc";
	size_t N = 5;

	printf("my:         %d\n", ft_memcmp(a,b,N));
	printf("default:    %d\n", memcmp(a,b,N));

	return (0);

}*/
