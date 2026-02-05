/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:52:42 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/05 12:57:11 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyboard(int touche, t_hook *hook)
{
	if (touche == 65362)
		up(hook);
	else if (touche == 65364)
		down(hook);
	else if (touche == 65363)
	{	
		right(hook);
		hook->master->walk = !hook->master->walk;
	}
	else if (touche == 65361)
	{	
		left(hook);
		hook->master->walk = !hook->master->walk;
	}
	else if (touche == 65307)
		ft_exit(hook);
	if ((hook->map->nb_c == 0 && hook->map->spawn_x == hook->map->exit_x && hook->map->spawn_y == hook->map->exit_y))
		ft_exit(hook);
	draw_map(hook->master, hook->map);
	return (0);
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

int	ft_exit(t_hook *hook)
{
	ft_destroy_img(hook->master);
	mlx_destroy_window(hook->master->mlx, hook->master->window);
	mlx_destroy_display(hook->master->mlx);
	free(hook->master->sprites);
	free(hook->master);
	ft_free_map(hook->map);
	free(hook);
	exit(EXIT_SUCCESS);
}

void	up(t_hook *hook)
{
	if (hook->map->map[hook->map->spawn_x - 1][hook->map->spawn_y] != '1' &&
			hook->map->map[hook->map->spawn_x - 1][hook->map->spawn_y] != 'D')
	{
		hook->master->frame = 2;
		if (hook->map->map[hook->map->spawn_x - 1][hook->map->spawn_y] == 'C')
			hook->map->nb_c--;
		hook->map->map[hook->map->spawn_x - 1][hook->map->spawn_y] = 'P';
		if (hook->map->spawn_x != hook->map->exit_x || hook->map->spawn_y != hook->map->exit_y)
			hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = '0';
		else
			hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = 'E';
		hook->map->spawn_x--;
		hook->master->steps++;
	}
}

void	down(t_hook *hook)
{
	if (hook->map->map[hook->map->spawn_x + 1][hook->map->spawn_y] != '1' &&
			hook->map->map[hook->map->spawn_x + 1][hook->map->spawn_y] != 'D') // bas
	{
		hook->master->frame = 1;
		if (hook->map->map[hook->map->spawn_x + 1][hook->map->spawn_y] == 'C')
			hook->map->nb_c--;
		hook->map->map[hook->map->spawn_x + 1][hook->map->spawn_y] = 'P';
		if (hook->map->spawn_x != hook->map->exit_x || hook->map->spawn_y != hook->map->exit_y)
			hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = '0';
		else
			hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = 'E';
		hook->map->spawn_x++;
		hook->master->steps++;
	}
}

void	right(t_hook *hook)
{
	if (hook->map->map[hook->map->spawn_x][hook->map->spawn_y + 1] != '1'
		&& hook->map->map[hook->map->spawn_x][hook->map->spawn_y + 1] != 'D') // vers la droite
	{
		hook->master->frame = 3;
		if (hook->map->map[hook->map->spawn_x][hook->map->spawn_y + 1] == 'C')
			hook->map->nb_c--;
		hook->map->map[hook->map->spawn_x][hook->map->spawn_y + 1] = 'P';
		if (hook->map->spawn_x != hook->map->exit_x || hook->map->spawn_y != hook->map->exit_y)
			hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = '0';
		else
			hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = 'E';
		hook->map->spawn_y++;
		hook->master->steps++;	
	}
}

void	left(t_hook *hook)
{
	if (hook->map->map[hook->map->spawn_x][hook->map->spawn_y - 1] != '1'
		&& hook->map->map[hook->map->spawn_x][hook->map->spawn_y - 1] !=  'D') // vers la gauche
	{
		hook->master->frame = 4;
		if (hook->map->map[hook->map->spawn_x][hook->map->spawn_y - 1] == 'C')
			hook->map->nb_c--;
		hook->map->map[hook->map->spawn_x][hook->map->spawn_y - 1] = 'P';
		if (hook->map->spawn_x != hook->map->exit_x || hook->map->spawn_y != hook->map->exit_y)
			hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = '0';
		else
			hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = 'E';
		hook->map->spawn_y--;
		hook->master->steps++;	
	}
}

void	init_data(t_master *master, t_map *map)
{
	t_hook	*hook;

	hook = malloc(sizeof(*hook));
	hook->master = master;
	hook->map = map;
	hook->master->steps = 0;
	hook->master->frame = 1;
	hook->master->walk = 0;
	init_img(master, map);
	draw_map(master, map);
	mlx_hook(master->window, 2, 3, keyboard, hook); // cette fonction gere les hooks (les hooks c'est des crochets qui ont une fonction a appeler en cas de touche presse)
	mlx_hook(master->window, 17, 0, ft_exit, hook);
//	mlx_loop_hook(master->mlx, enemy, hook);
	// if (map->nb_c == 0)
		// on change l'image de l'exit
	//free(hook); faut pas mettre de free ici
}

void	init_img(t_master *master, t_map *map) // pour avoir l'addresse de chaque image 
{
	master->sprites->gemme = get_addr_img(master, map, "images/collectible.xpm");
	master->sprites->dos = get_addr_img(master, map, "images/de_dos.xpm");
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
	
	ptr = mlx_xpm_file_to_image(master->mlx, filename, &h, &l); // cette fonction renvoie l'addrese de l'image au format xpm qu'on lui a donne tout en modifiant sa hauteur et sa largeur par reference 
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
	int x;
	int	y;
	char *steps;
	x = 0;
	while (x < map->x)
	{
		y = 0;
		while (map->map[x][y])
		{
			steps = ft_itoa(master->steps);
			mlx_put_image_to_window(master->mlx, master->window, master->sprites->sols, y * 64, x * 64); // cette fonction met l'image dans la fenetre en commancant par le coin haut gauche 
			if (map->map[x][y] == '1')
				mlx_put_image_to_window(master->mlx, master->window, master->sprites->murs, y * 64, x * 64);
			else if (map->map[x][y] == 'E' && map->nb_c != 0)
				mlx_put_image_to_window(master->mlx, master->window, master->sprites->e_f, y * 64, x * 64);
			else if (map->map[x][y] == 'E' && map->nb_c == 0)
				mlx_put_image_to_window(master->mlx, master->window, master->sprites->e_o, y * 64, x * 64);
			else if (map->map[x][y] == 'C')
				mlx_put_image_to_window(master->mlx, master->window, master->sprites->gemme, y * 64, x * 64);
			else if (map->map[x][y] == 'P' && master->frame == 1)
				mlx_put_image_to_window(master->mlx, master->window, master->sprites->face, y * 64, x * 64);
			else if (map->map[x][y] == 'P' && master->frame == 2)
				mlx_put_image_to_window(master->mlx, master->window, master->sprites->dos, y * 64, x * 64);
			else if (map->map[x][y] == 'P' && master->frame == 3 && master->walk == 0)
				mlx_put_image_to_window(master->mlx, master->window, master->sprites->droite, y * 64, x * 64);
			else if (map->map[x][y] == 'P' && master->frame == 3 && master->walk == 1)
				mlx_put_image_to_window(master->mlx, master->window, master->sprites->marche_d, y * 64, x * 64);
			else if (map->map[x][y] == 'P' && master->frame == 4 && master->walk == 0)
				mlx_put_image_to_window(master->mlx, master->window, master->sprites->gauche, y * 64, x * 64);
			else if (map->map[x][y] == 'P' && master->frame == 4 && master->walk == 1)
				mlx_put_image_to_window(master->mlx, master->window, master->sprites->marche_g, y * 64, x * 64);
			else if (map->map[x][y] == 'D')
				mlx_put_image_to_window(master->mlx, master->window, master->sprites->ennemi, y * 64, x * 64);
			mlx_string_put(master->mlx, master->window, 1 * 32, 1 * 32, 0xFFFFFF, steps);
			free(steps);
			y++;
		}
		x++;
	}
}
