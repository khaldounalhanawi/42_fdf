/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:38:15 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/13 18:38:17 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return ((c >= 32 && c <= 126));
}
/*
#include <stdio.h>
#include <ctype.h>
int	main()
{	
	char a = '5';

	printf("my %d\n", ft_isprint(a));
	printf("default %d\n", isprint(a));
	return (0);

}
*/
