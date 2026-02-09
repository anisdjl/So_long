/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:14:43 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/09 14:34:43 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_file_name(char *argv, t_map *map)
{
	size_t	y;

	if (ft_strrchr(argv, 47))
		check_file_name2(argv, map);
	else
	{
		y = ft_strlen_map(argv);
		if (y <= 4 || ft_strncmp((argv + y - 4), ".ber", 4))
		{
			ft_printf("Error\n invalid format of file\n");
			free(map);
			exit(EXIT_FAILURE);
		}
	}
	ft_printf("%s\n", argv);
}

void	check_file_name2(char *argv, t_map *map)
{
	size_t	y;
	char	*argv2;

	argv2 = ft_strtrim(ft_strrchr(argv, 47), "/");
	y = ft_strlen_map(argv2);
	if (y <= 4 || ft_strncmp((argv2 + y - 4), ".ber", 4))
	{
		ft_printf("Error\n invalid format of file\n");
		free(argv2);
		free(map);
		exit(EXIT_FAILURE);
	}
	free(argv2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	y;

	y = 0;
	while ((s1[y] || s2[y]) && y < n)
	{
		if (s1[y] != s2[y])
			return ((unsigned char)(s1[y]) - (unsigned char)(s2[y]));
		else
			y++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	y;

	y = 0;
	while (s[y])
	{
		y++;
	}
	while (y >= 0)
	{
		if (s[y] == (char)c)
		{
			return ((char *)(s + y));
		}
		else
			y--;
	}
	return (NULL);
}
