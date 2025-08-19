/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:38:13 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/20 15:38:30 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len)
	{
		*p++ = c;
		len--;
	}
	return (b);
}
/*


#include <stdio.h>
#include <string.h>

int	main()
{	
	char a[] = "khal";
	char b[] = "khal";

	ft_memset(a,'#', 3);
	memset(b, '#', 3);

	printf("mine:    %s\n", a);
	printf("default: %s\n", b);
	return (0);

}
*/
	// unsigned char *p;
	// void *origin;

	// origin = b;
	// while (len)
	// {
	// 	p = (unsigned char *)b;
	// 	*p = c;
	// 	b++;
	// 	len--;
	// }
	// return (origin);
