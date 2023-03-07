#include "cube.h"

void	open_menu(t_game *game)
{
	int screen_width;
	int screen_height;

	screen_width = screenWidth * 3;
	screen_height = screenHeight * 3;
	game->menu = malloc(sizeof(t_data) * 3);
	game->menu[0].img = mlx_xpm_file_to_image(game->mlx,"./sprits/menu1.xpm" , &screen_width, &screen_height);
	game->menu[0].addr=  mlx_get_data_addr(game->menu[0].img, &game->menu[0].bits_per_pixel, &game->menu[0].line_length,
							&game->menu[0].endian);	
	game->menu[1].img = mlx_xpm_file_to_image(game->mlx,"./sprits/menu2.xpm" , &screen_width, &screen_height);
	game->menu[1].addr=  mlx_get_data_addr(game->menu[1].img, &game->menu[1].bits_per_pixel, &game->menu[1].line_length,
							&game->menu[1].endian);	
	game->menu[2].img = mlx_xpm_file_to_image(game->mlx,"./sprits/menu3.xpm" , &screen_width, &screen_height);
	game->menu[2].addr=  mlx_get_data_addr(game->menu[2].img, &game->menu[2].bits_per_pixel, &game->menu[2].line_length,
							&game->menu[2].endian);
}

void	display_menu(t_game *game)
{
	static long long last_time;
	static	int			i;

	if (get_first_time() - last_time > 150)
	{
		i = (i + 1) % 3;
		last_time = get_first_time();
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->menu[i].img, 0, 0);
}

int	handle_menu(t_game *game)
{
	if (game->key.space)
	{
		mlx_destroy_image(game->mlx, game->menu[0].img);
		mlx_destroy_image(game->mlx, game->menu[1].img);
		mlx_destroy_image(game->mlx, game->menu[2].img);
		free(game->menu);
		game->mode = 2;
        open_char_select(game);
        game->char_select = 0;
        game->key.space = 0;
	}
	return (0);
}