/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:34:04 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/20 15:26:09 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	val;
	int	sign;

	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	val = 0;
	while (*str >= '0' && *str <= '9')
	{
		val = (val * 10) + (*str - '0');
		str++;
	}
	return (val * sign);
}
/*
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i = 0;
	// char a[] = "43b3";
	char *a[] = {"-+433","","-a34","b","-45b",
		"+43b9","-43b9","é4","  0990","\t005",
		"020b","2147483647","-2147483648"};

	while (i < 13)
	{
		printf("my:        %d\t\t", ft_atoi(a[i]));
		printf("default:   %d\n", atoi(a[i]));
		i++;
	}
}
*/
