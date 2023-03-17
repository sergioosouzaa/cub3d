/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:55:30 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/16 19:05:09 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/* função sprite */
void	draw_square(int x_screen, int y_screen, int color, t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (i < get_title_size(&game.map))
	{
		j = 0;
		while (j < get_title_size(&game.map))
		{
			my_mlx_pixel_put(&game.img, (x_screen + i), screenHeight \
			- (y_screen + j), color);
			j++;
		}
		i++;
	}
}

/* função minimap */

int	get_title_size(t_map *map)
{
	int	max_side;
	int	side;
	int	title_size;

	if (map->lines > map->columns)
	{
		max_side = map->lines;
		side = 0.3 * screenHeight;
	}
	else
	{
		max_side = map->columns;
		side = 0.3 * screenWidth;
	}
	title_size = side / max_side;
	return (title_size);
}

void	put_pic(t_game game, t_data img, int x, int y)
{
	mlx_put_image_to_window(game.mlx, game.mlx_win, img.img, x, y);
}

void	put_pic_minimap(t_game game)
{
	size_t	y;
	size_t	x;
	size_t	y_screen;
	size_t	x_screen;

	x = -1;
	x_screen = screenWidth - (game.map.lines * get_title_size(&game.map));
	while (++x < game.map.lines)
	{
		y = -1;
		y_screen = screenHeight - (game.map.columns * get_title_size(&game.map));
		while (++y < game.map.columns)
		{
			if (x == (size_t)game.sprites[1].pos_x && y == \
			(size_t)game.sprites[1].pos_y)
				put_pic(game, game.sprites[1].texture_3, x_screen, screenHeight \
				- y_screen - get_title_size(&game.map) * 1.5);
			else if (x == (size_t)game.sprites[0].pos_x && y == \
			(size_t)game.sprites[0].pos_y)
				put_pic(game, game.minimap, x_screen, screenHeight - y_screen \
				- get_title_size(&game.map) * 1.5);
			y_screen += get_title_size(&game.map);
		}
		x_screen += get_title_size(&game.map);
	}
}

void	draw_minimap(t_game game)
{
	int	y_screen;
	int	x_screen;
	int	color;
	size_t	y;
	size_t	x;

	x = 0;
	x_screen = screenWidth - (game.map.lines * get_title_size(&game.map));
	while (x < game.map.lines)
	{
		y = 0;
		y_screen = screenHeight - (game.map.columns * get_title_size(&game.map));
		while (y < game.map.columns)
		{
			color = 0x00CACACA;
			if (game.world_map[x][y] >= '1' || (game.world_map[x][y] == '9' && \
			game.doors[0].mode != '4'))
				color = 0x474564;
			draw_square(x_screen, y_screen, color, game);
			y_screen += get_title_size(&game.map);
			y++;
		}
		x_screen += get_title_size(&game.map);
		x++;
	}
}
