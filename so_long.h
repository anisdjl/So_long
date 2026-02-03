/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:03:37 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/03 14:47:16 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx_linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>

typedef	struct images
{
	void	*ptr_img; // le pointeur vers l'image
	int		longeur;
	int		largeur;
}	t_img;

typedef struct sprites_for_the_game
{
	t_img	murs;
	t_img	sols;
	t_img	e_f; // sortie fermee
	t_img	e_o; // sortie ouverte
	t_img	gemme;
	t_img	face; // face
	t_img	dos; // dos
	t_img	droite; // de cote droit
	t_img	gauche; // de cote gauche
	t_img	marche_d; // marche vers la droite
	t_img	marche_g; // marche vers la gauche
	t_img	ennemi;
}	t_sprites;

typedef struct map
{
	int		x; // nb of lines (la largeur de la map)
	int		y; // nb of columns (la longeur de la map)
	char	**map;
	int		spawn_x;
	int		spawn_y;
	int		exit_x;
	int		exit_y;
	int		nb_c; // nombre de collectible
}	t_map;

typedef struct master_struct
{
	void	*mlx; // pour le mlx_init()
	void	*window; // pour la fenetre
	t_sprites	sprites; // toutes les images
	int	player_position_x;
	int	player_position_y;
	int	steps; // le nombre de pas
	int	frame;
}	t_master;

typedef struct hook // celle la je l'utilise que pour les hooks
{
	t_master	*master;
	t_map		*map;
}	t_hook;

void	ft_free_tab(char ***tab);
size_t	ft_strlen_map(const char *s);
void	ft_free_map(t_map *map);
void	ft_check_map(t_map *map, char *filename);
void	ft_parse_map(t_map *map, char *filename);
void	ft_remove_nl(t_map *map);
void	ft_test_length_line(t_map *map);
int		side_walls(t_map *map);
int		top_down_walls(t_map *map);
void	ft_test_walls(t_map *map);
void	ft_test_elements(t_map *map);
void	ft_count_elements(t_map *map, int *nb_e, int *nb_p);
int		ft_test_forbidden_elements(t_map *map);
char	**copy_map(t_map *map);
void	ft_print_map_2(char **map);
void	flood_fill(int pos_p_x, int pos_p_y, char **map);
void	find_pos_of_spawn_exit(t_map *map);
void	ft_check_valid_path(t_map *map, char **map_filled);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	check_file_name(char *argv, t_map *map);
void	parse(t_map *map, char *filename);
void	init_data(t_master *master, t_map *map);
void	init_img(t_master *master, t_map *map);
t_img	get_addr_img(t_master *master, t_map *map, char *filename);
void	draw_map(t_master *master, t_map *map);
void	ft_mouvements(int touche, t_hook *hook);
int	keyboard(int touche, t_hook *hook);

#endif