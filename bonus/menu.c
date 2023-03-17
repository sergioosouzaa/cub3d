/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:53:40 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/17 14:39:08 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	open_menu(t_game *game)
{
	game->menu = malloc(sizeof(t_data) * 3);
	open_image(&game->menu[0], "./sprits/menu1.xpm", game);
	open_image(&game->menu[1], "./sprits/menu2.xpm", game);
	open_image(&game->menu[2], "./sprits/menu3.xpm", game);
}

void	display_menu(t_game *game)
{
	static long long	last_time;
	static int			i;

	if (get_first_time() - last_time > 150)
	{
		i = (i + 1) % 3;
		last_time = get_first_time();
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->menu[i].img, 0, 0);
}

int	handle_menu(t_game *game)
{
	if (game->key.space)
	{
		mlx_destroy_image(game->mlx, game->menu[0].img);
		mlx_destroy_image(game->mlx, game->menu[1].img);
		mlx_destroy_image(game->mlx, game->menu[2].img);
		free(game->menu);
		game->mode = 2;
		open_char_select(game);
		game->char_select = 1;
		game->key.space = 0;
	}
	if (game->key.esc)
	{
		mlx_destroy_image(game->mlx, game->menu[0].img);
		mlx_destroy_image(game->mlx, game->menu[1].img);
		mlx_destroy_image(game->mlx, game->menu[2].img);
		free(game->menu);
		exit_close(game);
	}
	return (0);
}
