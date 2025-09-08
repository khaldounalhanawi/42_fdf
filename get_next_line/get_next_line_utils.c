/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:18:41 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/26 18:46:14 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	if (ch == '\0')
	{
		while (*s != ch)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		len_total;
	char	*p;
	char	*original;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	len_total = len1 + len2 + 1;
	p = malloc(len_total * sizeof(char));
	if (!p)
		return (NULL);
	original = p;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (original);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	char	*record;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	p = malloc ((len + 1) * (size_t) sizeof (char));
	if (!p)
		return (NULL);
	record = p;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (record);
}

char	*searcher(char **rest, char **temp)
{
	int		new_len;
	char	*clean;
	char	*income;
	char	*record;

	income = *rest;
	new_len = ft_strchr(income, '\n') - income + 1;
	clean = malloc((new_len + 1) * sizeof(char));
	if (!clean)
		return (free_all(temp, rest));
	record = clean;
	while (*income != '\n')
		*clean++ = *income++;
	*clean++ = *income++;
	*clean = '\0';
	free_all(rest, NULL);
	*rest = *temp;
	return (record);
}
