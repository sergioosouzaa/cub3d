#include "cube.h"

void floor_ceiling(t_game *game)
{
	int y;
	int	x;
	t_ray	ray;

	y = 0;
	while (y < screenHeight / 2)
	{
		ray.ray_dir_x0 = game->map.dir_x - game->map.plane_x;
		ray.ray_dir_y0 = game->map.dir_y - game->map.plane_y;
		ray.ray_dir_x1 = game->map.dir_x + game->map.plane_x;
		ray.ray_dir_y1 = game->map.dir_y + game->map.plane_y;
		ray.pos_p = y - screenHeight / 2;
		ray.pos_camera = 0.7 * screenHeight;
		ray.row_dist = 1.0 * ray.pos_camera / ray.pos_p;
		ray.floor_step_x = ray.row_dist * (ray.ray_dir_x1 - ray.ray_dir_x0) / screenWidth;
		ray.floor_step_y = ray.row_dist * (ray.ray_dir_y1 - ray.ray_dir_y0) / screenWidth;
		ray.floor_x = game->map.pos_x + ray.row_dist * ray.ray_dir_x0;
		ray.floor_y = game->map.pos_y + ray.row_dist * ray.ray_dir_y0;
		ray.texture  = game->img_1;
		x = 0;
		while (x < screenWidth)
		{
			ray.cell_x = (int)ray.floor_x;
			ray.cell_y = (int)ray.floor_y;
			ray.t_x = (int)(texWidth * (ray.floor_x - ray.cell_x))  & (texWidth - 1);
			ray.t_y = (int)(texHeight * (ray.floor_y - ray.cell_y)) & (texHeight - 1);
			ray.floor_x += ray.floor_step_x;
			ray.floor_y += ray.floor_step_y;
			ray.color = get_color(&ray.texture,  ray.t_x, ray.t_y);
			my_mlx_pixel_put(&game->img, x, y, ray.color);
			ray.color = get_color(&game->img_2,  ray.t_x, ray.t_y);
			my_mlx_pixel_put(&game->img, x, screenHeight - y - 1, ray.color);
			x++;
		}
		y++;
	}

}

void	raycast(t_game game)
{
	t_ray	ray;
	int		x;
	int		y;
	
	x = 0;
	floor_ceiling(&game);
	while (x < screenWidth)
	{
		ray_init(&ray, game, x);
		side_dist_init(&ray, game.map);
		dda(&ray);
		calc_texture(&ray, game);
		y = 0;
		while (y < screenHeight)
		{
			if (y >= ray.draw_start && y < ray.draw_end)
			{
				ray.tex_y = (int)ray.tex_pos;
				if (ray.tex_y > texHeight  - 1)
					ray.tex_y = texHeight  - 1;
				ray.tex_pos += ray.step;
				ray.color = get_color(&ray.texture,  ray.tex_x, ray.tex_y);
				if (ray.side == 1)
					ray.color = (ray.color >> 1) & 8355711;
				my_mlx_pixel_put(&game.img, x, y, ray.color);
			}
			y++;
		}
		x++;
	}
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
		if(game.world_map[ray->map_x][ray->map_y] > 0)
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

