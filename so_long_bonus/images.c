/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:08:46 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/09 11:51:35 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_img(t_master *master, t_map *map)
{
	master->sprites->gemme = get_addr_img(master, map,
			"images/collectible.xpm");
	master->sprites->dos = get_addr_img(master, map, "images/de_dos.xpm");
	master->sprites->gemme_2 = get_addr_img(master, map,
			"images/collectible_2.xpm");
	master->sprites->ennemi = get_addr_img(master, map, "images/enemy.xpm");
	master->sprites->e_f = get_addr_img(master, map, "images/exit_closed.xpm");
	master->sprites->e_o = get_addr_img(master, map, "images/exit_opened.xpm");
	master->sprites->face = get_addr_img(master, map, "images/face.xpm");
	master->sprites->droite = get_addr_img(master, map, "images/pdroit.xpm");
	master->sprites->gauche = get_addr_img(master, map, "images/pgauche.xpm");
	master->sprites->sols = get_addr_img(master, map, "images/sol.xpm");
	master->sprites->marche_g = get_addr_img(master, map, "images/w_t_l.xpm");
	master->sprites->marche_d = get_addr_img(master, map, "images/w_t_r.xpm");
	master->sprites->murs = get_addr_img(master, map, "images/wall.xpm");
}

void	*get_addr_img(t_master *master, t_map *map, char *filename)
{
	int		h;
	int		l;
	void	*ptr;

	ptr = mlx_xpm_file_to_image(master->mlx, filename, &h, &l);
	if (!ptr)
	{
		free(master);
		ft_free_map(map);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	draw_map(t_master *master, t_map *map)
{
	int		x;
	int		y;
	char	*steps;

	x = 0;
	while (x < map->x)
	{
		y = 0;
		while (map->map[x][y])
		{
			steps = ft_itoa(master->steps);
			mlx_put_image_to_window(master->mlx, master->window,
				master->sprites->sols, y * 64, x * 64);
			if (map->map[x][y] == '1')
				mlx_put_image_to_window(master->mlx, master->window,
					master->sprites->murs, y * 64, x * 64);
			else
				draw_map2(master, map, x, y);
			mlx_string_put(master->mlx, master->window, 1 * 32,
				1 * 32, 0xFFFFFF, steps);
			free(steps);
			y++;
		}
		x++;
	}
}

void	draw_map2(t_master *master, t_map *map, int x, int y)
{
	if (map->map[x][y] == 'E' && map->nb_c != 0)
		mlx_put_image_to_window(master->mlx, master->window,
			master->sprites->e_f, y * 64, x * 64);
	else if (map->map[x][y] == 'E' && map->nb_c == 0)
		mlx_put_image_to_window(master->mlx, master->window,
			master->sprites->e_o, y * 64, x * 64);
	else if (map->map[x][y] == 'C')
		mlx_put_image_to_window(master->mlx, master->window,
			master->sprites->gemme, y * 64, x * 64);
	else if (map->map[x][y] == 'P' && master->frame == 1)
		mlx_put_image_to_window(master->mlx, master->window,
			master->sprites->face, y * 64, x * 64);
	else if (map->map[x][y] == 'P' && master->frame == 2)
		mlx_put_image_to_window(master->mlx, master->window,
			master->sprites->dos, y * 64, x * 64);
	else
		draw_map3(master, map, x, y);
}

void	draw_map3(t_master *master, t_map *map, int x, int y)
{
	if (map->map[x][y] == 'P' && master->frame == 3 && master->walk == 0)
		mlx_put_image_to_window(master->mlx, master->window,
			master->sprites->droite, y * 64, x * 64);
	else if (map->map[x][y] == 'P' && master->frame == 3 && master->walk == 1)
		mlx_put_image_to_window(master->mlx, master->window,
			master->sprites->marche_d, y * 64, x * 64);
	else if (map->map[x][y] == 'P' && master->frame == 4 && master->walk == 0)
		mlx_put_image_to_window(master->mlx, master->window,
			master->sprites->gauche, y * 64, x * 64);
	else if (map->map[x][y] == 'P' && master->frame == 4 && master->walk == 1)
		mlx_put_image_to_window(master->mlx, master->window,
			master->sprites->marche_g, y * 64, x * 64);
	else if (map->map[x][y] == 'D')
		mlx_put_image_to_window(master->mlx, master->window,
			master->sprites->ennemi, y * 64, x * 64);
}
