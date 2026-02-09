/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:06:09 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/09 12:26:26 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	top_down_walls(t_map *map)
{
	int	a;

	a = 0;
	while (map->map[0][a])
	{
		if (map->map[0][a] != '1')
			return (0);
		a++;
	}
	a = 0;
	while (map->map[map->x - 1][a])
	{
		if (map->map[map->x - 1][a] != '1')
			return (0);
		a++;
	}
	return (1);
}

int	side_walls(t_map *map)
{
	int	y;

	y = 0;
	while (map->map[y])
	{
		if (map->map[y][0] != '1' || map->map[y][map->y - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

void	ft_count_elements(t_map *map, int *nb_e, int *nb_p)
{
	int	i;
	int	a;

	i = 0;
	while (map->map[i])
	{
		a = 0;
		while (map->map[i][a])
		{
			if (map->map[i][a] == 'C')
				map->nb_c++;
			else if (map->map[i][a] == 'P')
				(*nb_p)++;
			else if (map->map[i][a] == 'E')
				(*nb_e)++;
			a++;
		}
		i++;
	}
}

void	ft_test_elements(t_map *map)
{
	int	nb_e;
	int	nb_p;

	nb_e = 0;
	nb_p = 0;
	map->nb_c = 0;
	ft_count_elements(map, &nb_e, &nb_p);
	if (nb_p != 1 || nb_e != 1 || !ft_test_forbidden_elements(map)
		|| map->nb_c < 1)
	{
		ft_free_map(map);
		ft_printf("Error\n wrong elements or wrong number of elements\n");
		exit(EXIT_FAILURE);
	}
}

int	ft_test_forbidden_elements(t_map *map)
{
	int	y;
	int	a;

	y = 0;
	while (map->map[y])
	{
		a = 0;
		while (map->map[y][a])
		{
			if (map->map[y][a] != '1' && map->map[y][a] != '0'
				&& map->map[y][a] != 'E' && map->map[y][a] != 'P' &&
					map->map[y][a] != 'C' && map->map[y][a] != 'D')
				return (0);
			a++;
		}
		y++;
	}
	return (1);
}
