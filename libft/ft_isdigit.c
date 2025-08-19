/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:20:46 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/13 17:20:50 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main()
{	
	char a = '1';

	printf("my %d\n", ft_isdigit(a));
	printf("default %d\n", isdigit(a));
	return (0);

}
*/
