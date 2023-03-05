
#include "cube.h"

t_map	get_pos(void)
{
	t_map	map;

	map.pos_x = 8.0;
	map.pos_y = 4.0;
	map.dir_x = -1.0;
	map.dir_y = 0.0;
	map.plane_x = 0.0;
	map.plane_y = 0.66;
	return (map);
}

int	handle_press(int key, t_game *game)
{
	double	aux;

	if (key == KEY_LEFT)
	{
		aux = game->map.dir_x;
	  	game->map.dir_x = game->map.dir_x * cos(-rot) - game->map.dir_y * sin(-rot);
	  	game->map.dir_y = aux * sin(-rot) + game->map.dir_y  * cos(-rot);
	  	aux = game->map.plane_x;
	  	game->map.plane_x = game->map.plane_x * cos(-rot) - game->map.plane_y * sin(-rot);
	  	game->map.plane_y = aux * sin(-rot) + game->map.plane_y * cos(-rot);
	}
	if (key == KEY_RIGHT)
	{		
		aux = game->map.dir_x;
	  	game->map.dir_x = game->map.dir_x * cos(rot) - game->map.dir_y * sin(rot);
	  	game->map.dir_y = aux * sin(rot) + game->map.dir_y  * cos(rot);
	  	aux = game->map.plane_x;
	  	game->map.plane_x = game->map.plane_x * cos(rot) - game->map.plane_y * sin(rot);
	  	game->map.plane_y = aux * sin(rot) + game->map.plane_y * cos(rot);
	}
	if (key == KEY_DOWN)
	{
		game->map.pos_x -= game->map.dir_x * 0.1;
		game->map.pos_y -= game->map.dir_y * 0.1;
	}
	if (key == KEY_UP)
	{
		game->map.pos_x += game->map.dir_x * 0.1;
		game->map.pos_y += game->map.dir_y * 0.1;
	}
	mlx_destroy_image(game->mlx, game->img.img);
	game->img.img = mlx_new_image(game->mlx, screenWidth, screenHeight);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length,
								&game->img.endian);
	mlx_clear_window(game->mlx, game->mlx_win);
	raycast(*game);
	return (0);
}

int	handle_key(int key, t_game *game)
{
	double	aux;

	if (key == KEY_LEFT)
	{
		aux = game->map.dir_x;
	  	game->map.dir_x = game->map.dir_x * cos(-rot) - game->map.dir_y * sin(-rot);
	  	game->map.dir_y = aux * sin(-rot) + game->map.dir_y  * cos(-rot);
	  	aux = game->map.plane_x;
	  	game->map.plane_x = game->map.plane_x * cos(-rot) - game->map.plane_y * sin(-rot);
	  	game->map.plane_y = aux * sin(-rot) + game->map.plane_y * cos(-rot);
	}
	if (key == KEY_RIGHT)
	{		
		aux = game->map.dir_x;
	  	game->map.dir_x = game->map.dir_x * cos(rot) - game->map.dir_y * sin(rot);
	  	game->map.dir_y = aux * sin(rot) + game->map.dir_y  * cos(rot);
	  	aux = game->map.plane_x;
	  	game->map.plane_x = game->map.plane_x * cos(rot) - game->map.plane_y * sin(rot);
	  	game->map.plane_y = aux * sin(rot) + game->map.plane_y * cos(rot);
	}
	if (key == KEY_DOWN)
	{
		game->map.pos_x -= game->map.dir_x * 0.1;
		game->map.pos_y -= game->map.dir_y * 0.1;
	}
	if (key == KEY_UP)
	{
		game->map.pos_x += game->map.dir_x * 0.1;
		game->map.pos_y += game->map.dir_y * 0.1;
	}
	mlx_destroy_image(game->mlx, game->img.img);
	game->img.img = mlx_new_image(game->mlx, screenWidth, screenHeight);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length,
								&game->img.endian);
	mlx_clear_window(game->mlx, game->mlx_win);
	raycast(*game);
	return (0);
}

int main(void)
{
	t_map	pos;
	t_game	game;

	pos = get_pos();
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, screenWidth, screenHeight, "window");
	game.size_txt = texWidth;
	get_sprites(&game);
	game.img.img = mlx_new_image(game.mlx, screenWidth, screenHeight);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length,
								&game.img.endian);
	game.map = pos;
	game.ceiling_color =  0x000000FF;
	game.floor_color =  0x00F00FFF;
	raycast(game);
	mlx_hook(game.mlx_win, 2, (1L<<0), &handle_press,  &game);
	mlx_key_hook(game.mlx_win, handle_key, &game);
	mlx_loop(game.mlx);			
}
