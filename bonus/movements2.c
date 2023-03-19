/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:53:08 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/19 19:22:00 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	change_cam(t_game *game, int signal, double rotation)
{
	double	aux[4];
	double	ang;

	ang = rotation * signal;
	aux[0] = game->map.dir_x;
	aux[2] = game->map.dir_y;
	game->map.dir_x = game->map.dir_x * cos(ang) - game->map.dir_y * sin(ang);
	game->map.dir_y = aux[0] * sin(ang) + game->map.dir_y * cos(ang);
	aux[1] = game->map.plane_x;
	aux[3] = game->map.plane_y;
	game->map.plane_x = game->map.plane_x * cos(ang) \
	- game->map.plane_y * sin(ang);
	game->map.plane_y = aux[1] * sin(ang) + game->map.plane_y * cos(ang);
}

void	save_data(t_game *game, int mode)
{
	static double	aux[6];

	if (mode == 1)
	{
		aux[2] = game->map.dir_x;
		aux[3] = game->map.dir_y;
		aux[0] = game->map.plane_x;
		aux[1] = game->map.plane_y;
		aux[4] = game->map.pos_x;
		aux[5] = game->map.pos_y;
	}
	if (mode == 0)
	{
		game->map.dir_x = aux[2];
		game->map.dir_y = aux[3];
		game->map.plane_x = aux[0];
		game->map.plane_y = aux[1];
	}
	if (mode == 2)
	{
		game->map.pos_x = aux[4];
		game->map.pos_y = aux[5];
	}	
}

void	walk_side(t_game *game, int signal)
{
	save_data(game, 1);
	change_cam(game, signal, 1.571);
	if (game->world_map[(int)(game->map.pos_x + (game->map.dir_x * \
	0.12))][(int)(game->map.pos_y + (game->map.dir_y * 0.12))] < '1')
	{
		game->map.pos_x = game->map.pos_x + (game->map.dir_x * 0.12);
		game->map.pos_y = game->map.pos_y + (game->map.dir_y * 0.12);
	}
	save_data(game, 0);
	if (!check_valid_pos(game, 1, 0.12))
		save_data(game, 2);
}
