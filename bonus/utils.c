
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

void create_sprites(t_game *game)
{
	game->sprites = malloc(sizeof(t_sprite) * 2);
	game->sprites[0].pos_x = 10;
	game->sprites[0].pos_y = 4;
	game->sprites[1].pos_x = 10;
	game->sprites[1].pos_y = 4;
	game->sprites->sprite = 0;
	
	game->mode = 1;
}

void game_init(t_game *game, t_map pos)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, screenWidth, screenHeight, "window");
	game->size_txt = texWidth;
	get_sprites(game);
	game->img.img = mlx_new_image(game->mlx, screenWidth, screenHeight);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length,
								&game->img.endian);
	game->map = pos;
}

void	get_sprites(t_game *game)
{
	game->door.img = mlx_xpm_file_to_image(game->mlx, "./sprits/door.xpm", &game->size_txt, &game->size_txt);
	game->door.addr=  mlx_get_data_addr(game->door.img, &game->door.bits_per_pixel, &game->door.line_length,
							&game->door.endian);
	game->img_1.img = mlx_xpm_file_to_image(game->mlx, "./sprits/sprite1.xpm", &game->size_txt, &game->size_txt);
	game->img_1.addr = mlx_get_data_addr(game->img_1.img, &game->img_1.bits_per_pixel, &game->img_1.line_length,
							&game->img_1.endian);
	game->img_2.img = mlx_xpm_file_to_image(game->mlx, "./sprits/sprite2.xpm", &game->size_txt, &game->size_txt);
	game->img_2.addr = mlx_get_data_addr(game->img_2.img, &game->img_2.bits_per_pixel, &game->img_2.line_length,
							&game->img_2.endian);
	game->img_3.img = mlx_xpm_file_to_image(game->mlx, "./sprits/sprite3.xpm", &game->size_txt, &game->size_txt);
	game->img_3.addr = mlx_get_data_addr(game->img_3.img, &game->img_3.bits_per_pixel, &game->img_3.line_length,
							&game->img_3.endian);
	game->img_4.img = mlx_xpm_file_to_image(game->mlx, "./sprits/sprite4.xpm", &game->size_txt, &game->size_txt);
	game->img_4.addr = mlx_get_data_addr(game->img_4.img, &game->img_4.bits_per_pixel, &game->img_4.line_length,
							&game->img_4.endian);
}

int exit_close()
{
	system("killall afplay");
	exit(0);
	return (0);
}