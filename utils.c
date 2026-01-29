/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:23:21 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/29 15:07:40 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_tab(char ***tab)
{
	int	y;

	y = 0;
	while ((*tab)[y])
	{
		free ((*tab)[y]);
		y++;
	}
	free (*tab);
	tab = NULL;
}

size_t	ft_strlen_map(const char *s)
{
	int	y;

	y = 0;
	while (s[y])
		y++;
	return (y);
}

void	ft_free_map(t_map *map)
{
	if (map->map != NULL)
		ft_free_tab(&map->map);
	free(map);
}