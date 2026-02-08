/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:23:21 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/08 19:07:34 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_tab(char ***tab)
{
	int	y;

	y = 0;
	while ((*tab)[y])
	{
		free ((*tab)[y]);
		y++;
	}
	free (*tab);
	tab = NULL;
}

size_t	ft_strlen_map(const char *s)
{
	int	y;

	y = 0;
	while (s[y])
		y++;
	return (y);
}

void	ft_free_map(t_map *map)
{
	if (map->map != NULL)
		ft_free_tab(&map->map);
	free(map);
}

void	nb_enemy(t_map *map)
{
	int	y;
	int	a;

	map->nb_enemy = 0;
	y = 0;
	while (map->map[y])
	{
		a = 0;
		while (map->map[y][a])
		{
			if (map->map[y][a] == 'D')
				map->nb_enemy++;
			a++;
		}
		y++;
	}
}
