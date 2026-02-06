/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:08:46 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/06 16:13:37 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	master->sprites->enemy2 = get_addr_img(master, map, "images/enemy2.xpm");
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

void	ft_destroy_img(t_master *master)
{
	mlx_destroy_image(master->mlx, master->sprites->dos);
	mlx_destroy_image(master->mlx, master->sprites->face);
	mlx_destroy_image(master->mlx, master->sprites->droite);
	mlx_destroy_image(master->mlx, master->sprites->e_f);
	mlx_destroy_image(master->mlx, master->sprites->e_o);
	mlx_destroy_image(master->mlx, master->sprites->ennemi);
	mlx_destroy_image(master->mlx, master->sprites->gauche);
	mlx_destroy_image(master->mlx, master->sprites->gemme);
	mlx_destroy_image(master->mlx, master->sprites->sols);
	mlx_destroy_image(master->mlx, master->sprites->murs);
	mlx_destroy_image(master->mlx, master->sprites->marche_d);
	mlx_destroy_image(master->mlx, master->sprites->marche_d);
}
