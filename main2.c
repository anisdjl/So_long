// #include "so_long.h"

// int	handle_input(int keysym, void **mlx, void **window)
// {
// 	if (keysym == 65307 || keysym == 53)
// 	{
// 		mlx_destroy_window(*mlx, *window);
// 		exit (0);
// 	}
// 	return (0);
// }

// int main(void)
// {
// 	void	*mlx;
// 	void	*window;
// 	void	*pic_ptr;
// 	int		width;
// 	int		height;

// 	mlx = mlx_init();
// 	if (!mlx)
// 		return (0);
//window = mlx_new_window(mlx, 1920, 1080, "rien");
// 	pic_ptr = mlx_xpm_file_to_image(mlx, "mr_robot.xpm", &width, &height);
// 	mlx_put_image_to_window(mlx, window, pic_ptr, 170, 175);

// 	//mlx_key_hook(window, handle_input, mlx);
// 	mlx_loop(mlx);
// }