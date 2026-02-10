/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:03:37 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/10 10:38:39 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <math.h>
# include "minilibx_linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>
# include "printf/ft_printf.h"

typedef struct sprites_for_the_game
{
	void	*murs;
	void	*sols;
	void	*e_f;
	void	*e_o;
	void	*gemme;
	void	*gemme_2;
	void	*face;
	void	*dos;
	void	*droite;
	void	*gauche;
	void	*marche_d;
	void	*marche_g;
	void	*ennemi;
	void	*enemy2;
}	t_sprites;

typedef struct map
{
	int		x;
	int		y;
	char	**map;
	int		spawn_x;
	int		spawn_y;
	int		exit_x;
	int		exit_y;
	int		nb_c;
	int		side;
	int		nb_enemy;
}	t_map;

typedef struct enemy
{
	int	pos_e_x;
	int	pos_e_y;
	int	dir;
	int	count;
}	t_enemy;

typedef struct master_struct
{
	void		*mlx;
	void		*window;
	t_sprites	*sprites;
	int			opps_pos_x;
	int			opps_pos_y;
	int			steps;
	int			frame;
	int			walk;
	t_enemy		**enemy;
}	t_master;

typedef struct hook
{
	t_master	*master;
	t_map		*map;
	int			count;
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
void	draw_map2(t_master *master, t_map *map, int x, int y);
void	draw_map3(t_master *master, t_map *map, int x, int y);
void	display_annim(t_hook *hook, int a, int b);
void	init(t_map *map, char *argv);
t_enemy	*create_struct_ennemis(t_hook *hook, int y, int a, t_enemy **ennemis);
void	ft_free_ennemis(t_hook *hook);
void	ft_free_error_malloc_ennemis(t_hook *hook, t_enemy **ennemis);
void	init_master(t_master *master, t_map *map);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
void	check_file_name2(char *argv, t_map *map);
int		opti_draw(t_hook *hook);
void	*find_ptr(t_master *master, t_map *map, int x, int y);
void	*find_ptr2(t_master *master, t_map *map, int x, int y);

#endif