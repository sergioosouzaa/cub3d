/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:49:58 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/14 16:53:37 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	open_char_select(t_game *game)
{
	game->menu = malloc(sizeof(t_data) * 5);
	open_image(&game->menu[0], "./sprits/peach_menu.xpm", game);
	open_image(&game->menu[1], "./sprits/peach_menu2.xpm", game);
	open_image(&game->menu[2], "./sprits/luigi_menu.xpm", game);
	open_image(&game->menu[3], "./sprits/luigi_menu2.xpm", game);
	open_image(&game->menu[4], "./sprits/char_select.xpm", game);
}

void	open_luigi(t_game *game)
{
	open_image(&game->sprites[0].texture_1, "./sprits/luigi_race1.xpm", game);
	open_image(&game->sprites[0].texture_2, "./sprits/luigi_race2.xpm", game);
	open_image(&game->sprites[0].texture_3, "./sprits/luigi_race3.xpm", game);
	open_image(&game->sprites[0].texture_4, "./sprits/luigi_race4.xpm", game);
	open_image(&game->minimap, "./sprits/luigi_profile.xpm", game);
}

void	open_peach(t_game *game)
{
	open_image(&game->sprites[0].texture_1, "./sprits/peach_race1.xpm", game);
	open_image(&game->sprites[0].texture_2, "./sprits/peach_race2.xpm", game);
	open_image(&game->sprites[0].texture_3, "./sprits/peach_race3.xpm", game);
	open_image(&game->sprites[0].texture_4, "./sprits/peach_race4.xpm", game);
	open_image(&game->minimap, "./sprits/peach_profile.xpm", game);
}

void	handle_char_select(t_game *game)
{
	if (game->key.rotate_l || game->key.walk_l)
		game->char_select = 0;
	if (game->key.rotate_r || game->key.walk_r)
		game->char_select = 1;
	if (game->key.space || game->key.esc)
	{
		game->mode = 3;
		mlx_destroy_image(game->mlx, game->menu[0].img);
		mlx_destroy_image(game->mlx, game->menu[1].img);
		mlx_destroy_image(game->mlx, game->menu[2].img);
		mlx_destroy_image(game->mlx, game->menu[3].img);
		free(game->menu);
	}
	if (game->key.space)
	{
		if (game->char_select == 0)
			open_luigi(game);
		else
			open_peach(game);
		game->menu = malloc(sizeof(t_data));
		open_image(&game->menu[0], "./sprits/controls.xpm", game);
	}
	if (game->key.esc)
		exit_close(game);
	game->key.space = 0;
}

void	display_char_select(t_game *game)
{
	static long long	last_time;
	static int			i;

	if (get_first_time() - last_time > 150)
	{
		i = (i + 1) % 2;
		last_time = get_first_time();
	}
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->menu[4].img, 0, 0);
	if (game->char_select == 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->menu[0].img, \
		(screenWidth / 4) * 0.8, screenHeight / 2);
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->menu[2 + i].img, (screenWidth / 4) * 3, screenHeight / 2);
	}
	else if (game->char_select == 1)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->menu[i].img, \
		(screenWidth / 4) * 0.8, screenHeight / 2);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->menu[2].img, \
		(screenWidth / 4) * 3, screenHeight / 2);
	}
}
