/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:15:52 by mpons             #+#    #+#             */
/*   Updated: 2021/11/26 11:21:26 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_read_save(int fd, char *str)
{
	char	*buf;
	int		char_lu;
	int		i;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 0;
	while (!ft_strchr(str, '\n'))
	{
		char_lu = read(fd, buf, BUFFER_SIZE);
		if (char_lu == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[char_lu] = '\0';
		str = ft_strjoin(str, buf);
		if (char_lu == 0)
			break ;
	}
	free (buf);
	return (str);
}

char	*ft_get_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = ft_substr(s, 0, i);
	return (line);
}

char	*ft_reste(char *s)
{
	char	*new_s;
	int		i;

	i = 0;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	new_s = ft_substr(s, i, ft_strlen(s) - i + 1);
	free(s);
	return (new_s);
}

char	*get_next_line(int fd)
{
	char		*r_line;
	static char	*bkp[257];

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (0);
	bkp[fd] = ft_read_save(fd, bkp[fd]);
	if (!bkp[fd])
		return (NULL);
	r_line = ft_get_line(bkp[fd]);
	bkp[fd] = ft_reste(bkp[fd]);
	return (r_line);
}
