/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 08:51:45 by mpons             #+#    #+#             */
/*   Updated: 2021/11/26 10:57:43 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
	{
	int		i;
	char	ch;
	char	*str;

	ch = (char)c;
	str = (char *)s;
	if (!s)
		return (0);
	i = 0;
	while (str[i] != ch)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (str + i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dst;
	size_t	len;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	free(s1);
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i])
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return ((void *)0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(const char *s, unsigned int start, size_t len_max)
{
	char	*dest;
	size_t	len_s;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	len_s = ft_strlen(s + start);
	if (len_s > len_max)
		len_s = len_max;
	dest = malloc ((len_s + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len_s)
	{
		dest[i] = s[start + i];
		i++;
	}	
	dest[i] = '\0';
	return (dest);
}
