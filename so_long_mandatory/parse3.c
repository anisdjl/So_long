/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:14:22 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/08 19:03:21 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	parse(t_map *map, char *filename)
{
	char	**map_2;

	check_file_name(filename, map);
	ft_check_map(map, filename);
	ft_parse_map(map, filename);
	ft_remove_nl(map);
	ft_test_length_line(map);
	ft_test_walls(map);
	ft_test_elements(map);
	map_2 = copy_map(map);
	find_pos_of_spawn_exit(map);
	flood_fill(map->spawn_x, map->spawn_y, map_2);
	ft_check_valid_path(map, map_2);
	ft_free_tab(&map_2);
}

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
	if (pos_p_x < 1 || pos_p_y < 1 || map[pos_p_x][pos_p_y]
		== '1' || map[pos_p_x][pos_p_y] == 'F' || map[pos_p_x][pos_p_y] == 'D')
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
	int	y;
	int	a;

	y = 0;
	while (map_filled[y])
	{
		a = 0;
		while (map_filled[y][a])
		{
			if (map_filled[y][a] == 'P' || map_filled[y][a] == 'E'
				|| map_filled[y][a] == 'C')
			{
				ft_free_map(map);
				ft_free_tab(&map_filled);
				printf("invalid map valid path\n");
				exit(EXIT_FAILURE);
			}
			a++;
		}
		y++;
	}
}
