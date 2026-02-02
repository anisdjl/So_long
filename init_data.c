/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:52:42 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/02 17:47:06 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_master *master, t_map *map)
{
	init_img(master, map);
	draw_map(master, map);
}

void	init_img(t_master *master, t_map *map)
{
	master->sprites.gemme = get_addr_img(master, map, "images/collectible.xpm");
	master->sprites.dos = get_addr_img(master, map, "images/de_dos.xpm");
	master->sprites.ennemi = get_addr_img(master, map, "images/enemy.xpm");
	master->sprites.e_f = get_addr_img(master, map, "images/exit_closed.xpm");
	master->sprites.e_o = get_addr_img(master, map, "images/exit_opened.xpm");
	master->sprites.face = get_addr_img(master, map, "images/face.xpm");
	master->sprites.droite = get_addr_img(master, map, "images/pdroit.xpm");
	master->sprites.gauche = get_addr_img(master, map, "images/pgauche.xpm");
	master->sprites.sols = get_addr_img(master, map, "images/sol.xpm");
	master->sprites.marche_g = get_addr_img(master, map, "images/w_t_l.xpm");
	master->sprites.marche_d = get_addr_img(master, map, "images/w_t_r.xpm");
	master->sprites.murs = get_addr_img(master, map, "images/wall.xpm");
}

t_img	get_addr_img(t_master *master, t_map *map, char *filename)
{
	t_img	img;

	img.ptr_img = mlx_xpm_file_to_image(master->mlx, filename, &img.longeur, &img.largeur);
	if (!img.ptr_img)
	{
		//ft_free_master(master);
		ft_free_map(map);
		exit(EXIT_FAILURE);
	}
	return (img);
}

void	draw_map(t_master *master, t_map *map)
{
	int x;
	int	y;
	
	x = 0;
	while (x < map->x)
	{
		y = 0;
		while (map->map[x][y])
		{
			mlx_put_image_to_window(master->mlx, master->window, master->sprites.sols.ptr_img, y * 64, x * 64);
			if (map->map[x][y] == '1')
				mlx_put_image_to_window(master->mlx, master->window, master->sprites.murs.ptr_img, y * 64, x * 64);
			else if (map->map[x][y] == 'E')
				mlx_put_image_to_window(master->mlx, master->window, master->sprites.e_f.ptr_img, y * 64, x * 64);
			else if (map->map[x][y] == 'C')
				mlx_put_image_to_window(master->mlx, master->window, master->sprites.gemme.ptr_img, y * 64, x * 64);
			else if (map->map[x][y] == 'P')
				mlx_put_image_to_window(master->mlx, master->window, master->sprites.face.ptr_img, y * 64, x * 64);
			else if (map->map[x][y] == 'D')
				mlx_put_image_to_window(master->mlx, master->window, master->sprites.ennemi.ptr_img, y * 64, x * 64);
			y++;
		}
		x++;
	}
}

// int	keyboard(int touche, t_master *master)
// {
// 	if ()
// }


// if (touche == keycode)
// {
// 	if (pos != '1')
// 	{
// 		map->map[y][x] = 'p'
// 	}
// }