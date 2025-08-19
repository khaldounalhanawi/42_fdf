/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:38:55 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/24 12:40:29 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

static int	devider_cal(long m)
{
	int	devider;

	devider = 1;
	while (devider <= m / 10)
	{
		devider *= 10;
	}
	return (devider);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	out;
	int		devider;
	long	m;

	m = (long) n;
	if (m < 0)
	{
		ft_putchar_fd('-', fd);
		m = m * (-1);
	}
	devider = devider_cal (m);
	while (devider > 0)
	{
		out = (m / devider) + '0';
		ft_putchar_fd(out, fd);
		m %= devider;
		devider /= 10;
	}
}
/*
# include <limits.h>
int main()
{

	// int a = INT_MIN;
	int a = 1005;
	// int a = 0;
	// int a = 10;
	// int a = INT_MAX;
	// int a = -5;
	// int a = -100;

	ft_putnbr_fd(a, 1);


}
*/