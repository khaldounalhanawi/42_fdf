/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:00:13 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/13 18:00:39 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'));
}
/*
#include <stdio.h>
#include <ctype.h>
int	main()
{	
	char a = 'p';

	printf("my %d\n", ft_isalnum(a));
	printf("default %d\n", isalnum(a));
	return (0);

}

*/
