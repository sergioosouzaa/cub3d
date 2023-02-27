
#include "cube.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int get_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void	print_floor(t_data *img, int floor_color, int ceiling_color)
{
	int i;
	int	j;
	i = 0;
	j = 0;
	while (i < screenWidth)
	{
		j = 0;
		while (j < screenHeight)
		{
			if (j < (screenHeight / 4) * 3)
				my_mlx_pixel_put(img, i, j, floor_color);
			else
				my_mlx_pixel_put(img, i, j, ceiling_color);
			j++;
		}
		i++;
	}
}

void	get_sprites(t_game *game)
{
	int x;
	int y;

	x = screenWidth;
	y = screenHeight;
	game->sky.img = mlx_xpm_file_to_image(game->mlx, "./sprits/sky.xpm", &x, &y);
	game->sky.addr=  mlx_get_data_addr(game->sky.img, &game->sky.bits_per_pixel, &game->sky.line_length,
							&game->sky.endian);
	game->img_1.img = mlx_xpm_file_to_image(game->mlx, "./sprits/Wood.xpm", &game->size_txt, &game->size_txt);
	game->img_1.addr = mlx_get_data_addr(game->img_1.img, &game->img_1.bits_per_pixel, &game->img_1.line_length,
							&game->img_1.endian);
	game->img_2.img = mlx_xpm_file_to_image(game->mlx, "./sprits/Circle.xpm", &game->size_txt, &game->size_txt);
	game->img_2.addr = mlx_get_data_addr(game->img_2.img, &game->img_2.bits_per_pixel, &game->img_2.line_length,
							&game->img_2.endian);
	game->img_3.img = mlx_xpm_file_to_image(game->mlx, "./sprits/Yellow.xpm", &game->size_txt, &game->size_txt);
	game->img_3.addr = mlx_get_data_addr(game->img_3.img, &game->img_3.bits_per_pixel, &game->img_3.line_length,
							&game->img_3.endian);
	game->img_4.img = mlx_xpm_file_to_image(game->mlx, "./sprits/Brick.xpm", &game->size_txt, &game->size_txt);
	game->img_4.addr = mlx_get_data_addr(game->img_4.img, &game->img_4.bits_per_pixel, &game->img_4.line_length,
							&game->img_4.endian);
}