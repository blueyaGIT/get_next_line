/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:57:41 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/13 15:09:57 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t len;

	len = 0;
    while (s[len])
        len++;
    return (len);
}

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}


char *ft_strdup(const char *s1)
{
    size_t	len;
	size_t	temp;
    char	*copy;
	
	temp = -1;
	len = ft_strlen(s1);
    copy = (char *)malloc(len + 1);
	if (!copy)
        return NULL;
	while(++temp < len)
        copy[temp] = s1[temp];
    copy[len] = '\0';
    return copy;
}

char *ft_strjoin(char *s1, const char *s2)
{

    size_t	len1;
    size_t	len2;
	size_t	temp1;
	size_t	temp2;
	char	*joined;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	temp1 = -1;
	temp2 = -1;
    if (!s1 || !s2)
        return (NULL);
	joined = (char *)malloc(len1 + len2 + 1);
    if (!joined)
        return (NULL);
	while (++temp1 < len1)
        joined[temp1] = s1[temp1];
	while (++temp2 < len2)
        joined[len1 + temp2] = s2[temp2];
    joined[len1 + len2] = '\0';
    return (joined);
}
