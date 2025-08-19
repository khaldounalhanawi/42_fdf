/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:58:22 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/20 15:58:30 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int main()
{
	char a = 'v';
	//char b = 'f';

	int	aa = ft_toupper(a);
	int	bb = toupper(a);

	printf("my :      %c, %d, %c\n", a, aa, aa);
	printf("default : %c, %d, %c\n", a, bb, bb);



}*/
