/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:57 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/30 14:14:08 by anis             ###   ########.fr       */
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
	ft_print_map(map);
	char **map_2 = copy_map(map);
	ft_print_map_2(map_2);
	flood_fill(1, 1, map_2); // il me faut une fonction qui trouve la position de spawn
	ft_print_map_2(map_2);
	ft_free_map(map);
	return (0);
}
