/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:24:29 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/29 18:01:43 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_test_length_line(t_map *map)
{
	size_t	length;
	int y;
	
	length = ft_strlen(map->map[0]);
	y = 0;
	while (map->map[y])
	{
		if (ft_strlen(map->map[y]) != length)
		{
			ft_free_map(map);
			printf("invalid map");
			exit(EXIT_FAILURE);
		}
		y++;
	}
	map->y = length;
	if (map->x == map->y)
	{
		ft_free_map(map);
		printf("invalid map\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_check_map(t_map *map)
{
	int fd;
	char	*tmp;
	
	fd = open("map.ber", O_RDONLY);
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

void	ft_parse_map(t_map *map)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("map.ber", O_RDONLY);
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
	int y;
	int a;

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
		printf("invalid map");
		exit(EXIT_FAILURE);
	}
	if (!side_walls(map))
	{
		ft_free_map(map);
		printf("invalid map");
		exit(EXIT_FAILURE);
	}
}

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
	int y;

	y = 0;
	while(map->map[y])
	{
		if (map->map[y][0] != '1' || map->map[y][map->y - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

void	ft_count_elements(t_map *map, int *nb_c, int *nb_e, int *nb_p)
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
				(*nb_c)++;
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
	int nb_c;
	int nb_e;
	int	nb_p;

	nb_c = 0;
	nb_e = 0;
	nb_p = 0;
	ft_count_elements(map, &nb_c, &nb_e, &nb_p);
	if (nb_p != 1 || nb_e != 1 || !ft_test_forbidden_elements(map))
	{
		ft_free_map(map);
		printf("invalid map");
		exit(EXIT_FAILURE);
	}
	if (!ft_test_forbidden_elements(map))
	{
		ft_free_map(map);
		printf("invalid map");
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
					map->map[y][a] != 'C')
				return (0);
			a++;
		}
		y++;
	}
	return (1);
}
