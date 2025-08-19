/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:43:32 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/20 15:44:37 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	num;
	size_t	num_src;

	num = 0;
	num_src = 0;
	while (dst[num])
		num++;
	while (src[num_src])
		num_src++;
	if (dstsize > num)
	{
		num_src += num;
		dstsize -= num;
		while (*dst)
			dst++;
		while (--dstsize && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	else
	{
		num_src = num_src + dstsize;
	}
	return (num_src);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	char a[3] = "asd";
	char b[] = "123";

	char aD[3] = "asd";
	char bD[] = "123";

	size_t dstsize = 2;

	int my  = (int)ft_strlcat(a,b,dstsize);
	int def = (int)strlcat(aD,bD,dstsize);

	printf("my:        %s\n", a);
	printf("default:   %s\n", aD);	

	printf("%d\n", my);
	printf("%d\n", def);

}
*/
