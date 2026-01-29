/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:39:32 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/29 14:47:03 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *stash)
{
	int		t;
	char	*line;

	t = 0;
	while (stash[t] != '\n')
		t++;
	line = malloc(sizeof(char) * (t + 2));
	if (!line)
		return (NULL);
	t = 0;
	while (stash[t] != '\n')
	{
		line[t] = stash[t];
		t++;
	}
	if (stash[t] == '\n')
		line[t++] = '\n';
	line[t] = '\0';
	return (line);
}

char	*ft_substr(char *stash, unsigned int start, size_t len)
{
	size_t	y;
	int		a;
	char	*str;

	y = 0;
	if (start >= ft_strlen(stash))
		return (ft_strdup(""));
	if (len <= (ft_strlen(stash) - start))
		str = malloc(sizeof(char) * (len + 1));
	else
		str = malloc(sizeof(char) * (ft_strlen(stash) - start + 1));
	if (!str)
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	a = start;
	while (y < len && stash[a])
		str[y++] = stash[a++];
	str[y] = '\0';
	return (str);
}

char	*ft_update_stash(char *stash)
{
	int		start;
	int		len;
	char	*new_stash;

	start = 0;
	while (stash[start] != '\n')
		start++;
	start++;
	len = ft_strlen(stash) - start;
	new_stash = ft_substr(stash, start, len);
	free (stash);
	return (new_stash);
}

char	*ft_strdup(char *s)
{
	char	*new_str;
	int		a;

	a = 0;
	while (s[a])
		a++;
	new_str = malloc(sizeof(char) * (a + 1));
	if (!new_str)
		return (0);
	a = 0;
	while (s[a])
	{
		new_str[a] = s[a];
		a++;
	}
	new_str[a] = '\0';
	return (new_str);
}

char	*read_and_fill(int fd, char *stash)
{
	char	*buffer;
	int		nbytes;

	nbytes = 1;
	while (nbytes != 0 && !ft_test_n(stash))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		free(buffer);
	}
	return (stash);
}
