/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:14:22 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/31 17:49:52 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_map *map)
{
	char	**coppied_map;
	int		y;

	y = 0;
	coppied_map = malloc(sizeof(char *) * (map->x + 1));
	while (y < map->x)
	{
		coppied_map[y] = ft_strdup(map->map[y]);
		y++;
	}
	coppied_map[y] = NULL;
	return (coppied_map);
}

void	flood_fill(int pos_p_x, int pos_p_y, char **map)
{
	if (pos_p_x < 1 || pos_p_y < 1 || map[pos_p_x][pos_p_y] == '1' || map[pos_p_x][pos_p_y] == 'F')
		return ;
	map[pos_p_x][pos_p_y] = 'F';
	flood_fill(pos_p_x + 1, pos_p_y, map);
	flood_fill(pos_p_x - 1, pos_p_y, map);
	flood_fill(pos_p_x, pos_p_y + 1, map);
	flood_fill(pos_p_x, pos_p_y - 1, map);
}

void	find_pos_of_spawn_exit(t_map *map)
{
	int	y;
	int	a;

	y = 0;
	while (map->map[y])
	{
		a = 0;
		while (map->map[y][a])
		{
			if (map->map[y][a] == 'P')
			{
				map->spawn_x = y;
				map->spawn_y = a;
			}
			else if (map->map[y][a] == 'E')
			{
				map->exit_x = y;
				map->exit_y = a;
			}
			a++;
		}
		y++;
	}	
}

void	ft_check_valid_path(t_map *map, char **map_filled)
{
	int y;
	int a;

	y = 0;
	while (map_filled[y])
	{
		a = 0;
		while (map_filled[y][a])
		{
			if (map_filled[y][a] == 'P' || map_filled[y][a] == 'E' || map_filled[y][a] == 'C')
			{
				ft_free_map(map);
				ft_free_tab(&map_filled);
				printf("invalid map\n");
				exit(EXIT_FAILURE);
			}
			a++;
		}
		y++;
	}
}
