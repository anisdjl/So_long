/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:03:37 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/30 14:03:30 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "minilibx_linux/mlx.h"
#include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
}	t_mlx;

typedef struct map
{
	int	x; // nb of lines (la largeur de la map)
	int	y; // nb of columns (la longeur de la map)
	char	**map;
}	t_map;

void	ft_free_tab(char ***tab);
size_t	ft_strlen_map(const char *s);
void	ft_free_map(t_map *map);
void	ft_check_map(t_map *map);
void	ft_parse_map(t_map *map);
void	ft_remove_nl(t_map *map);
void	ft_test_length_line(t_map *map);
int		side_walls(t_map *map);
int		top_down_walls(t_map *map);
void	ft_test_walls(t_map *map);
void	ft_test_elements(t_map *map);
void	ft_count_elements(t_map *map, int *nb_c, int *nb_e, int *nb_p);
int	ft_test_forbidden_elements(t_map *map);
char	**copy_map(t_map *map);
void	ft_print_map_2(char **map);
void	flood_fill(int pos_p_x, int pos_p_y, char **map);

#endif