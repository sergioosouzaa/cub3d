/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:59:59 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/13 11:00:17 by sdos-san         ###   ########.fr       */
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
		mlx_destroy_image(game->mlx, game->menu[0].img);
		free(game->menu);
	}
	game->key.space = 0;
}
