/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:38:59 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/24 16:57:20 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char) c;
	if (ch == '\0')
	{
		while (*s != ch)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
/* 

#include <stdio.h>
#include <string.h>

int main()
{
	char txt[] = "teste";
	char txt2[] = "teste";
	// char txt[] = {'k', 'h','a', '\0', 'a'};
	char c = 'e';

	printf("my :      %p, %s, %p\n", txt, ft_strchr(txt,c), ft_strchr(txt,c));
	printf("default : %p, %s, %p\n", txt2,strchr(txt2,c), strchr(txt2,c));



}
 */