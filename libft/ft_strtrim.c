/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:51:39 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/20 15:54:14 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		start;
	int		end;
	int		final_len;

	if (!s1 || !set)
		return (NULL);
	if (!*s1 || !*set)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	final_len = end - start + 2;
	new = malloc (final_len * sizeof (char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s1[start], final_len);
	return (new);
}
/*



#include <stdio.h>

int main()
{
	int i = 0;

	char *t[][2] = 
	{
        {"", ""},
        {"abc", ""},
        {"", "abc"},
        {"abc", "abc"},
        {"ab123", "ab"},
        {"123ab", "ab"},
        {"ab123ab", "ab"},
        {"ab123ab", "b"},
        {"ab123ab", "a"},
        {"ab123ab", "f"},
        {"123ab12", "ab"},
        {"abab123abab", "ab"},
        {"ab123ab", "ff"},
        {"ab123ab", "fa"},
        {"a12ba3ab", "abc"},
        {"ab123ab", "fabcdefghijk"},
        {"Hgelzloa gUgfzok!", "zgak"},
        {"", ""},
        {"aacacabaaacccb", "abc"},
        {"  \t \t \n   \n\n\n\t", " \n\t"},
        {"   \t  \n\n \t\t  \n\n\nHello \t  Please\n 
        Trim me !\n   \n \n \t\t\n  "," \n\t"}
    };

   	int ss = sizeof(t) / sizeof(t[0]);
   	// printf("%lu\n", sizeof(t[0]));
   	while (i < ss)
   	{
		printf("my >%s<\n", ft_strtrim(t[i][0], t[i][1]));
		printf("pd >%s<\n", ft_strtrim2(t[i][0], t[i][1]));
		printf("\n");
   		i++;
   	}


	// char s1[] = "Hgelzloa gUgfzok!";
	// char s2[] = "zgak";
	          // 012345678 9 
	// char s1[] = "";
	// char s2[] = "";

	
	// char s1[] = "aacacabaaacccb";
	// char s2[] = "abc";

	// char s1[] = "  \t \t \n   \n\n\n\t";
	// char s2[] = " \n\t";


// char s1[] = "";
// char s2[] = "";

// char s1[] = "abc";
// char s2[] = "";

// char s1[] = "";
// char s2[] = "abc";

// char s1[] = "abc";
// char s2[] = "abc";

// char s1[] = "abc";
// char s2[] = "afg";

// char s1[] = "ab123";
// char s2[] = "ab";

// char s1[] = "123ab";
// char s2[] = "ab";

// char s1[] = "ab123ab";
// char s2[] = "ab";

// char s1[] = "ab123ab";
// char s2[] = "b";

// char s1[] = "ab123ab";
// char s2[] = "a";

// char s1[] = "ab123ab";
// char s2[] = "f";

// char s1[] = "123ab12";
// char s2[] = "ab";

// char s1[] = "abab123abab";
// char s2[] = "ab";

// char s1[] = "ab123ab";
// char s2[] = "ff";

// char s1[] = "ab123ab";
// char s2[] = "fa";

// char s1[] = "a12ba3ab";
// char s2[] = "abc";

// char s1[] = "ab123ab";
// char s2[] = "fabcdefghijk";



	return (0);
}
*/