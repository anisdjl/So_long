/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_annim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:03:02 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/09 14:48:06 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	animation(t_hook *hook)
{
	static int	y;
	int			a;
	int			b;

	y++;
	if (y < 30000)
		return (0);
	y = 0;
	ft_move_ennemis(hook);
	hook->map->side = !hook->map->side;
	a = 0;
	while (hook->map->map[a])
	{
		b = 0;
		while (hook->map->map[a][b])
		{
			display_annim(hook, a, b);
			b++;
		}
		a++;
	}
	return (0);
}

void	display_annim(t_hook *hook, int a, int b)
{
	if (hook->map->map[a][b] == 'C' && hook->map->side == 0)
		mlx_put_image_to_window(hook->master->mlx, hook->master->window,
			hook->master->sprites->gemme, b * 64, a * 64);
	else if (hook->map->map[a][b] == 'C' && hook->map->side == 1)
		mlx_put_image_to_window(hook->master->mlx, hook->master->window,
			hook->master->sprites->gemme_2, b * 64, a * 64);
}
