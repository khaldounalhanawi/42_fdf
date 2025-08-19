/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:57:52 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/20 15:58:01 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += ('a' - 'A');
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int main()
{
	char a = 'Z';
	//char b = 'f';

	int	aa = ft_tolower(a);
	int	bb = tolower(a);

	printf("my :      %c, %d, %c\n", a, aa, aa);
	printf("default : %c, %d, %c\n", a, bb, bb);



}*/
