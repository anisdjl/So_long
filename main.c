/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:57 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/02 18:03:40 by adjelili         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_map	*map;
	t_master	*master;

	master = malloc(sizeof(t_master));
	if (!master)
		return (0);
	map = malloc(sizeof(t_map));
	if (!map)
	{
		//ft_free_master(master);
		return (0);
	}
	map->x = 0;
	map->y = 0;
	map->map = NULL;
	parse(map, argv[argc - 1]);
	master->mlx = mlx_init();
	master->window = mlx_new_window(master->mlx, map->y * 64, map->x * 64, "so_long");
	init_data(master, map);
	mlx_loop(master->mlx);
	ft_free_map(map);
	return (0);
}

void	check_file_name(char *argv, t_map *map)
{
	size_t	y;

	y = ft_strlen_map(argv);
	if (y < 4 || ft_strncmp((argv + y - 4), ".ber", 4))
	{
		printf("invalid format of map\n");
		ft_free_map(map);
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
