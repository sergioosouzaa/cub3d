#include "cube.h"

void    open_char_select(t_game *game)
{
	int screen_width;
	int screen_height;

	screen_width = screenWidth;
	screen_height = screenHeight;
	game->menu = malloc(sizeof(t_data) * 5);
	game->menu[0].img = mlx_xpm_file_to_image(game->mlx,"./sprits/peach_menu.xpm" , &screen_width, &screen_height);
	game->menu[0].addr=  mlx_get_data_addr(game->menu[0].img, &game->menu[0].bits_per_pixel, &game->menu[0].line_length,
						&game->menu[0].endian);	
	game->menu[1].img = mlx_xpm_file_to_image(game->mlx,"./sprits/peach_menu2.xpm" , &screen_width, &screen_height);
	game->menu[1].addr=  mlx_get_data_addr(game->menu[1].img, &game->menu[1].bits_per_pixel, &game->menu[1].line_length,
						&game->menu[1].endian);	
	game->menu[2].img = mlx_xpm_file_to_image(game->mlx,"./sprits/luigi_menu.xpm" , &screen_width, &screen_height);
	game->menu[2].addr=  mlx_get_data_addr(game->menu[2].img, &game->menu[2].bits_per_pixel, &game->menu[2].line_length,
						&game->menu[2].endian);	
	game->menu[3].img = mlx_xpm_file_to_image(game->mlx,"./sprits/luigi_menu2.xpm" , &screen_width, &screen_height);
	game->menu[3].addr=  mlx_get_data_addr(game->menu[3].img, &game->menu[3].bits_per_pixel, &game->menu[3].line_length,
						&game->menu[3].endian);	
	game->menu[4].img = mlx_xpm_file_to_image(game->mlx,"./sprits/char_select.xpm" , &screen_width, &screen_height);
	game->menu[4].addr=  mlx_get_data_addr(game->menu[4].img, &game->menu[4].bits_per_pixel, &game->menu[4].line_length,
						&game->menu[4].endian);	

}

void	open_luigi(t_game *game, int title_size)
{
	game->my_char.txt1.img = mlx_xpm_file_to_image(game->mlx, "./sprits/luigi_race1.xpm", &game->size_txt, &game->size_txt);
	game->my_char.txt1.addr=  mlx_get_data_addr(game->my_char.txt1.img, &game->my_char.txt1.bits_per_pixel, &game->my_char.txt1.line_length,
							&game->my_char.txt1.endian);
	game->my_char.txt2.img = mlx_xpm_file_to_image(game->mlx, "./sprits/luigi_race2.xpm", &game->size_txt, &game->size_txt);
	game->my_char.txt2.addr=  mlx_get_data_addr(game->my_char.txt2.img, &game->my_char.txt2.bits_per_pixel, &game->my_char.txt2.line_length,
							&game->my_char.txt2.endian);
	game->my_char.txt3.img = mlx_xpm_file_to_image(game->mlx, "./sprits/luigi_race3.xpm", &game->size_txt, &game->size_txt);
	game->my_char.txt3.addr=  mlx_get_data_addr(game->my_char.txt3.img, &game->my_char.txt3.bits_per_pixel, &game->my_char.txt3.line_length,
							&game->my_char.txt3.endian);	
	game->my_char.txt4.img = mlx_xpm_file_to_image(game->mlx, "./sprits/luigi_race4.xpm", &game->size_txt, &game->size_txt);
	game->my_char.txt4.addr=  mlx_get_data_addr(game->my_char.txt4.img, &game->my_char.txt4.bits_per_pixel, &game->my_char.txt4.line_length,
							&game->my_char.txt4.endian);	
	game->minimap.img = mlx_xpm_file_to_image(game->mlx, "./sprits/luigi_profile.xpm", &title_size, &title_size);
	game->minimap.addr = mlx_get_data_addr(game->minimap.img, &game->minimap.bits_per_pixel, &game->minimap.line_length,
							&game->minimap.endian);
}

void	open_peach(t_game *game, int title_size)
{
	game->my_char.txt1.img = mlx_xpm_file_to_image(game->mlx, "./sprits/peach_race1.xpm", &game->size_txt, &game->size_txt);
	game->my_char.txt1.addr=  mlx_get_data_addr(game->my_char.txt1.img, &game->my_char.txt1.bits_per_pixel, &game->my_char.txt1.line_length,
							&game->my_char.txt1.endian);
	game->my_char.txt2.img = mlx_xpm_file_to_image(game->mlx, "./sprits/peach_race2.xpm", &game->size_txt, &game->size_txt);
	game->my_char.txt2.addr=  mlx_get_data_addr(game->my_char.txt2.img, &game->my_char.txt2.bits_per_pixel, &game->my_char.txt2.line_length,
							&game->my_char.txt2.endian);
	game->my_char.txt3.img = mlx_xpm_file_to_image(game->mlx, "./sprits/peach_race3.xpm", &game->size_txt, &game->size_txt);
	game->my_char.txt3.addr=  mlx_get_data_addr(game->my_char.txt3.img, &game->my_char.txt3.bits_per_pixel, &game->my_char.txt3.line_length,
							&game->my_char.txt3.endian);	
	game->my_char.txt4.img = mlx_xpm_file_to_image(game->mlx, "./sprits/peach_race4.xpm", &game->size_txt, &game->size_txt);
	game->my_char.txt4.addr=  mlx_get_data_addr(game->my_char.txt4.img, &game->my_char.txt4.bits_per_pixel, &game->my_char.txt4.line_length,
							&game->my_char.txt4.endian);	
	game->minimap.img = mlx_xpm_file_to_image(game->mlx, "./sprits/peach_profile.xpm", &title_size, &title_size);
	game->minimap.addr = mlx_get_data_addr(game->minimap.img, &game->minimap.bits_per_pixel, &game->minimap.line_length,
							&game->minimap.endian);
}

void	handle_char_select(t_game *game)
{
	int	max_side;
	int	side;

	max_side = mapWidth;
	side = 0.3 * screenWidth;
	if (mapHeight > mapWidth)
	{
		max_side = mapHeight;
		side = 0.3 * screenHeight;
	}
	side = (side / max_side) / 256;
	if(game->key.rotate_l)
		game->char_select = 0;
	if(game->key.rotate_r)
		game->char_select = 1;
	if(game->key.space)
	{
		game->mode = 3;
		mlx_destroy_image(game->mlx, game->menu[0].img);
		mlx_destroy_image(game->mlx, game->menu[1].img);
		mlx_destroy_image(game->mlx, game->menu[2].img);
		mlx_destroy_image(game->mlx, game->menu[3].img);
		free(game->menu);
		if (game->char_select == 0)
			open_luigi(game, side);
		else
			open_peach(game, side);
		max_side = screenHeight;
		side = screenWidth;
		game->menu = malloc(sizeof(t_data));
		game->menu[0].img = mlx_xpm_file_to_image(game->mlx,"./sprits/controls.xpm" , &side, &max_side);
		game->menu[0].addr=  mlx_get_data_addr(game->menu[0].img, &game->menu[0].bits_per_pixel, &game->menu[0].line_length,
							&game->menu[0].endian);
	}
	game->key.space = 0;
}
