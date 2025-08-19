// #include "minilibx_macos/mlx.h"

// #include <stdio.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }

#include "minilibx_macos/mlx.h"




typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	// int width = 50;
	// int height = 75;
	// int i = 0;
	// while (i < width)
	// {
	// 	my_mlx_pixel_put(&img, 250 + i, 250, 0x00FF0000);
	// 	my_mlx_pixel_put(&img, 250 + i, 250 + height, 0x00FF0000);
	// 	i ++;
	// }
	// int j = 0;
	// while (j < height)
	// {
	// 	my_mlx_pixel_put(&img, 250, 250 + j, 0x00FF0000);
	// 	my_mlx_pixel_put(&img, 250 + width, 250 + j, 0x00FF0000);
	// 	j++;
	// }

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
