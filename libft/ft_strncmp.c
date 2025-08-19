/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:46:34 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/20 15:48:34 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	val;

	val = 0;
	while (n--)
	{
		val = ((unsigned char)*s1 - (unsigned char)*s2);
		if (!*s2 || !*s1 || *s1 != *s2)
			return (val);
		s1++;
		s2++;
	}
	return (val);
}
/*
#include <stdio.h>
#include <string.h>

int 	main()
{

	char a[] = " ";
	char b[] = "";
	size_t n = 1;

	printf("my:      %d\n", ft_strncmp(a,b,n));
	printf("default: %d\n", strncmp(a,b,n));

	return (0);
}*/
