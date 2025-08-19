/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:56:10 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/24 18:20:06 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	num;

	num = 0;
	while (src[num])
		num++;
	if (dstsize)
	{
		while (--dstsize && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (num);
}

static void	len_cal(unsigned int *s_len, unsigned int *s2_len,
	unsigned int start, char const *s)
{
	while (s[*s_len])
		*s_len = *s_len + 1;
	*s2_len = *s_len - start;
}

static char	*body(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	s_len;
	unsigned int	s2_len;

	s_len = 0;
	s2_len = 0;
	len_cal(&s_len, &s2_len, start, s);
	if (len < (size_t)(s2_len))
		s2_len = (int) len;
	if (start >= s_len)
	{
		p = malloc(1);
		if (!p)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	p = malloc((s2_len + 1) * sizeof(unsigned char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, &s[start], s2_len + 1);
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*empty;
	char	*p;

	if (!s)
		return (NULL);
	if (*s == '\0' || len == 0)
	{
		empty = malloc(1);
		if (!empty)
			return (NULL);
		empty[0] = '\0';
		return (empty);
	}
	p = body (s, start, len);
	return (p);
}
/*
#include <stdio.h>

int main()
{

	char s[] = "hola";
	int pos = 0;
	size_t len = 1;

	printf("%s\n", ft_substr(s,pos,len));
}
  */