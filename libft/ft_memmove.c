/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:37:33 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/20 15:37:47 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p;
	const unsigned char	*j;

	if (!dst && !src)
		return (NULL);
	p = (unsigned char *)dst;
	j = (const unsigned char *)src;
	if (dst < src)
	{
		while (len--)
			*p++ = *j++;
	}
	else
	{
		p += len;
		j += len;
		while (len--)
			*--p = *--j;
	}
	return (dst);
}
/*

#include <stdio.h>
#include <string.h> 

int	main()
{
 	char src[] = "khaldoun";
 	char dst[] = "123xyz";

 	char srcD[] = "khaldoun";
 	char dstD[] = "123xyz";

 	char *a;
 	char *b;

 	int num = 4;

 	a = (char *)ft_memmove(&dst[2], dst, num);
 	b = (char *)memmove(&dstD[2], dstD, num);

 	printf("my:      %s\n", dst);
 	printf("default: %s\n", dstD);

 	printf("%s\n", a);
 	printf("%s\n", b);

}
*/
