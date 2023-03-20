/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:38 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/20 11:46:20 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	color_rgb(char *str, t_game *game, int var)
{
	char	**colors;
	int		rgb[3];

	rgb[0] = 0;
	rgb[1] = 0;
	rgb[2] = 0;
	(void)game;
	(void)var;
	colors = ft_split(str, ',');
	if (colors[0])
		rgb[0] = ft_atoi(colors[0]);
	if (colors[1])
		rgb[1] = ft_atoi(colors[1]);
	if (colors[2])
		rgb[2] = ft_atoi(colors[2]);
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
		m_erro("Not valid color RGB.\n");
	else if (rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0)
		m_erro("Not valid color RGB.\n");
	create_rgb(rgb, game, var);
}

void	create_rgb(int *rgb, t_game *game, int var)
{
	int	color;

	color = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	if (var == 1)
	{
		game->mlx = mlx_init();
		game->mlx_win = mlx_new_window(game->mlx, SCREENWIDTH,
				SCREENHEIGHT, "cub3d");
		game->size_txt = TEXWIDTH;
		game->img.img = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
		game->img.addr = mlx_get_data_addr(game->img.img, \
		&game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
		game->ceiling_color = color;
	}
	else if (var == 0)
		game->floor_color = color;
	game->key = init_keys();
}

unsigned int	get_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

t_data	get_texture(t_ray ray, t_game game)
{
	t_data	texture;

	if (ray.side == 1)
	{
		if (ray.raydir_y > 0)
			texture = game.img_north;
		else
			texture = game.img_south;
	}
	else
	{
		if (ray.raydir_x > 0)
			texture = game.img_west;
		else
			texture = game.img_east;
	}
	return (texture);
}

void	calc_texture(t_ray *ray, t_game game)
{
	ray->line_heigh = (int)(SCREENHEIGHT / ray->perpwalldist);
	ray->draw_start = -ray->line_heigh / 2 + SCREENHEIGHT / 2 + ray->pitch;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_heigh / 2 + SCREENHEIGHT / 2 + ray->pitch;
	if (ray->draw_end >= SCREENHEIGHT)
		ray->draw_end = SCREENHEIGHT - 1;
	ray->texture = get_texture(*ray, game);
	if (ray->side == 0)
		ray->wall_x = game.map.pos_y + ray->perpwalldist * ray->raydir_y;
	else
		ray->wall_x = game.map.pos_x + ray->perpwalldist * ray->raydir_x;
	ray->wall_x -= floor((ray->wall_x));
	ray->tex_x = (int)(ray->wall_x * (double)TEXWIDTH);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = TEXWIDTH - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = TEXWIDTH - ray->tex_x - 1;
	ray->step = 1.0 * TEXHEIGHT / ray->line_heigh;
	ray->tex_pos = (ray->draw_start - ray->pitch - SCREENHEIGHT / 2
			+ ray->line_heigh / 2) * ray->step;
}
