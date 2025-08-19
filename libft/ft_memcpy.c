/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:36:13 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/20 15:36:56 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*j;

	if (!dst && !src)
		return (NULL);
	p = (unsigned char *)dst;
	j = (const unsigned char *)src;
	while (n)
	{
		*p++ = *j;
		j++;
		n--;
	}
	return (dst);
}
/*

#include <stdio.h>
#include <string.h> 

int	main()
{
 	char src[] = "khaldoun";
 	char dst[] = "xyz";

 	char srcD[] = "khaldoun";
 	char dstD[] = "xyz";

 	char *a;
 	char *b;

 	int num = 1;

 	a = (char *)ft_memcpy(dst, src, num);
 	b = (char *)memcpy(dstD, srcD, num);

 	printf("my:      %s\n", dst);
 	printf("default: %s\n", dstD);

 	printf("%s\n", a);
 	printf("%s\n", b);

}
*/
