/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:57 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/01 13:09:24 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(t_map *map)
{
	int a;

	a = 0;
	while(map->map[a])
	{
		printf("%s\n", map->map[a]);
		a++;
	}
}

void	ft_print_map_2(char **map)
{
	int a;

	a = 0;
	while(map[a])
	{
		printf("%s\n", map[a]);
		a++;
	}
	printf("\n");
}

int	main(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->x = 0;
	map->y = 0;
	ft_check_map(map);
	ft_parse_map(map);
	//printf("je suis ici\n");
	ft_remove_nl(map);
	//printf("je suis ici\n");
	ft_test_length_line(map);
	//printf("je suis ici\n");
	ft_test_walls(map);
	//printf("je suis ici\n");
	ft_test_elements(map);
	char **map_2 = copy_map(map);
	find_pos_of_spawn_exit(map);
	flood_fill(map->spawn_x, map->spawn_y, map_2);
	ft_check_valid_path(map, map_2);
	ft_free_tab(&map_2);
	ft_free_map(map);
	return (0);
}
