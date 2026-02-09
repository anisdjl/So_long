/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:07:54 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/08 19:03:26 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up(t_hook *hook)
{
	if (hook->map->map[hook->map->spawn_x - 1][hook->map->spawn_y] != '1' &&
		hook->map->map[hook->map->spawn_x - 1][hook->map->spawn_y] != 'D')
	{
		hook->master->frame = 2;
		if (hook->map->map[hook->map->spawn_x - 1][hook->map->spawn_y] == 'C')
			hook->map->nb_c--;
		hook->map->map[hook->map->spawn_x - 1][hook->map->spawn_y] = 'P';
		if (hook->map->spawn_x != hook->map->exit_x || hook->map->spawn_y
			!= hook->map->exit_y)
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
		hook->map->map[hook->map->spawn_x + 1][hook->map->spawn_y] != 'D')
	{
		hook->master->frame = 1;
		if (hook->map->map[hook->map->spawn_x + 1][hook->map->spawn_y] == 'C')
			hook->map->nb_c--;
		hook->map->map[hook->map->spawn_x + 1][hook->map->spawn_y] = 'P';
		if (hook->map->spawn_x != hook->map->exit_x || hook->map->spawn_y
			!= hook->map->exit_y)
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
		&& hook->map->map[hook->map->spawn_x][hook->map->spawn_y + 1] != 'D')
	{
		hook->master->frame = 3;
		if (hook->map->map[hook->map->spawn_x][hook->map->spawn_y + 1] == 'C')
			hook->map->nb_c--;
		hook->map->map[hook->map->spawn_x][hook->map->spawn_y + 1] = 'P';
		if (hook->map->spawn_x != hook->map->exit_x || hook->map->spawn_y
			!= hook->map->exit_y)
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
		&& hook->map->map[hook->map->spawn_x][hook->map->spawn_y - 1] != 'D')
	{
		hook->master->frame = 4;
		if (hook->map->map[hook->map->spawn_x][hook->map->spawn_y - 1] == 'C')
			hook->map->nb_c--;
		hook->map->map[hook->map->spawn_x][hook->map->spawn_y - 1] = 'P';
		if (hook->map->spawn_x != hook->map->exit_x || hook->map->spawn_y
			!= hook->map->exit_y)
			hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = '0';
		else
			hook->map->map[hook->map->spawn_x][hook->map->spawn_y] = 'E';
		hook->map->spawn_y--;
		hook->master->steps++;
	}
}
