
#include "cube.h"


int worldMap[mapWidth][mapHeight]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};


t_map	get_pos(void)
{
	t_map map;

	map.pos_x = 22.0;
	map.pos_y = 11.0;
	map.dir_x = -1.0;
	map.dir_y = 0.0;
	map.plane_x = 0.0;
	map.plane_y = 0.66;
	return (map);
}

void	get_sprites(t_game *game)
{
	game->img_1.img = mlx_xpm_file_to_image(game->mlx, "./sprits/eagle.xpm", &game->size_txt, &game->size_txt);
	game->img_1.addr = mlx_get_data_addr(game->img_1.img, &game->img_1.bits_per_pixel, &game->img_1.line_length,
							&game->img_1.endian);
	game->img_2.img = mlx_xpm_file_to_image(game->mlx, "./sprits/redbrick.xpm", &game->size_txt, &game->size_txt);
	game->img_2.addr = mlx_get_data_addr(game->img_2.img, &game->img_2.bits_per_pixel, &game->img_2.line_length,
							&game->img_2.endian);
	game->img_3.img = mlx_xpm_file_to_image(game->mlx, "./sprits/purplestone.xpm", &game->size_txt, &game->size_txt);
	game->img_3.addr = mlx_get_data_addr(game->img_3.img, &game->img_3.bits_per_pixel, &game->img_3.line_length,
							&game->img_3.endian);
	game->img_4.img = mlx_xpm_file_to_image(game->mlx, "./sprits/purplestone.xpm", &game->size_txt, &game->size_txt);
	game->img_4.addr = mlx_get_data_addr(game->img_4.img, &game->img_4.bits_per_pixel, &game->img_4.line_length,
							&game->img_4.endian);
	game->img_5.img = mlx_xpm_file_to_image(game->mlx, "./sprits/bluestone.xpm", &game->size_txt, &game->size_txt);
	game->img_5.addr = mlx_get_data_addr(game->img_5.img, &game->img_5.bits_per_pixel, &game->img_5.line_length,
							&game->img_5.endian);
	game->img_6.img = mlx_xpm_file_to_image(game->mlx, "./sprits/mossy.xpm", &game->size_txt, &game->size_txt);
	game->img_6.addr = mlx_get_data_addr(game->img_6.img, &game->img_6.bits_per_pixel, &game->img_6.line_length,
							&game->img_6.endian);
	game->img_7.img = mlx_xpm_file_to_image(game->mlx, "./sprits/wood.xpm", &game->size_txt, &game->size_txt);
	game->img_7.addr = mlx_get_data_addr(game->img_7.img, &game->img_7.bits_per_pixel, &game->img_7.line_length,
							&game->img_7.endian);
	game->img_8.img = mlx_xpm_file_to_image(game->mlx, "./sprits/colorstone.xpm", &game->size_txt, &game->size_txt);
	game->img_8.addr = mlx_get_data_addr(game->img_8.img, &game->img_8.bits_per_pixel, &game->img_8.line_length,
							&game->img_8.endian);
}



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

void	dda(t_ray *ray)
{
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
		if(worldMap[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
	if(ray->side == 0)
		ray->perpwalldist = (ray->sidedist_x - ray->deltadist_x);
	else          
		ray->perpwalldist = (ray->sidedist_y - ray->deltadist_y);
}

t_data	get_texture(t_ray  ray, t_game game)
{
	t_data	texture;

	if (worldMap[ray.map_x][ray.map_y] - 1 == 0)
		texture = game.img_1;
	else if (worldMap[ray.map_x][ray.map_y] - 1 == 1)
		texture = game.img_2;   
	else if (worldMap[ray.map_x][ray.map_y] - 1 == 2)
		texture = game.img_3;   
	else if (worldMap[ray.map_x][ray.map_y] - 1 == 3)
		texture = game.img_4;               
	else if (worldMap[ray.map_x][ray.map_y] - 1 == 4)
		texture = game.img_5;   
	else if (worldMap[ray.map_x][ray.map_y] - 1 == 5)
		texture = game.img_6;   
	else if (worldMap[ray.map_x][ray.map_y] - 1 == 6)
		texture = game.img_7; 
	else
		texture = game.img_8;    
	return (texture);
}



void	raycast(t_game game)
{
	t_ray	ray;
	int		w; 
	int		h;
	int		x;
	
	h = screenHeight;
	w = screenWidth;
	x = 0;
	while (x < w)
	{
		ray.camera_x = 2 * x / (double)w - 1;
		ray.raydir_x = game.map.dir_x + (game.map.plane_x * ray.camera_x);
		ray.raydir_y = game.map.dir_y + (game.map.plane_y * ray.camera_x);
		ray.map_x = (int)game.map.pos_x;
		ray.map_y = (int)game.map.pos_y;
		ray.hit = 0;
		if (ray.raydir_x == 0)
			ray.deltadist_x = 1e30;
		else
			ray.deltadist_x = fabs( 1 / ray.raydir_x);
		if (ray.raydir_y == 0)
			ray.deltadist_y = 1e30;
		else
			ray.deltadist_y = fabs( 1 / ray.raydir_y);
		side_dist_init(&ray, game.map);
		dda(&ray);
		ray.line_heigh = (int)(h / ray.perpwalldist);
		ray.pitch = 100;
		ray.draw_start = -ray.line_heigh / 2 + h / 2 + ray.pitch;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = ray.line_heigh / 2 + h / 2 + ray.pitch;
      	if(ray.draw_end >= h)
			ray.draw_end = h - 1;
		ray.texture = get_texture(ray, game);
		if (ray.side == 0)
			ray.wall_x = game.map.pos_y + ray.perpwalldist * ray.raydir_y;
		else
			ray.wall_x = game.map.pos_x + ray.perpwalldist * ray.raydir_x;
		ray.wall_x -= floor((ray.wall_x));
		ray.tex_x = (int)(ray.wall_x * (double)texWidth);
		if (ray.side == 0 && ray.raydir_x > 0)
			ray.tex_x = texWidth - ray.tex_x - 1;
		if (ray.side == 1 && ray.raydir_y < 0)
			ray.tex_x = texWidth - ray.tex_x - 1;
		ray.step = 1.0 * texHeight / ray.line_heigh;
		ray.tex_pos = (ray.draw_start - ray.pitch - h / 2 + ray.line_heigh / 2) * ray.step;
		int y;
		y = ray.draw_start;
		while (y < ray.draw_end)
		{
			ray.tex_y = (int)ray.tex_pos & (texHeight  - 1);
			ray.tex_pos += ray.step;
			ray.color = get_color(&ray.texture, ray.tex_x, ray.tex_y);
			if (ray.side == 1)
				ray.color = (ray.color >> 1) & 8355711;
			my_mlx_pixel_put(&game.img, x, y, ray.color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img.img, 0, 0);
}

int	handle_key(int key, t_game *game)
{
	if (key == KEY_RIGHT)
		game->map.pos_y = game->map.pos_y - 0.2;
	if (key == KEY_LEFT)
		game->map.pos_y = game->map.pos_y + 0.2;
	if (key == KEY_DOWN)
		game->map.pos_x = game->map.pos_x + 0.2;
	if (key == KEY_UP)
		game->map.pos_x = game->map.pos_x - 0.2;
	int	i;
	int	j;
	i = 0;
	j = 0;
	mlx_destroy_image(game->mlx, game->img.img);
	game->img.img = mlx_new_image(game->mlx, screenWidth, screenHeight);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length,
								&game->img.endian);
	while (i < screenWidth)
	{
		j = 0;
		while (j < screenWidth)
		{

			if (j < screenHeight / 4 * 3)
				my_mlx_pixel_put(&game->img, i, j, 0X00FF0000);
			else
				my_mlx_pixel_put(&game->img, i, j, 0X00FF00FF);
			j++;
		}
		i++;
	}
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
				my_mlx_pixel_put(&game.img, i, j, 0X00FF0000);
			else
				my_mlx_pixel_put(&game.img, i, j, 0X00FF00FF);
			j++;
		}
		i++;
	}
	game.map = pos;
	raycast(game);
	mlx_key_hook(game.mlx_win, handle_key, &game);
	mlx_loop(game.mlx);			
}

