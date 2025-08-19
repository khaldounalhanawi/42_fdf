/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:34:49 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/24 12:38:16 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	cnvrt(char *str, int minus, long m, int devider)
{
	if (minus)
	{
		*str = '-';
		str++;
	}
	while (devider >= 10)
	{
		*str = (m / devider) + '0';
		m %= devider;
		devider /= 10;
		str++;
	}
	*str = (m % 10) + '0';
	str++;
	*str = '\0';
}

static void	devider_cal(int *devider, long m, int *size)
{
	int	*p_devider;
	int	*p_size;

	p_devider = devider;
	p_size = size;
	*p_devider = 1;
	while (*p_devider <= m / 10)
	{
		*p_devider *= 10;
		(*p_size)++;
	}
}

char	*ft_itoa(int n)
{
	int		devider;
	int		size;
	int		minus;
	char	*str;
	long	m;

	m = (long) n;
	minus = 0;
	size = 1;
	if (m < 0)
	{
		m *= -1;
		minus = 1;
		size++;
	}
	devider = 0;
	devider_cal (&devider, m, &size);
	str = malloc ((size + 1) * sizeof (char));
	if (!str)
		return (NULL);
	cnvrt(str, minus, m, devider);
	return (str);
}
/*
#include <limits.h>
#include <stdio.h>
int main ()
{
	//int a = INT_MIN;
	// int a = 0;
	// int a = 10;
	// int a = INT_MAX;
	// int a = -5;
	// int a = -10;
	int a = -104;

	printf("%s\n", ft_itoa(a));
}*/
