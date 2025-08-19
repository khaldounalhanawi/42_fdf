/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:32:48 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/24 12:33:50 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	str_len(char const *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*str;

	if (!s || !f)
		return (NULL);
	len = str_len(s);
	str = malloc ((len + 1) * sizeof (char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char add(unsigned int n, char c)
{
	return (c + n);
}

#include <stdio.h>
int main ()
{
	// printf("%d\n", str_len(" "));
	char str[] = "abcd";
	char (*kk)(unsigned int, char);

	kk = add;
	printf("%s\n", ft_strmapi(str, kk));


}*/
