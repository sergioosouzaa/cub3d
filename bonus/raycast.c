#include "cube.h"

// int	hsv_to_rgb(int hue, double saturation, double value)
// {
// 	double c;
// 	double x;
// 	double m;
// 	c = value * saturation;
// 	x = c * (1 - fabs(fmod((hue / 60.0), 2) - 1));
// 	m = value - c;
// 	if (hue >= 0 && hue < 60)
// 	{
// 		printf("%d %d %d \n",(int)(255 * (m + c)),  (int)(255 * (m + x)), ((int)((255 * m) )));
// 		return (((int)(255 * (m + c)) << 16) | ((int)(255 * (m + x)) << 8) | (int)(255 * m));
// 	}
// 	else if (60 <= hue && hue < 120)
// 		return (((int)(255 * (m + x)) << 16) | ((int)(255 * (m + c)) << 8) | (int)(255 * m));
// 	else if (120 <= hue && hue < 180)
// 		return (((int)(255 * m) << 16) | ((int)(255 * (m + c)) << 8) | (int)(255 * (m + x)));
// 	else if (180 <= hue && hue < 240)
// 		return (((int)(255 * (m + 0)) << 16) | ((int)(255 * (m + x)) << 8) | (int)(255 * (m + c)));
// 	else if (240 <= hue && hue < 300)
// 		return (((int)(255 * (m + x)) << 16) | ((int)(255 * m) << 8) | (int)(255 * (m + c)));
// 	else
// 		return (((int)(255 * (m + c)) << 16) | ((int)(255 * m) << 8) | (int)(255 * (m + x)));
// }

int sky_color(int x, int y)
{
	static int offset;

	(void)offset;
	(void)x;
	(void)y;
	// if (y > (int)(0.6 * screenHeight))
	// 	return (0x00000000);
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

	//return (255 / (int)(0.6 * screenHeight) * y);
	return (0x00000000);
}

int floor_color(int y, int f)
{
	int p = 70;
	int j = p / 7;
	int h[7] = {0xf94144, 0xf3722c, 0xf8961e, 0xf9844a, 0xf9c74f, 0x90be6d, 0x43aa8b};
	return (h[(f + (y % p) / j) % 7]);


	(void)f;
	//(void)y;

	// if (y % p < j)
	// 	return(h[f]);
	// if (y % p < j * 2)
	// 	f = f + 1;
	// if (y % p < j * 3)
	// 	f = f + 2;
	// if (y % p <  j * 4)
	// 	f = f + 3;
	// if (y % p <  j * 5)
	// 	f = f + 4;
	// if (y % p <  j * 6)
	// 	f = f + 5;
	// if (y % p <  j * 7)
	// 	f = f + 6;
	// f = f % 7;
	// return (h[f]);
	//return (0x00000000);		
}


void	raycast(t_game game)
{
	t_ray	ray;
	int		x;
	int		y;
	static int f;
	// static long long last_time;
	// long long time;
	
	x = 0;
	if (rand() % 2 == 0)
		f = (f + 1) % 360;
	// time = time_return(game.time);
	// printf("%lld \n", time - last_time);
	// last_time = time;
	// int j = 0;
	// while (j < screenHeight)
	// {
	// 	int p = 0;
	// 	while (p < screenWidth)
	// 	{
	// 		my_mlx_pixel_put(&game.img, p, j, sky_color(p, j));
	// 		p++;
	// 	}
	// 	j++;
	// }
	while (x < screenWidth)
	{
		ray_init(&ray, game, x);
		side_dist_init(&ray, game.map);
		dda(&ray);
		calc_texture(&ray, game);
		y = 0;
		while (y++ < ray. draw_start)
			my_mlx_pixel_put(&game.img, x, y, sky_color(x, y));
		y = ray.draw_start;
		while (y < ray.draw_end)
		{
			//my_mlx_pixel_put(&game.img, x, y_temp, 0xFFFFFFFF);
			//my_mlx_pixel_put(&game.img, x, y_temp, get_color(&game.sky, x, y_temp));
			// else if (y_temp < ray.draw_start)
			// 	my_mlx_pixel_put(&game.img, x, y_temp, sky_color(x, y));
			// int y_temp = (y + screenHeight) % screenHeight;
			// if (y_temp >= ray.draw_end)
			// 	my_mlx_pixel_put(&game.img, x, y_temp, game.ceiling_color);
			// else if (y >= ray.draw_end && y < ray.draw_end)
			// {
				ray.tex_y = (int)ray.tex_pos;
				if (ray.tex_y > texHeight  - 1)
					ray.tex_y = texHeight  - 1;
				ray.tex_pos += ray.step;
				ray.color = get_color(&ray.texture,  ray.tex_x, ray.tex_y);
				if (ray.side == 1)
					ray.color = (ray.color >> 1) & 8355711;
				my_mlx_pixel_put(&game.img, x, y, ray.color);
			// }
			y++;
		}
		y = ray.draw_end;
		while (y < screenHeight)
		{
			my_mlx_pixel_put(&game.img, x, y, floor_color(y, f));
			y++;
		}
		x++;
	}
	//mlx_put_image_to_window(game.mlx, game.mlx_win, game.sky.img, 0, 0);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img.img, 0, 0);
}


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

void	calc_texture(t_ray *ray, t_game game)
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
	ray->tex_x = (int)(ray->wall_x * (double)texWidth);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = texWidth - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = texWidth - ray->tex_x - 1;
	ray->step = 1.0 * texHeight / ray->line_heigh;
	ray->tex_pos = (ray->draw_start - ray->pitch - screenHeight / 2 + ray->line_heigh / 2) * ray->step;
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

	if (ray.side == 1)
	{
		if (ray.raydir_y > 0)
			texture = game.img_1;
		else
			texture = game.img_2;
	}
	else
	{
		if (ray.raydir_x > 0)
			texture = game.img_3;
		else
			texture = game.img_4;

	}
	return (texture);
}

