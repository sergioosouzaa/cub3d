
#include "cube.h"

int	worldMap[mapWidth][mapHeight]=
{
	{ 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7 },
	{ 4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7 },
	{ 4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7 },
	{ 4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7 },
	{ 4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7 },
	{ 4,0,4,0,0,0,0,5,9,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7 },
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
	map.dir_x = -0.5;
	map.dir_y = 0.0;
	map.plane_x = 0.00;
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
	if (key == KEY_SPACE)
		game->key.space = 1;
	if (key == KEY_SHIFT)
		game->key.shift = 1;
	return (0);
}

int handle_release(int key, t_game *game)
{
	if (key == KEY_LEFT)
	{
		game->key.rotate_l = 0;
		game->sprites->sprite = 1;
	}
	if (key == KEY_RIGHT)
	{
		game->key.rotate_r = 0;
		game->sprites->sprite = 1;
	}
	if (key == KEY_DOWN)
		game->key.down = 0;
	if (key == KEY_UP)
		game->key.up = 0;
	if (key == KEY_SPACE)
		game->key.space = 0;
	if (key == KEY_SHIFT)
		game->key.shift = 0;
	return (0);
}

int check_valid_cam(t_game *game, int signal)
{
	double aux_1;
	double aux_2;
	double aux_3;
	double aux_4;
	t_ray	ray_1;
	t_ray	ray_2;

	ray_init(&ray_1, *game, (screenWidth / 2) - 2 );
	side_dist_init(&ray_1, game->map);
	dda(&ray_1, *game, 0);
	ray_init(&ray_2, *game, (screenWidth / 2) + 2 );
	side_dist_init(&ray_2, game->map);
	dda(&ray_2, *game, 0);

	aux_1 = game->map.dir_x;
	aux_3 = game->map.dir_y;
	game->map.dir_x = game->map.dir_x * cos(rot * signal) - game->map.dir_y * sin(rot * signal);
	game->map.dir_y = aux_1 * sin(rot * signal) + game->map.dir_y  * cos(rot * signal);
	aux_2 = game->map.plane_x;
	aux_4 = game->map.plane_y;
	game->map.plane_x = game->map.plane_x * cos(rot * signal) - game->map.plane_y * sin(rot * signal);
	game->map.plane_y = aux_2 * sin(rot * signal) + game->map.plane_y * cos(rot * signal);
	game->sprites->sprite = 2;
	if ((ray_1.perpwalldist >= 1.5 &&  ray_2.perpwalldist >= 1.5))
			return (1); 
	else
	{
		game->map.dir_x = aux_1;
		game->map.plane_x = aux_2;
		game->map.dir_y = aux_3;
		game->map.plane_y = aux_4;
		return (0);
	}
}

int check_valid_pos(t_game *game, int signal, double speed)
{
	int pos_x;
	int pos_y;
	t_ray	ray_1;
	t_ray	ray_2;

	ray_init(&ray_1, *game, (screenWidth / 2) - 2 );
	side_dist_init(&ray_1, game->map);
	dda(&ray_1, *game, 0);
	ray_init(&ray_2, *game, (screenWidth / 2) + 2 );
	side_dist_init(&ray_2, game->map);
	dda(&ray_2, *game, 0);
	if (game->key.shift)
		speed = 0.12;
	pos_x = (int)(game->map.pos_x + signal * game->map.dir_x * speed);
	pos_y = (int)(game->map.pos_y + signal * game->map.dir_y * speed);
	if (pos_x > 0 && pos_x < mapWidth && pos_y > 0 && pos_y < mapHeight && worldMap[pos_x][pos_y] < 1)
	{
		if ((ray_1.perpwalldist >= 1.5 &&  ray_2.perpwalldist >= 1.5)|| signal == -1)
			return (1);
	}
	return (0);
}

int	handle_key(t_game *game)
{
	double speed;
	
	
	speed = 0.08;
	if (game->key.space)
		speed = 0.16;
	if (game->key.down && game->key.down != game->key.up)
	{
		if (check_valid_pos(game, -1, speed))
		{
			game->map.pos_x -= game->map.dir_x * speed;
			game->map.pos_y -= game->map.dir_y * speed;
		}
	}
	if (game->key.up && game->key.down != game->key.up)
	{	
		if (check_valid_pos(game, +1, speed))
		{	
			if (game->key.shift)
				speed = 0.12;
			game->map.pos_x += game->map.dir_x * speed;
			game->map.pos_y += game->map.dir_y * speed;
		}
	}
	if (game->key.rotate_l && game->key.rotate_l != game->key.rotate_r )
	{
		check_valid_cam(game, -1);
	}
	if (game->key.rotate_r && game->key.rotate_l != game->key.rotate_r)
	{
		check_valid_cam(game, 1);
	}

	return (0);
}

int	handle_menu(t_game *game)
{
	int screen_width;
	int screen_height;

	screen_width = screenWidth;
	screen_height = screenHeight;
	if (game->key.space)
	{
		mlx_destroy_image(game->mlx, game->menu[0].img);
		mlx_destroy_image(game->mlx, game->menu[1].img);
		mlx_destroy_image(game->mlx, game->menu[2].img);
		free(game->menu);
		game->mode = 2;
		game->menu = malloc(sizeof(t_data) * 5);
		game->menu[0].img = mlx_xpm_file_to_image(game->mlx,"./sprits/thais_menu.xpm" , &screen_width, &screen_height);
		game->menu[0].addr=  mlx_get_data_addr(game->menu[0].img, &game->menu[0].bits_per_pixel, &game->menu[0].line_length,
								&game->menu[0].endian);	
		game->menu[1].img = mlx_xpm_file_to_image(game->mlx,"./sprits/thais_menu2.xpm" , &screen_width, &screen_height);
		game->menu[1].addr=  mlx_get_data_addr(game->menu[1].img, &game->menu[1].bits_per_pixel, &game->menu[1].line_length,
								&game->menu[1].endian);	
		game->menu[2].img = mlx_xpm_file_to_image(game->mlx,"./sprits/luigi_menu.xpm" , &screen_width, &screen_height);
		game->menu[2].addr=  mlx_get_data_addr(game->menu[2].img, &game->menu[2].bits_per_pixel, &game->menu[2].line_length,
								&game->menu[2].endian);	
		game->menu[3].img = mlx_xpm_file_to_image(game->mlx,"./sprits/luigi_menu2.xpm" , &screen_width, &screen_height);
		game->menu[3].addr=  mlx_get_data_addr(game->menu[3].img, &game->menu[3].bits_per_pixel, &game->menu[3].line_length,
								&game->menu[3].endian);	
		game->menu[4].img = mlx_xpm_file_to_image(game->mlx,"./sprits/start1.xpm" , &screen_width, &screen_height);
		game->menu[4].addr=  mlx_get_data_addr(game->menu[4].img, &game->menu[4].bits_per_pixel, &game->menu[4].line_length,
								&game->menu[4].endian);	
		game->char_select = 0;
		game->key.space = 0;
		usleep(20000);
	}
	return (0);
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


/// carregar os sprites
void	handle_char_select(t_game *game)
{
	if(game->key.rotate_l)
	{
		game->char_select = 0;
	}
	if(game->key.rotate_r)
	{
		game->char_select = 1;
	}
	if(game->key.space)
	{
		game->mode = 3;
		// game->my_char =  malloc(sizeof(t_data) * 4);
		// if (game->char_select == 0)
		// {
		// 	game->my_char[0].img = mlx_xpm_file_to_image(game->mlx, "./sprits/mariogay.xpm", &game->size_txt, &game->size_txt);
		// 	game->my_char[0].addr=  mlx_get_data_addr(game->my_char[0].img, &game->my_char[0].bits_per_pixel, &game->my_char[0].line_length,
		// 							&game->my_char[0].endian);
		// 	game->my_char[1].img = mlx_xpm_file_to_image(game->mlx, "./sprits/mario2.xpm", &game->size_txt, &game->size_txt);
		// 	game->my_char[1].addr=  mlx_get_data_addr(game->my_char[1].img, &game->my_char[1].bits_per_pixel, &game->my_char[1].line_length,
		// 							&game->my_char[1].endian);
		// 	game->my_char[2].img = mlx_xpm_file_to_image(game->mlx, "./sprits/mario3.xpm", &game->size_txt, &game->size_txt);
		// 	game->my_char[2].addr=  mlx_get_data_addr(game->my_char[2].img, &game->my_char[2].bits_per_pixel, &game->my_char[2].line_length,
		// 							&game->my_char[2].endian);	
		// 	game->my_char[3].img = mlx_xpm_file_to_image(game->mlx, "./sprits/mario3.xpm", &game->size_txt, &game->size_txt);
		// 	game->my_char[3].addr=  mlx_get_data_addr(game->my_char[3].img, &game->my_char[3].bits_per_pixel, &game->my_char[3].line_length,
		// 							&game->my_char[3].endian);	
		// }
		// else
		// {
		// 	game->my_char[0].img = mlx_xpm_file_to_image(game->mlx, "./sprits/mariogay.xpm", &game->size_txt, &game->size_txt);
		// 	game->my_char[0].addr=  mlx_get_data_addr(game->my_char[0].img, &game->my_char[0].bits_per_pixel, &game->my_char[0].line_length,
		// 							&game->my_char[0].endian);
		// 	game->my_char[1].img = mlx_xpm_file_to_image(game->mlx, "./sprits/mario2.xpm", &game->size_txt, &game->size_txt);
		// 	game->my_char[1].addr=  mlx_get_data_addr(game->my_char[1].img, &game->my_char[1].bits_per_pixel, &game->my_char[1].line_length,
		// 							&game->my_char[1].endian);
		// 	game->my_char[2].img = mlx_xpm_file_to_image(game->mlx, "./sprits/mario3.xpm", &game->size_txt, &game->size_txt);
		// 	game->my_char[2].addr=  mlx_get_data_addr(game->my_char[2].img, &game->my_char[2].bits_per_pixel, &game->my_char[2].line_length,
		// 							&game->my_char[2].endian);	
		// 	game->my_char[3].img = mlx_xpm_file_to_image(game->mlx, "./sprits/mario3.xpm", &game->size_txt, &game->size_txt);
		// 	game->my_char[3].addr=  mlx_get_data_addr(game->my_char[3].img, &game->my_char[3].bits_per_pixel, &game->my_char[3].line_length,
		// 							&game->my_char[3].endian);	
		// }
		// game->my_char
	}
}



void	display_char_select(t_game *game)
{
	static long long last_time;
	static	int			i;

	if (get_first_time() - last_time > 150)
	{
		i = (i + 1) % 2;
		last_time = get_first_time();
	}
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->menu[4].img, 0, 0);
	if (game->char_select == 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->menu[0].img, (screenWidth / 4) * 0.8, screenHeight / 2);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->menu[2 + i].img, (screenWidth / 4) * 3, screenHeight / 2);
	}
	else if(game->char_select == 1)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->menu[i].img, (screenWidth / 4) * 0.8, screenHeight / 2);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->menu[2].img, (screenWidth / 4) * 3, screenHeight / 2);
	}
}


int	game_loop(t_game *game)
{
	if (game->mode == 3)
	{
		handle_key(game);
		raycast(*game);
	}
	else if (game->mode == 1)
	{
		display_menu(game);
		handle_menu(game);
	}
	else if (game->mode == 2)
	{
		display_char_select(game);
		handle_char_select(game);
	}
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
	key.space	= 0;
	key.shift = 0;
	return (key);
}


int main(void)
{
	t_map	pos;
	t_game	game;

	
	game.first_time = get_first_time();
	initialize_chaos();
	pos = get_pos();
	game_init(&game, pos);
	create_sprites(&game);
	
	game.ceiling_color =  0x000000FF;
	game.floor_color =  0x00F00FFF;
	game.key = init_keys();
	// game.time = time;
	game.mode = 1;
	game.menu = malloc(sizeof(t_data) * 3);
	int screen_width = screenWidth * 3;
	int screen_height = screenHeight * 3;
	game.menu[0].img = mlx_xpm_file_to_image(game.mlx,"./sprits/menu1.xpm" , &screen_width, &screen_height);
	game.menu[0].addr=  mlx_get_data_addr(game.menu[0].img, &game.menu[0].bits_per_pixel, &game.menu[0].line_length,
							&game.menu[0].endian);	
	game.menu[1].img = mlx_xpm_file_to_image(game.mlx,"./sprits/menu2.xpm" , &screen_width, &screen_height);
	game.menu[1].addr=  mlx_get_data_addr(game.menu[1].img, &game.menu[1].bits_per_pixel, &game.menu[1].line_length,
							&game.menu[1].endian);	
	game.menu[2].img = mlx_xpm_file_to_image(game.mlx,"./sprits/menu3.xpm" , &screen_width, &screen_height);
	game.menu[2].addr=  mlx_get_data_addr(game.menu[2].img, &game.menu[2].bits_per_pixel, &game.menu[2].line_length,
							&game.menu[2].endian);	
	mlx_hook(game.mlx_win, 2, (1L<<0), &handle_press,  &game);
	mlx_hook(game.mlx_win, 3, (1L<<1), &handle_release,  &game);
	mlx_loop_hook(game.mlx, &game_loop, &game);
	mlx_loop(game.mlx);			
}