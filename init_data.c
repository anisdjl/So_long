/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:52:42 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/06 16:16:56 by adjelili         ###   ########.fr       */
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
	if ((hook->map->nb_c == 0 && hook->map->spawn_x == hook->map->exit_x
			&& hook->map->spawn_y == hook->map->exit_y))
		ft_exit(hook);
	draw_map(hook->master, hook->map);
	return (0);
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

void	init_data(t_master *master, t_map *map)
{
	t_hook	*hook;
	int i;

	i = 0;
	hook = malloc(sizeof(*hook));
	hook->master = master;
	hook->map = map;
	hook->master->steps = 0;
	hook->master->frame = 1;
	hook->master->walk = 0;
	hook->map->side = 0;
	nb_enemy(map);
	master->enemy = init_ennemis(hook);
	init_img(master, map);
	draw_map(master, map);
	mlx_loop_hook(master->mlx, animation, hook);
	mlx_hook(master->window, 2, 3, keyboard, hook);
	mlx_hook(master->window, 17, 0, ft_exit, hook);
}

int	enemy(t_hook *hook)
{
	ft_move_ennemis(hook);
	return (0);
}

void	ft_move_ennemis(t_hook *hook)
{
	int y;

	y = 0;
	while (y < hook->map->nb_enemy)
	{
		if (hook->map->map[hook->master->enemy[y]->pos_e_x]
				[hook->master->enemy[y]->pos_e_y + hook->master->enemy[y]->dir] == '0')
		{
			hook->map->map[hook->master->enemy[y]->pos_e_x][hook->master->enemy[y]->pos_e_y] = '0';
			hook->map->map[hook->master->enemy[y]->pos_e_x][hook->master->enemy[y]->pos_e_y + hook->master->enemy[y]->dir] = 'D';
			hook->master->enemy[y]->pos_e_y = hook->master->enemy[y]->pos_e_y + hook->master->enemy[y]->dir;
			draw_map(hook->master, hook->map);
		}
		else if (hook->map->map[hook->master->enemy[y]->pos_e_x][hook->master->enemy[y]->pos_e_y + hook->master->enemy[y]->dir] == 'P')
			ft_exit(hook);
		else
			hook->master->enemy[y]->dir = -hook->master->enemy[y]->dir;
		y++;
	}
}

t_enemy	**init_ennemis(t_hook *hook)
{
	int y;
	int a;
	int i;
	t_enemy	**ennemis;

	i = 0;
	y = 0;
	ennemis = malloc(sizeof(t_enemy*) * (hook->map->nb_enemy));
	if (!ennemis)
		ft_exit(hook); 
	while (hook->map->map[y])
	{
		a = 0;
		while (hook->map->map[y][a])
		{
			if (hook->map->map[y][a] == 'D')
			{
				ennemis[i] = malloc(sizeof(t_enemy));
				ennemis[i]->pos_e_x = y;
				ennemis[i]->pos_e_y = a;
				ennemis[i]->dir = 1;
				i++;
			}
			a++;
		}
		y++;
	}
	return (ennemis);
}

int		animation(t_hook *hook)
{
	static int y;
	int a;
	int b;

	y++;
	if (y < 30000)
		return (0);
	y = 0;
	enemy(hook);
	hook->map->side = !hook->map->side;
	a = 0;
	while (hook->map->map[a])
	{
		b = 0;
		while (hook->map->map[a][b])
		{
			if (hook->map->map[a][b] == 'C' && hook->map->side == 0)
				mlx_put_image_to_window(hook->master->mlx, hook->master->window, hook->master->sprites->gemme, b * 64, a * 64);
			else if (hook->map->map[a][b] == 'C' && hook->map->side == 1)
				mlx_put_image_to_window(hook->master->mlx, hook->master->window, hook->master->sprites->gemme_2, b * 64, a * 64);
			b++;
		}
		a++;
	}
	return (0);
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
			mlx_put_image_to_window(master->mlx, master->window, master->sprites->sols, y * 64, x * 64); 
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


void	nb_enemy(t_map *map)
{
	int y;
	int a;

	map->nb_enemy = 0;
	y = 0;
	while (map->map[y])
	{
		a = 0;
		while (map->map[y][a])
		{
			if (map->map[y][a] == 'D')
				map->nb_enemy++;
			a++;
		}
		y++;
	}
}
