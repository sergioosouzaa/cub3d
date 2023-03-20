/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:59:59 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/20 13:22:21 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	display_controls(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->menu[0].img, 0, 0);
}

void	handle_controls(t_game *game)
{
	if (game->key.space == 1)
	{
		game->mode = 4;
		system("killall afplay");
		system("afplay ./sounds/game.mp3 &");
		mlx_destroy_image(game->mlx, game->menu[0].img);
		free(game->menu);
	}
	if (game->key.esc)
	{
		mlx_destroy_image(game->mlx, game->menu[0].img);
		free(game->menu);
		exit_close(game);
	}
	game->key.space = 0;
}
