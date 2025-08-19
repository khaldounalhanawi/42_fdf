/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:40:56 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/24 12:41:23 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	str_len(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	len;
	unsigned int	counter;

	if (!s || !f)
		return ;
	len = (unsigned int) str_len (s);
	if (len == 0)
		return ;
	counter = 0;
	while (counter < len)
	{
		f(counter, &s[counter]);
		counter++;
	}
}
/*
void add(unsigned int n, char *c)
{
	*c = 'f';
}
#include <stdio.h>

int main()
{
	// printf("%d\n", str_len(" "));
	char str[] = "hey wo";
	void (*kk)(unsigned int, char*);

	kk = add;

	ft_striteri(str,kk);
	printf("%s\n", str);

	return (0);
}*/
