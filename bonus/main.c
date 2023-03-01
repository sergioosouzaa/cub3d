
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
	if (game->key.rotate_l == 0 && game->key.rotate_r == 0)
		game->sprites->texture = &game->sprites->texture_1;
	return (0);
}

int	handle_key(t_game *game)
{
	double	aux;

	double speed = 0.08;
	double scale = sqrt(game->map.dir_x * game->map.dir_x + game->map.dir_y * game->map.dir_x);
	double	dir_norm_x = game->map.dir_x  / scale;
	double	dir_norm_y = game->map.dir_y  / scale;
	double invers_det = 1.0 / (game->map.plane_x * game->map.dir_y - game->map.plane_y * game->map.dir_x);
	double	new_x =  invers_det * (game->map.dir_y * dir_norm_x - game->map.dir_x * dir_norm_y);
	double	new_y =  invers_det * (-game->map.plane_y * dir_norm_x - game->map.plane_x * dir_norm_x);


	if (game->key.down && game->key.down != game->key.up)
	{
		if (worldMap[(int)(game->map.pos_x - game->map.dir_x * 25 * speed) % 24][(int)(game->map.pos_y - game->map.dir_y * 25 * speed) % 24] < 1)
		{
			game->map.pos_x -= game->map.dir_x * speed;
			game->map.pos_y -= game->map.dir_y * speed;
			game->sprites->pos_x = game->map.pos_x + (2.5 * new_x);
			game->sprites->pos_y = game->map.pos_y + (2.5 * new_y);
		}
	}
	if (game->key.up && game->key.down != game->key.up)
	{	
		if (worldMap[(int)(game->map.pos_x + game->map.dir_x * 25 * speed) % 24][(int)(game->map.pos_y + game->map.dir_y * 25 * speed) % 24] < 1)
		{	
			game->map.pos_x += game->map.dir_x * speed;
			game->map.pos_y += game->map.dir_y * speed;
			game->sprites->pos_x = game->map.pos_x + (2.5 * new_x);
			game->sprites->pos_y = game->map.pos_y+ (2.5 * new_y);
		}
	}
	if (game->key.rotate_l && game->key.rotate_l != game->key.rotate_r)
	{
		aux = game->map.dir_x;
	  	game->map.dir_x = game->map.dir_x * cos(-rot) - game->map.dir_y * sin(-rot);
	  	game->map.dir_y = aux * sin(-rot) + game->map.dir_y  * cos(-rot);
	  	aux = game->map.plane_x;
	  	game->map.plane_x = game->map.plane_x * cos(-rot) - game->map.plane_y * sin(-rot);
	  	game->map.plane_y = aux * sin(-rot) + game->map.plane_y * cos(-rot);
		//game->sprites->texture = &game->sprites->texture_3;
		game->sprites->pos_x = game->map.pos_x + (2.5 * new_x);
		game->sprites->pos_y = game->map.pos_y + (2.5 * new_y);
	}
	if (game->key.rotate_r && game->key.rotate_l != game->key.rotate_r)
	{
		aux = game->map.dir_x;
	  	game->map.dir_x = game->map.dir_x * cos(rot) - game->map.dir_y * sin(rot);
	  	game->map.dir_y = aux * sin(rot) + game->map.dir_y  * cos(rot);
	  	aux = game->map.plane_x;
	  	game->map.plane_x = game->map.plane_x * cos(rot) - game->map.plane_y * sin(rot);
	  	game->map.plane_y = aux * sin(rot) + game->map.plane_y * cos(rot);
		//game->sprites->texture = &game->sprites->texture_2;
		
		game->sprites->pos_x = game->map.pos_x + (2.5 * new_x);
		game->sprites->pos_y = game->map.pos_y + (2.5 * new_y);
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

long long	get_first_time(void)
{
	struct timeval	first;

	gettimeofday(&first, NULL);
	return ((first.tv_sec) * 1000 + (first.tv_usec) * 0.001);
}

long long	time_return(long long first_time)
{
	struct timeval	first;
	long long		actual_time;

	gettimeofday(&first, NULL);
	actual_time = (first.tv_sec) * 1000 + (first.tv_usec) * 0.001;
	return (actual_time - first_time);
}

int main(void)
{
	t_map	pos;
	t_game	game;
	// struct timeval current_time;
  	// gettimeofday(&current_time, NULL);
	// long long time = get_first_time();

   	time_t t;
   	srand((unsigned) time(&t));  
	pos = get_pos();
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, screenWidth, screenHeight, "window");
	game.size_txt = texWidth;
	get_sprites(&game);
	game.img.img = mlx_new_image(game.mlx, screenWidth, screenHeight);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length,
								&game.img.endian);
	game.map = pos;
	game.sprites = malloc(sizeof(t_sprite));
	game.sprites->pos_x = 6;
	game.sprites->pos_y = 0;
	game.sprites->texture_1.img = mlx_xpm_file_to_image(game.mlx, "./sprits/mariogay.xpm", &game.size_txt, &game.size_txt);
	game.sprites->texture_1.addr=  mlx_get_data_addr(game.sprites->texture_1.img, &game.sprites->texture_1.bits_per_pixel, &game.sprites->texture_1.line_length,
							&game.sprites->texture_1.endian);
	game.sprites->texture_2.img = mlx_xpm_file_to_image(game.mlx, "./sprits/mariogay.xpm", &game.size_txt, &game.size_txt);
	game.sprites->texture_2.addr=  mlx_get_data_addr(game.sprites->texture_2.img, &game.sprites->texture_2.bits_per_pixel, &game.sprites->texture_2.line_length,
							&game.sprites->texture_2.endian);
	game.sprites->texture_3.img = mlx_xpm_file_to_image(game.mlx, "./sprits/mariogay.xpm", &game.size_txt, &game.size_txt);
	game.sprites->texture_3.addr=  mlx_get_data_addr(game.sprites->texture_3.img, &game.sprites->texture_3.bits_per_pixel, &game.sprites->texture_3.line_length,
							&game.sprites->texture_3.endian);	
	game.sprites->texture = &game.sprites->texture_1;		
	game.ceiling_color =  0x000000FF;
	game.floor_color =  0x00F00FFF;
	game.key = init_keys();
	// game.time = time;
	raycast(game);
	mlx_hook(game.mlx_win, 2, (1L<<0), &handle_press,  &game);
	mlx_hook(game.mlx_win, 3, (1L<<1), &handle_release,  &game);
	mlx_loop_hook(game.mlx, &game_loop, &game);
	mlx_loop(game.mlx);			
}