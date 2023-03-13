/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:31 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/13 18:36:31 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	raycast(t_game game)
{
	t_ray	ray;
	int		x;
	int		y;

	x = 0;
	while (x < SCREENWIDTH)
	{
		ray_init(&ray, game, x);
		side_dist_init(&ray, game.map);
		dda(&ray, game);
		calc_texture(&ray, game);
		y = 0;
		while (y < SCREENHEIGHT)
		{
			functions_pixel(&ray, game, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img.img, 0, 0);
}

void	functions_pixel(t_ray *ray, t_game game, int x, int y)
{
	if (y < ray->draw_start)
		my_mlx_pixel_put(&game.img, x, y, game.floor_color);
	else if (y >= ray->draw_end)
		my_mlx_pixel_put(&game.img, x, y, game.ceiling_color);
	else
	{
		ray->tex_y = (int)ray->tex_pos;
		if (ray->tex_y > TEXHEIGHT - 1)
			ray->tex_y = TEXHEIGHT - 1;
		ray->tex_pos += ray->step;
		ray->color = get_color(&ray->texture, ray->tex_x, ray->tex_y);
		if (ray->side == 1)
			ray->color = (ray->color >> 1) & 8355711;
		my_mlx_pixel_put(&game.img, x, y, ray->color);
	}
}

void	ray_init(t_ray *ray, t_game game, int x)
{
	ray->camera_x = 2 * x / (double)(SCREENWIDTH) - 1;
	ray->raydir_x = game.map.dir_x + (game.map.plane_x * ray->camera_x);
	ray->raydir_y = game.map.dir_y + (game.map.plane_y * ray->camera_x);
	ray->map_x = (int)game.map.pos_x;
	ray->map_y = (int)game.map.pos_y;
	ray->hit = 0;
	if (ray->raydir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = fabs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = fabs(1 / ray->raydir_y);
	ray->pitch = 100;
}

void	side_dist_init(t_ray *ray, t_map map)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (map.pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - map.pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
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

void	dda(t_ray *ray, t_game game)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
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
		if (game.world_map[ray->map_x][ray->map_y] > '0')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->perpwalldist = (ray->sidedist_y - ray->deltadist_y);
}
