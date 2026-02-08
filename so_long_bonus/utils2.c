/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:14:43 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/08 19:07:39 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_file_name(char *argv, t_map *map)
{
	size_t	y;

	y = ft_strlen_map(argv);
	if (y <= 4 || ft_strncmp((argv + y - 4), ".ber", 4))
	{
		printf("invalid format of map\n");
		free(map);
		exit(EXIT_FAILURE);
	}
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
