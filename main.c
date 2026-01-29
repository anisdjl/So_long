/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:47:31 by adjelili          #+#    #+#             */
/*   Updated: 2026/01/28 11:31:17 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minilibx_linux/mlx.h"
// #include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixels / 8));
// 	*(unsigned int*)dst = color;
// }

// int main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	// t_data img;
// 	// int y;
// 	// int x;
// 	void	*img_pointer;
// 	int pic_height;
// 	int pic_width;

// 	mlx = mlx_init(); // cree une fenetre ?
// 	//img.img = mlx_new_image(mlx, 1920, 1080);
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long"); // envoie un pointeur sur la fenetre qu'on ivent de creer
// 	img_pointer = mlx_xpm_file_to_image(mlx, "./wp4507677-mr-robot-wallpapers.jpg", &pic_width, &pic_height);
// 	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, &img.line_length, &img.endian);
// 	// x = 480;
// 	// while (x < 480 * 2)
// 	// {
// 	// 	y = 1080 / 4;
// 	// 	while (y < (1080 / 4) * 2)
// 	// 	{
// 	// 		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
// 	// 		y++;
// 	// 	}
// 	// 	x++;
// 	// }
	
// 	mlx_put_image_to_window(mlx, mlx_win, img_pointer, 0, 0);
// 	mlx_loop(mlx);
// }

// int main(void)
// {
// 	void	*window;
// 	void	*mlx_window;
	
// 	window = mlx_init();
// 	mlx_window = mlx_new_window(window, 800,800, "hello");
// 	mlx_loop(window);
// }

// int main(void)
// {
// 	void	*mlx;
// 	void	*img;

// 	mlx = mlx_init();
// 	img = mlx_new_window(mlx, 1920, 1080, "hello");
	
// 	mlx_loop(mlx);
// }