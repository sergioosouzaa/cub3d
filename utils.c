/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:47 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/14 11:17:49 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	game_loop(t_game *game)
{
	handle_key(game);
	raycast(*game);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_floor(t_data *img, int floor_color, int ceiling_color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < SCREENWIDTH)
	{
		j = 0;
		while (j < SCREENHEIGHT)
		{
			if (j < (SCREENHEIGHT / 4) * 3)
				my_mlx_pixel_put(img, i, j, floor_color);
			else
				my_mlx_pixel_put(img, i, j, ceiling_color);
			j++;
		}
		i++;
	}
}

void	get_sprites(t_map *map, t_game *game)
{
	game->img_north.img = mlx_xpm_file_to_image(game->mlx, map->north,
			&game->size_txt, &game->size_txt);
	game->img_north.addr = mlx_get_data_addr(game->img_north.img,
			&game->img_north.bits_per_pixel, &game->img_north.line_length,
			&game->img_north.endian);
	game->img_south.img = mlx_xpm_file_to_image(game->mlx, map->south,
			&game->size_txt, &game->size_txt);
	game->img_south.addr = mlx_get_data_addr(game->img_south.img,
			&game->img_south.bits_per_pixel, &game->img_south.line_length,
			&game->img_south.endian);
	game->img_west.img = mlx_xpm_file_to_image(game->mlx, map->west,
			&game->size_txt, &game->size_txt);
	game->img_west.addr = mlx_get_data_addr(game->img_west.img,
			&game->img_west.bits_per_pixel, &game->img_west.line_length,
			&game->img_west.endian);
	game->img_east.img = mlx_xpm_file_to_image(game->mlx, map->east,
			&game->size_txt, &game->size_txt);
	game->img_east.addr = mlx_get_data_addr(game->img_east.img,
			&game->img_east.bits_per_pixel, &game->img_east.line_length,
			&game->img_east.endian);
}

t_keys	init_keys(void)
{
	t_keys	key;

	key.up = 0;
	key.down = 0;
	key.esc = 0;
	key.rotate_r = 0;
	key.rotate_l = 0;
	key.right = 0;
	key.left = 0;
	return (key);
}
