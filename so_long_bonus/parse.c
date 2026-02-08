/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:24:29 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/08 19:07:19 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_test_length_line(t_map *map)
{
	size_t	length;
	int		y;

	length = ft_strlen(map->map[0]);
	y = 0;
	while (map->map[y])
	{
		if (ft_strlen(map->map[y]) != length)
		{
			ft_free_map(map);
			printf("invalid map\n");
			exit(EXIT_FAILURE);
		}
		y++;
	}
	map->y = length;
	if (map->x == map->y)
	{
		ft_free_map(map);
		printf("invalid map test length\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_check_map(t_map *map, char *filename)
{
	int		fd;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		exit(EXIT_FAILURE);
	}
	tmp = get_next_line(fd);
	if (tmp == NULL)
	{
		free(map);
		printf("empty map\n");
		exit(EXIT_FAILURE);
	}
	free (tmp);
	while (tmp)
	{
		tmp = get_next_line(fd);
		map->x++;
		free(tmp);
	}
	close(fd);
}

void	ft_parse_map(t_map *map, char *filename)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		exit(EXIT_FAILURE);
	}
	map->map = malloc(sizeof(char *) * (map->x + 1));
	if (!map->map)
	{
		free(map);
		exit(EXIT_FAILURE);
	}
	while (i < map->x)
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	get_next_line(fd);
	map->map[i] = NULL;
	close(fd);
}

void	ft_remove_nl(t_map *map)
{
	int	y;
	int	a;

	y = 0;
	while (map->map[y])
	{
		a = 0;
		while (map->map[y][a])
		{
			if (map->map[y][a] == '\n')
				map->map[y][a] = '\0';
			a++;
		}
		y++;
	}
}

void	ft_test_walls(t_map *map)
{
	if (!top_down_walls(map))
	{
		ft_free_map(map);
		printf("invalid map down walls\n");
		exit(EXIT_FAILURE);
	}
	if (!side_walls(map))
	{
		ft_free_map(map);
		printf("invalid map side walls\n");
		exit(EXIT_FAILURE);
	}
}
