/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:50:44 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/06 21:25:51 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_destroy_image(master->mlx, master->sprites->marche_g);
	mlx_destroy_image(master->mlx, master->sprites->gemme_2);
}

int	ft_exit(t_hook *hook)
{
	ft_destroy_img(hook->master);
	mlx_destroy_window(hook->master->mlx, hook->master->window);
	mlx_destroy_display(hook->master->mlx);
	free(hook->master->mlx);
	ft_free_ennemis(hook);
	free(hook->master->sprites);
	free(hook->master);
	ft_free_map(hook->map);
	free(hook);
	exit(EXIT_SUCCESS);
}

void	ft_free_ennemis(t_hook *hook)
{
	int y;
	
	y = 0;
	while (y < hook->count)
	{
		free(hook->master->enemy[y]);
		y++;
	}
	free(hook->master->enemy);
}

void	ft_free_error_malloc_ennemis(t_hook *hook, t_enemy **ennemis)
{
	int	y;

	y = 0;
	while (y < hook->count)
	{
		free(ennemis[y]);
		y++;
	}
	free(ennemis);
	free(hook->master->sprites);
	free(hook->master);
	ft_free_map(hook->map);
	free(hook);
}
