/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:52:42 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/09 17:12:04 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	init_data(t_master *master, t_map *map)
{
	t_hook	*hook;
	int		i;

	i = 0;
	hook = malloc(sizeof(*hook));
	hook->master = master;
	hook->map = map;
	nb_enemy(map);
	master->enemy = init_ennemis(hook);
	init_img(master, map);
	draw_map(master, map);
	mlx_loop_hook(master->mlx, animation, hook);
	mlx_hook(master->window, 2, 3, keyboard, hook);
	mlx_hook(master->window, 17, 0, ft_exit, hook);
	mlx_hook(master->window, 12, 1L << 15, opti_draw, hook);
}

void	ft_move_ennemis(t_hook *hook)
{
	int	y;

	y = 0;
	while (y < hook->map->nb_enemy)
	{
		if (hook->map->map[hook->master->enemy[y]->pos_e_x]
			[hook->master->enemy[y]->pos_e_y
				+ hook->master->enemy[y]->dir] == '0')
		{
			hook->map->map[hook->master->enemy[y]->pos_e_x]
			[hook->master->enemy[y]->pos_e_y] = '0';
			hook->map->map[hook->master->enemy[y]->pos_e_x][hook->master->enemy
			[y]->pos_e_y + hook->master->enemy[y]->dir] = 'D';
			hook->master->enemy[y]->pos_e_y = hook->master->enemy[y]->pos_e_y
				+ hook->master->enemy[y]->dir;
			draw_map(hook->master, hook->map);
		}
		else if (hook->map->map[hook->master->enemy[y]->pos_e_x][hook->master
			->enemy[y]->pos_e_y + hook->master->enemy[y]->dir] == 'P')
			ft_exit(hook);
		else
			hook->master->enemy[y]->dir = -hook->master->enemy[y]->dir;
		y++;
	}
}

t_enemy	**init_ennemis(t_hook *hook)
{
	int		y;
	int		a;
	t_enemy	**ennemis;

	hook->count = 0;
	y = 0;
	ennemis = malloc(sizeof(t_enemy *) * (hook->map->nb_enemy));
	if (!ennemis)
		ft_exit(hook);
	while (hook->map->map[y])
	{
		a = 0;
		while (hook->map->map[y][a])
		{
			if (hook->map->map[y][a] == 'D')
			{
				ennemis[hook->count] = create_struct_ennemis
					(hook, y, a, ennemis);
				hook->count++;
			}
			a++;
		}
		y++;
	}
	return (ennemis);
}

t_enemy	*create_struct_ennemis(t_hook *hook, int y, int a, t_enemy **ennemis)
{
	t_enemy	*ennemi;

	ennemi = malloc(sizeof(t_enemy));
	if (!ennemi)
		ft_free_error_malloc_ennemis(hook, ennemis);
	ennemi->pos_e_x = y;
	ennemi->pos_e_y = a;
	ennemi->dir = 1;
	return (ennemi);
}
