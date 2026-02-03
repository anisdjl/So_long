/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:52:42 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/03 18:18:42 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyboard(int touche, t_hook *hook)
{
	if (touche == 65362 || touche == 65364 || touche == 65361 || touche == 65363) // ic je vais gerer tout les deplacements haut bas droite gauche
		ft_mouvements(touche, hook); // appelle la fonction pour les mouvements 
	if (touche == 65307)
	{
		mlx_destroy_window(hook->master->mlx, hook->master->window);
		mlx_destroy_display(hook->master->mlx);
		free(hook->master);
		ft_free_map(hook->map);
	}//la fonction qui exite et free tout et qui ferme la window
	printf("%d\n", hook->map->nb_c);
	return (0);
}

void	ft_mouvements(int touche, t_hook *hook)
{
	if ((hook->map->spawn_x != hook->map->exit_x || hook->map->spawn_y != hook->map->exit_y) && hook->map->map[hook->map->exit_x][hook->map->exit_y] != 'E')
	{
	 	hook->map->map[hook->map->exit_x][hook->map->exit_y] = 'E';
	 	draw_map(hook->master, hook->map);
	}
	if (touche == 65362 && hook->map->map[hook->map->spawn_x - 1][hook->map->spawn_y] != '1' && hook->map->map[hook->map->spawn_x - 1][hook->map->spawn_y] != 'D') // haut
	{
		hook->map->map[hook->map->spawn_x - 1][hook->map->spawn_y] = 'P';
		hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = '0';
		hook->map->spawn_x--;
		if (hook->map->map[hook->map->spawn_x - 1][hook->map->spawn_y] == 'C')
			hook->map->nb_c--;
		draw_map(hook->master, hook->map);	
	}
	else if (touche == 65364 && hook->map->map[hook->map->spawn_x + 1][hook->map->spawn_y] != '1' && hook->map->map[hook->map->spawn_x + 1][hook->map->spawn_y] != 'D') // bas
	{
		hook->map->map[hook->map->spawn_x + 1][hook->map->spawn_y] = 'P';
		hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = '0';
		hook->map->spawn_x++;
		if (hook->map->map[hook->map->spawn_x + 1][hook->map->spawn_y] == 'C')
			hook->map->nb_c--;
		draw_map(hook->master, hook->map);	
	}
	else if (touche == 65363 && hook->map->map[hook->map->spawn_x][hook->map->spawn_y + 1] != '1' && hook->map->map[hook->map->spawn_x][hook->map->spawn_y + 1] != 'D') // vers la droite
	{
		hook->map->map[hook->map->spawn_x][hook->map->spawn_y + 1] = 'P';
		hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = '0';
		hook->map->spawn_y++;
		if (hook->map->map[hook->map->spawn_x][hook->map->spawn_y + 1] == 'C')
			hook->map->nb_c--;
		draw_map(hook->master, hook->map);	
	}
	else if (touche == 65361 && hook->map->map[hook->map->spawn_x][hook->map->spawn_y - 1] != '1' && hook->map->map[hook->map->spawn_x][hook->map->spawn_y - 1] !=  'D') // vers la gauche
	{
		hook->map->map[hook->map->spawn_x][hook->map->spawn_y - 1] = 'P';
		hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = '0';
		hook->map->spawn_y--;
		if (hook->map->map[hook->map->spawn_x][hook->map->spawn_y - 1] == 'C')
			hook->map->nb_c--;
		draw_map(hook->master, hook->map);	
	}
	else
		return ;
}

void	init_data(t_master *master, t_map *map)
{
	t_hook	*hook;

	hook = malloc(sizeof(*hook));
	hook->master = master;
	hook->map = map;
	init_img(master, map);
	draw_map(master, map);
	// if (hook->map->spawn_x != hook->map->exit_x && hook->map->spawn_y != hook->map->exit_y)
	// {
	// 	hook->map->map[hook->map->exit_y][hook->map->exit_x] = 'E';
	// 	draw_map(hook->master, hook->map);
	// }
	mlx_key_hook(master->window, keyboard, hook);
	// if (map->nb_c == 0)
		// on change l'image de l'exit
	//free(hook); faut pas mettre de free ici
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
		free(master);
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
