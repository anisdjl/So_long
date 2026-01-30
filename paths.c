/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:14:22 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/30 14:33:09 by anis             ###   ########.fr       */
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
	ft_print_map_2(map);
	flood_fill(pos_p_x + 1, pos_p_y, map);
	flood_fill(pos_p_x - 1, pos_p_y, map);
	flood_fill(pos_p_x, pos_p_y + 1, map);
	flood_fill(pos_p_x, pos_p_y - 1, map);
}

void	find_pos_of_spawn_exit(t_map *map, t_player *player)
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
				player->spawn_x = a;
				player->spawn_y = y;
			}
			else if (map->map[y][a] == 'E')
			{
				player->exit_x = a;
				player->exit_y = y;
			}
			a++;
		}
		y++;
	}	
}
