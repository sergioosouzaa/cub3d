/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:18:21 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/19 19:06:24 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	organize(t_game *game, int *sprite_order, int *sprite_distance)
{
	int	i;

	i = 0;
	while (i < game->sprite_num)
	{
		sprite_order[i] = i;
		sprite_distance[i] = (pow((game->map.pos_x - game->sprites[i].pos_x), \
		2) + pow((game->map.pos_y - game->sprites[i].pos_y), 2));
		i++;
	}
	sort_sprites(sprite_order, sprite_distance, game->sprite_num);
	sort_order(sprite_order, game->sprite_num);
}

void	calc_end_start(t_draw *sprites, int *sprite_order, t_game *game, int i)
{
	if (sprites->draw_start_y < 0)
		sprites->draw_start_y = 0;
	sprites->draw_end_y = sprites->sprite_height / 2 + SCREENHEIGHT / 2 + \
	sprites->v_move;
	if (sprites->draw_end_y >= SCREENHEIGHT)
		sprites->draw_end_y = SCREENHEIGHT - 1;
	sprites->sprite_width = abs((int)(SCREENHEIGHT / (sprites->transform_y))) \
	/ game->sprites[sprite_order[i]].u_div;
	sprites->draw_start_x = -sprites->sprite_width / 2 + \
	sprites->sprite_screen_x;
	if (sprites->draw_start_x < 0)
		sprites->draw_start_x = 0;
	sprites->draw_end_x = sprites->sprite_width / 2 + sprites->sprite_screen_x;
	if (sprites->draw_end_x > SCREENWIDTH)
		sprites->draw_end_x = SCREENWIDTH;
}

void	init_sprites(t_game *game, int *sprite_order, int i, t_draw *sprites)
{
	sprites->sprite_x = game->sprites[sprite_order[i]].pos_x - game->map.pos_x;
	sprites->sprite_y = game->sprites[sprite_order[i]].pos_y - game->map.pos_y;
	sprites->inv_det = 1.0 / (game->map.plane_x * game->map.dir_y - \
	game->map.dir_x * game->map.plane_y);
	sprites->transform_x = sprites->inv_det * (game->map.dir_y * \
	sprites->sprite_x - game->map.dir_x * sprites->sprite_y);
	sprites->transform_y = sprites->inv_det * (-game->map.plane_y * \
	sprites->sprite_x + game->map.plane_x * sprites->sprite_y);
	sprites->sprite_screen_x = (int)((SCREENHEIGHT / 2) * (1 + \
	sprites->transform_x / sprites->transform_y));
	sprites->v_move = (int)(VMOVE / sprites->transform_y);
	sprites->sprite_height = abs((int)(SCREENHEIGHT / (sprites->transform_y))) \
	/ game->sprites[sprite_order[i]].v_div;
	sprites->draw_start_y = -sprites->sprite_height / 2 + SCREENHEIGHT / 2 + \
	sprites->v_move;
	calc_end_start(sprites, sprite_order, game, i);
}

void	put_sprites(t_draw *sprites, t_game *game, int i, int *z_buffer)
{
	int		stripe;
	int		y;

	stripe = sprites->draw_start_x;
	while (stripe < sprites->draw_end_x)
	{
		sprites->tex_x = (int)(256 * (stripe - (-sprites->sprite_width / 2 + \
		sprites->sprite_screen_x)) * TEXWIDTH / sprites->sprite_width) / 256;
		if (sprites->transform_y > 0 && sprites->transform_y < z_buffer[stripe])
		{
			y = sprites->draw_start_y - 1;
			while (++y < sprites->draw_end_y)
			{
				sprites->d = (y - sprites->v_move) * 256 - SCREENHEIGHT * 128 \
				+ sprites->sprite_height * 128;
				sprites->tex_y = ((sprites->d * TEXHEIGHT) / \
				sprites->sprite_height) / 256;
				sprites->color = get_color(game->sprites[i].texture, \
				sprites->tex_x, sprites->tex_y);
				if (((sprites->color >> 24) & 0xFF) != 0xFF)
					my_mlx_pixel_put(&game->img, stripe, y, sprites->color);
			}
		}
		stripe++;
	}
}

void	draw_sprites(int *z_buffer, t_game *game)
{
	int		*sprite_order;
	int		*sprite_distance;
	t_draw	sprites;
	int		i;

	i = 0;
	sprite_order = malloc(sizeof(int) * game->sprite_num);
	sprite_distance = malloc(sizeof(int) * game->sprite_num);
	organize(game, sprite_order, sprite_distance);
	while (i < game->sprite_num)
	{
		init_sprites(game, sprite_order, i, &sprites);
		put_sprites(&sprites, game, sprite_order[i], z_buffer);
		i++;
	}
	free (sprite_order);
	free (sprite_distance);
}
