/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:57 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/29 17:27:51 by adjelili         ###   ########.fr       */
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
	ft_free_map(map);
	return (0);
}
