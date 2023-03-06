
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
	game->sprites = malloc(sizeof(t_sprite));
	game->sprites->pos_x = 10;
	game->sprites->pos_y = 4;
	game->sprites->dir_x= game->map.dir_x;
	game->sprites->dir_y= game->map.dir_y;
	game->sprites->texture = malloc(3 *sizeof(t_data));
	game->sprites->sprite = 0;
	game->sprites->texture[0].img = mlx_xpm_file_to_image(game->mlx, "./sprits/mariogay.xpm", &game->size_txt, &game->size_txt);
	game->sprites->texture[0].addr=  mlx_get_data_addr(game->sprites->texture[0].img, &game->sprites->texture[0].bits_per_pixel, &game->sprites->texture[0].line_length,
							&game->sprites->texture[0].endian);
	game->sprites->texture[1].img = mlx_xpm_file_to_image(game->mlx, "./sprits/mario2.xpm", &game->size_txt, &game->size_txt);
	game->sprites->texture[1].addr=  mlx_get_data_addr(game->sprites->texture[1].img, &game->sprites->texture[1].bits_per_pixel, &game->sprites->texture[1].line_length,
							&game->sprites->texture[1].endian);
	game->sprites->texture[2].img = mlx_xpm_file_to_image(game->mlx, "./sprits/mario3.xpm", &game->size_txt, &game->size_txt);
	game->sprites->texture[2].addr=  mlx_get_data_addr(game->sprites->texture[2].img, &game->sprites->texture[2].bits_per_pixel, &game->sprites->texture[2].line_length,
							&game->sprites->texture[2].endian);	

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
	int	max_side;
	int	side;
	int title_size;

	x = screenWidth;
	y = screenHeight;
	if (mapHeight > mapWidth)
	{
		max_side = mapHeight;
		side = 0.2 * screenHeight;
	}
	else
	{
		max_side = mapWidth;
		side = 0.2 * screenWidth;
	}
	title_size = (side / max_side) / 256;
	game->door.img = mlx_xpm_file_to_image(game->mlx, "./sprits/door.xpm", &x, &y);
	game->door.addr=  mlx_get_data_addr(game->door.img, &game->door.bits_per_pixel, &game->door.line_length,
							&game->door.endian);
	game->img_1.img = mlx_xpm_file_to_image(game->mlx, "./sprits/star_road1.xpm", &game->size_txt, &game->size_txt);
	game->img_1.addr = mlx_get_data_addr(game->img_1.img, &game->img_1.bits_per_pixel, &game->img_1.line_length,
							&game->img_1.endian);
	game->img_2.img = mlx_xpm_file_to_image(game->mlx, "./sprits/star_road1.xpm", &game->size_txt, &game->size_txt);
	game->img_2.addr = mlx_get_data_addr(game->img_2.img, &game->img_2.bits_per_pixel, &game->img_2.line_length,
							&game->img_2.endian);
	game->img_3.img = mlx_xpm_file_to_image(game->mlx, "./sprits/star_road1.xpm", &game->size_txt, &game->size_txt);
	game->img_3.addr = mlx_get_data_addr(game->img_3.img, &game->img_3.bits_per_pixel, &game->img_3.line_length,
							&game->img_3.endian);
	game->img_4.img = mlx_xpm_file_to_image(game->mlx, "./sprits/star_road2.xpm", &game->size_txt, &game->size_txt);
	game->img_4.addr = mlx_get_data_addr(game->img_4.img, &game->img_4.bits_per_pixel, &game->img_4.line_length,
							&game->img_4.endian);
	game->minimap.img = mlx_xpm_file_to_image(game->mlx, "./sprits/profile.xpm", &title_size, &title_size);
	game->minimap.addr = mlx_get_data_addr(game->minimap.img, &game->minimap.bits_per_pixel, &game->minimap.line_length,
							&game->minimap.endian);
}