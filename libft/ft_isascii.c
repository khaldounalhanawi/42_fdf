/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:21:56 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/13 18:21:58 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}
/*
#include <stdio.h>
#include <ctype.h>
int	main()
{	
	//char a = 'é';

	printf("my %d\n", ft_isascii('0'));
	printf("default %d\n", isascii('0'));
	return (0);

}
*/
