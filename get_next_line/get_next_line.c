/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:39:27 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/29 14:53:19 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = read_and_fill(fd, stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (ft_test_n(stash))
	{
		line = ft_line(stash);
		stash = ft_update_stash(stash);
		return (line);
	}
	line = ft_strdup(stash);
	free(stash);
	stash = NULL;
	return (line);
}

char	*ft_strjoin(char const *stash, char const *buffer)
{
	int		a;
	int		y;
	char	*new_str;

	if (!stash)
	{
		stash = ft_calloc(1, 1);
		if (!stash)
			return (NULL);
	}
	a = -1;
	y = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer) + 1));
	if (!new_str)
	{
		free ((char *)stash);
		return (NULL);
	}
	while (stash[++a])
		new_str[a] = stash[a];
	while (buffer[y])
		new_str[a++] = buffer[y++];
	new_str[a] = '\0';
	free ((char *)stash);
	return (new_str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	y;
	char	*ptr;

	if (nmemb != 0 && size >= (SIZE_MAX - 1) / nmemb)
		return (NULL);
	y = 0;
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	while (y < nmemb * size)
		ptr[y++] = 0;
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	y;

	if (!s)
		return (0);
	y = 0;
	while (s[y])
		y++;
	return (y);
}

int	ft_test_n(char *stash)
{
	int	x;

	if (!stash)
		return (0);
	x = 0;
	while (stash[x])
	{
		if (stash[x] == '\n')
			return (1);
		x++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("map.ber", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// free (line);
// 	return (0);
// }