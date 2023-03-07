#include "cube.h"


 /// JUNTAR FUNCÇOES ////////


int sky_color(int x, int y)
{
	static int offset;

	(void)offset;
	(void)x;
	(void)y;
	int i = rand() % 2000;
	int	j = rand() % 7;
	if (i  == 10)
	{
		if (j == 0)
			return (0x9400D3);
		if (j == 1)
			return (0x4B0082);
		if (j == 2)
			return (0x0000FF);
		if (j == 3)
			return (0x00FF00);
		if (j == 4)
			return (0xFFFF00);
		if (j == 5)
			return (0xFF7F00);
		if (j == 6)
			return (0xFF0000);
	}
	return (0x00000000);
}

int floor_color(int y, int x, int f)
{
	int j;
	int h[7] = {0xf94144, 0xf3722c, 0xf8961e, 0xf9844a, 0xf9c74f, 0x90be6d, 0x43aa8b};
	(void)y;
	j = ((y / 30) + (x / 30));
	return (h[(f + j) % 7]);
}


/* Arquivo sprites  */
void	sort_sprites(int *sprite_order, int *sprite_dist, int sprite_num)
{
	int i;

	i = 0;
	while (i < sprite_num - 1)
	{
		if (sprite_dist[i] < sprite_dist[i + 1])
		{
			int aux;
			aux = sprite_order[i + 1];
			sprite_order[i + 1] = sprite_order[i];
			sprite_order[i] = aux;
			aux = sprite_dist[i + 1];
			sprite_dist[i + 1] = sprite_dist[i];
			sprite_dist[i] = aux;
			i = 0;
		}
		else
			i++;
	}
}

/* arquivo sprites  */
void 	draw_sprites(int *perpedist, t_game *game)
{
	int	sprite_order[game->sprite_num];
	int	sprite_dist[game->sprite_num];
	int i;

	i  = 0;
	while(i < game->sprite_num)
	{
		sprite_order[i] = i;
		sprite_dist[i] = ((game->map.pos_x - game->sprites[i].pos_x) * (game->map.pos_x - game->sprites[i].pos_x)) + ((game->map.pos_y - game->sprites[i].pos_y) * (game->map.pos_y - game->sprites[i].pos_y));
		i++;
	}
	sort_sprites(sprite_order, sprite_dist, game->sprite_num);
	i = 0;
	while (i < game->sprite_num)
	{
		double sprite_x = game->sprites[sprite_order[i]].pos_x - game->map.pos_x;
		double sprite_y = game->sprites[sprite_order[i]].pos_y - game->map.pos_y;
		double invers_det = 1.0 / (game->map.plane_x * game->map.dir_y - game->map.plane_y * game->map.dir_x);
		double	new_x =  invers_det * (game->map.dir_y * sprite_x - game->map.dir_x * sprite_y);
		double	new_y =  invers_det * (-game->map.plane_y * sprite_x - game->map.plane_x * sprite_y);

		int sprite_pos_x = (int)((screenWidth / 2) * (1 + new_x / new_y));
		int	udiv = 1;
		int vdiv = 1;
		double vmove = 0;
		int v_move_screen =  (int)(vmove / new_y);
		int sprite_height = abs((int)(screenHeight / new_y)) / vdiv;
		int draw_start_y = -sprite_height / 2 + screenHeight / 2 + v_move_screen;
		if (draw_start_y < 0)
			draw_start_y = 0;
		int draw_end_y = sprite_height / 2 + screenHeight / 2 + v_move_screen;
		if (draw_start_y >= screenHeight)
			draw_start_y = screenHeight - 1;

		int	sprite_width = abs((int)(screenHeight / new_y)) / udiv;
		int	draw_start_x = -sprite_width / 2 + sprite_pos_x;
		if (draw_start_x < 0)
			draw_start_x = 0;
		int draw_end_x = sprite_width / 2 + sprite_pos_x;
		if (draw_end_x > screenWidth - 1)
			draw_end_x = screenWidth - 1;
		int stripe = draw_start_x;
		while (stripe < draw_end_x)
		{
			int tex_x =  (int)(256 * (stripe - (-sprite_width / 2 + sprite_pos_x)) * (texWidth / 4) / sprite_width) / 256;
			if (new_y > 0 && new_y < perpedist[stripe] && stripe > 0 && stripe < screenWidth)
			{
				int p;
				p = draw_start_y;
				while (p < draw_end_y)
				{
					int d = (p - v_move_screen) * 256 - screenHeight * 128 + sprite_height * 128;
					int tex_y = ((d * texHeight / 4) / sprite_height) / 256;
					int color = get_color(&game->img_2, tex_x, tex_y);
					if (((color >> 24) & 0xFF) != 0xFF)
						my_mlx_pixel_put(&game->img, stripe, p, color);
					
					p++;
				}
			}
			stripe++;
		}
		i++;
	}
}



/* função sprite */
void draw_square(int x_screen, int y_screen, int color, int title_size, t_game game)
{
	int i;
	int j;

	i = 0;
	while (i < title_size)
	{
		j = 0;
		while (j < title_size)
		{
			my_mlx_pixel_put(&game.img, x_screen + i, y_screen + j, color);
			j++;
		}
		i++;
	}
}


/* função minimap */

void	draw_minimap(t_game game, int *pos_x, int *pos_y)
{
	int	max_side;
	int	side;
	int	title_size;
	int	y_screen;
	int x_screen;
	int color;

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
	title_size = side / max_side;
	int y;
	int x;
	x = 0;
	x_screen = screenWidth - (mapWidth * title_size);
	while (x < mapWidth)
	{
		y = 0;
		y_screen = screenHeight - (mapHeight * title_size);
		while (y < mapHeight)
		{
			if (worldMap[x][y] >= 1)
			{
				color = 0x474564;
			}
			else if (x == (int)game.map.pos_x && y == (int)game.map.pos_y)
			{
				*pos_x = x_screen;
				*pos_y = y_screen;
				color = 0x00CACACA;
			}
			else
			{
				color = 0x00CACACA;
			}
			draw_square(x_screen, y_screen, color, title_size, game);
			// else
			// {
			// 	draw_square(x_screen, y_screen, color, title_size, game);
			// }
			y_screen += title_size;
			y++;
		}
		x_screen += title_size;
		x++;
	}
}

/*   Ok */
void	put_char_to_window(t_game *game, int *perp_dist)
{
	if (perp_dist[screenWidth / 2] >= 1)
	{
		if (game->key.rotate_l == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->my_char.txt1.img, screenWidth/2, screenHeight - 40);
		else if (game->key.rotate_r == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->my_char.txt2.img, screenWidth/2, screenHeight - 40);
		else
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->my_char.txt3.img, screenWidth/2, screenHeight - 40);
	}
}


/*antes de rodar o raycast fazer a função de checar minimapa que muda o f da porta dcriar um f e por num struct da porta*/
void	raycast(t_game game)
{
	t_ray	ray;
	int		x;
	int		y;
	static int f;
	int		perpedist[screenWidth];
	static long long last_time;
	// long long time;
	
	x = 0;
	// int	max_end;
	// max_end = 0;
	// if (rand() % 2 == 0)
	my_mlx_pixel_put(&game.img, 0, 0,0x00FF0000);
	if (get_first_time() - last_time > 100)
	{
		f = (f + 1) % 7;
		last_time = get_first_time();
	}
	while (x < screenWidth)
	{

		ray_init(&ray, game, x);
		side_dist_init(&ray, game.map);
		dda(&ray, game, f);
		calc_texture(&ray, game, f);
		y = 0;
		while (y++ < ray. draw_start)
			my_mlx_pixel_put(&game.img, x, y, sky_color(x, y));
		y = ray.draw_start;
		while (y < ray.draw_end)
		{
			ray.tex_y = (int)ray.tex_pos;
			if (ray.tex_y > texHeight  - 1)
				ray.tex_y = texHeight  - 1;
			ray.tex_pos += ray.step;
			ray.color = get_color(&ray.texture,  ray.tex_x, ray.tex_y);
			if (ray.side == 1)
				ray.color = (ray.color >> 1) & 8355711;
			my_mlx_pixel_put(&game.img, x, y, ray.color);
			y++;
		}
		y = ray.draw_end;
		while (y < screenHeight)
		{
			my_mlx_pixel_put(&game.img, x, y, floor_color(y, x, f));
			y++;
		}
		perpedist[x] = ray.perpwalldist;
		x++;
	}
	game.sprite_num = 1;
	// draw_sprites(perpedist, &game);
	int x_mini;
	int y_mini;

	x_mini = 2000;
	y_mini = 2000;
	draw_minimap(game, &x_mini, &y_mini);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img.img, 0, 0);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.minimap.img, x_mini, y_mini);
	//mlx_put_image_to_window(game.mlx, game.mlx_win, game.sprites->texture[game.sprites->sprite].img, screenWidth/2, screenHeight - 64);
	put_char_to_window(&game, perpedist);
	
}




/*     ok  */
void	ray_init(t_ray *ray, t_game game, int x)
{
	ray->camera_x = 2 * x / (double)(screenWidth) - 1;
	ray->raydir_x = game.map.dir_x + (game.map.plane_x * ray->camera_x);
	ray->raydir_y = game.map.dir_y + (game.map.plane_y * ray->camera_x);
	ray->map_x = (int)game.map.pos_x;
	ray->map_y = (int)game.map.pos_y;
	ray->hit = 0;
	if (ray->raydir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = fabs( 1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = fabs( 1 / ray->raydir_y);
	ray->pitch = 100;
}




/*    ok  */
void	calc_texture(t_ray *ray, t_game game, int f)
{
	ray->line_heigh = (int)(screenHeight / ray->perpwalldist);
	ray->draw_start = -ray->line_heigh / 2 + screenHeight / 2 + ray->pitch;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_heigh / 2 + screenHeight / 2 + ray->pitch;
	if(ray->draw_end >= screenHeight)
		ray->draw_end = screenHeight - 1;
	ray->texture = get_texture(*ray, game);
	if (ray->side == 0)
		ray->wall_x = game.map.pos_y + ray->perpwalldist * ray->raydir_y;
	else
		ray->wall_x = game.map.pos_x + ray->perpwalldist * ray->raydir_x;
	ray->wall_x -= floor((ray->wall_x));
	if (worldMap[ray->map_x][ray->map_y] == 9)
		ray->tex_x = (int)((ray->wall_x  + (f * (1.0 / 7))) * (double)texWidth);
	else
		ray->tex_x = (int)(ray->wall_x * (double)texWidth);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = texWidth - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = texWidth - ray->tex_x - 1;
	ray->step = 1.0 * texHeight / ray->line_heigh;
	ray->tex_pos = (ray->draw_start - ray->pitch - screenHeight / 2 + ray->line_heigh / 2) * ray->step;
}


/*  Ok */
void	side_dist_init(t_ray *ray, t_map map)
{
	if(ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (map.pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - map.pos_x) * ray->deltadist_x;
	}
	if(ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (map.pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - map.pos_y) * ray->deltadist_y;
	}
}

/* Ok */
void 	door_dda(t_ray *ray, t_game game, int f)
{
	double wall;

	ray->door = 1;
	if (ray->side == 0)
		wall = game.map.pos_y + (ray->sidedist_x - ray->deltadist_x) * ray->raydir_y;
	else
		wall = game.map.pos_x + (ray->sidedist_x - ray->deltadist_x)  * ray->raydir_x;
	wall -= floor((wall));
	if (wall < f * 0.1)
		ray->hit = 0;
	else
		ray->hit = 1;
}


/*  OK  */
void	dda(t_ray *ray, t_game game, int f)
{
	ray->door = 0;
	while (ray->hit == 0)
	{
		if(ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (worldMap[ray->map_x][ray->map_y] == 9)
			door_dda(ray, game, f);
		else if(worldMap[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
	if(ray->side == 0)
		ray->perpwalldist = (ray->sidedist_x - ray->deltadist_x);
	else          
		ray->perpwalldist = (ray->sidedist_y - ray->deltadist_y);
}





