
#include "cube.h"

int	worldMap[mapWidth][mapHeight]=
{
	{ 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7 },
	{ 4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7 },
	{ 4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7 },
	{ 4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7 },
	{ 4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7 },
	{ 4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7 },
	{ 4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1 },
	{ 4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8 },
	{ 4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1 },
	{ 4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8 },
	{ 4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1 },
	{ 4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1 },
	{ 6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6 },
	{ 8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 },
	{ 6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6 },
	{ 4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3 },
	{ 4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2 },
	{ 4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2 },
	{ 4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2 },
	{ 4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2 },
	{ 4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2 },
	{ 4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2 },
	{ 4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2 },
	{ 4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3 }
};

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

	if (key == KEY_LEFT)
		game->key.rotate_l = 1;
	if (key == KEY_RIGHT)	
		game->key.rotate_r = 1;
	if (key == KEY_DOWN)
		game->key.down = 1;
	if (key == KEY_UP)
		game->key.up = 1;
	return (0);
}

int handle_release(int key, t_game *game)
{
	if (key == KEY_LEFT)
		game->key.rotate_l = 0;
	if (key == KEY_RIGHT)	
		game->key.rotate_r = 0;
	if (key == KEY_DOWN)
		game->key.down = 0;
	if (key == KEY_UP)
		game->key.up = 0;
	return (0);
}

int	handle_key(t_game *game)
{
	double	aux;

	if (game->key.down && game->key.down != game->key.up)
	{
		game->map.pos_x -= game->map.dir_x * 0.05;
		game->map.pos_y -= game->map.dir_y * 0.05;
	}
	if (game->key.up && game->key.down != game->key.up)
	{		
		game->map.pos_x += game->map.dir_x * 0.05;
		game->map.pos_y += game->map.dir_y * 0.05;
	}
	if (game->key.rotate_l && game->key.rotate_l != game->key.rotate_r)
	{
		aux = game->map.dir_x;
	  	game->map.dir_x = game->map.dir_x * cos(-rot) - game->map.dir_y * sin(-rot);
	  	game->map.dir_y = aux * sin(-rot) + game->map.dir_y  * cos(-rot);
	  	aux = game->map.plane_x;
	  	game->map.plane_x = game->map.plane_x * cos(-rot) - game->map.plane_y * sin(-rot);
	  	game->map.plane_y = aux * sin(-rot) + game->map.plane_y * cos(-rot);
	}
	if (game->key.rotate_r && game->key.rotate_l != game->key.rotate_r)
	{
		aux = game->map.dir_x;
	  	game->map.dir_x = game->map.dir_x * cos(rot) - game->map.dir_y * sin(rot);
	  	game->map.dir_y = aux * sin(rot) + game->map.dir_y  * cos(rot);
	  	aux = game->map.plane_x;
	  	game->map.plane_x = game->map.plane_x * cos(rot) - game->map.plane_y * sin(rot);
	  	game->map.plane_y = aux * sin(rot) + game->map.plane_y * cos(rot);
	}
	return (0);
}

int	game_loop(t_game *game)
{
	handle_key(game);
	raycast(*game);
	return (0);
}

t_keys	init_keys(void)
{
	t_keys	key;

	key.up = 0;
	key.down = 0;
	key.esc = 0;
	key.rotate_r = 0;
	key.rotate_l = 0;
	return (key);
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
	game.key = init_keys();
	raycast(game);
	mlx_hook(game.mlx_win, 2, (1L<<0), &handle_press,  &game);
	mlx_hook(game.mlx_win, 3, (1L<<1), &handle_release,  &game);
	mlx_loop_hook(game.mlx, &game_loop, &game);
	mlx_loop(game.mlx);			
}