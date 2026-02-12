/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:57 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/12 09:47:31 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map;

	if (argc != 2)
		return (0);
	map = malloc(sizeof(t_map));
	if (!map)
	{
		return (0);
	}
	init(map, argv[argc - 1]);
	return (0);
}

void	init(t_map *map, char *argv)
{
	t_master	*master;

	map->x = 0;
	map->y = 0;
	map->map = NULL;
	map->side = 0;
	parse(map, argv);
	master = malloc(sizeof(t_master));
	if (!master)
	{
		free(map);
		exit(EXIT_FAILURE);
	}
	master->sprites = malloc(sizeof(t_sprites));
	if (!master->sprites)
	{
		free(map);
		free(master);
		return ;
	}
	init_master(master, map);
	init_data(master, map);
	mlx_loop(master->mlx);
}

void	init_master(t_master *master, t_map *map)
{
	master->steps = 0;
	master->frame = 1;
	master->walk = 0;
	master->mlx = mlx_init();
	master->window = mlx_new_window(master->mlx, map->y * 64,
			map->x * 64, "so_long");
}
