/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:03:37 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/06 15:07:31 by adjelili         ###   ########.fr       */
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

typedef struct sprites_for_the_game
{
	void	*murs;
	void	*sols;
	void	*e_f; // sortie fermee
	void	*e_o; // sortie ouverte
	void	*gemme;
	void	*gemme_2;
	void	*face; // face
	void	*dos; // dos
	void	*droite; // de cote droit
	void	*gauche; // de cote gauche
	void	*marche_d; // marche vers la droite
	void	*marche_g; // marche vers la gauche
	void	*ennemi;
	void	*enemy2;
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
	int		side;
	int		nb_enemy;
}	t_map;

typedef	struct enemy
{
	int pos_e_x;
	int pos_e_y;
	int	dir;
}	t_enemy;

typedef struct master_struct
{
	void	*mlx; // pour le mlx_init()
	void	*window; // pour la fenetre
	t_sprites	*sprites; // toutes les images
	int	opps_pos_x;
	int	opps_pos_y;
	int	steps; // le nombre de pas
	int	frame;
	int	walk;
	t_enemy **enemy;
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
void	*get_addr_img(t_master *master, t_map *map, char *filename);
void	draw_map(t_master *master, t_map *map);
void	up(t_hook *hook);
void	down(t_hook *hook);
void	right(t_hook *hook);
void	left(t_hook *hook);
int		keyboard(int touche, t_hook *hook);
char	*ft_itoa(int n);
int		ft_exit(t_hook *hook);
void	ft_destroy_img(t_master *master);
int		animation(t_hook *hook);
void	nb_enemy(t_map *map);
t_enemy	**init_ennemis(t_hook *hook);
void	ft_move_ennemis(t_hook *hook);
int	enemy(t_hook *hook);

#endif