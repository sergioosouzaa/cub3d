/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:25:31 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/13 18:12:49 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	create_sprites(t_game *game)
{
	game->sprites = malloc(sizeof(t_sprite) * 3);
	game->sprites[2].pos_x = 0;
	game->sprites[2].pos_y = 0;
	game->sprites[2].u_div = 1;
	game->sprites[2].v_div = 1;
	game->sprites[1].pos_x = 5;
	game->sprites[1].pos_y = 8;
	game->sprites[1].u_div = 8;
	game->sprites[1].v_div = 8;
	game->sprites[1].hp = 3;
	game->sprites[0].hp = 3;
	game->sprites[0].u_div = 6;
	game->sprites[0].v_div = 6;
	game->sprite_num = 3;
	open_image(&game->sprites[1].texture_1, "./sprits/bowser1.xpm", game);
	open_image(&game->sprites[1].texture_2, "./sprits/bowser2.xpm", game);
	open_image(&game->sprites[2].texture_1, "./sprits/turtle1.xpm", game);
	open_image(&game->sprites[2].texture_2, "./sprits/turtle2.xpm", game);
	open_image(&game->sprites[2].texture_3, "./sprits/turtle3.xpm", game);
	open_image(&game->sprites[1].texture_3, "./sprits/bowser_mini.xpm", game);
	game->sprites[2].texture = &game->sprites[2].texture_1;
	game->mode = 1;
}

void	game_init(t_game *game, t_map pos)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, screenWidth, \
	screenHeight, "window");
	game->size_txt = texWidth;
	get_sprites(game);
	game->img.img = mlx_new_image(game->mlx, screenWidth, screenHeight);
	game->img.addr = mlx_get_data_addr(game->img.img, \
	&game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	game->map = pos;
}

void	get_sprites(t_game *game)
{
	open_image(&game->door, "./sprits/door.xpm", game);
	open_image(&game->img_1, "./sprits/sprite1.xpm", game);
	open_image(&game->img_2, "./sprits/sprite2.xpm", game);
	open_image(&game->img_3, "./sprits/sprite3.xpm", game);
	open_image(&game->img_4, "./sprits/sprite4.xpm", game);
}
