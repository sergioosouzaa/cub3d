/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:30:11 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/17 18:41:53 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

	// 	if (game->sprites[1].hp <= 0)
	// {
	// 	game->sprites[1].pos_x = -1;
	// 	game->sprites[1].pos_y = -1;
	// }


void	move_turtle(t_game *game)
{
	double	vector;
	double	aux_1;

	if (game->sprites[2].pos_x > 0 && game->sprites[2].pos_y > 0)
	{
		vector = sqrt(game->sprites[2].dir_x * game->sprites[2].dir_x \
		+ game->sprites[2].dir_y * game->sprites[2].dir_y);
		if (worldMap[(int)(game->sprites[2].pos_x + (game->sprites[2].dir_x \
		/ vector))][(int)(game->sprites[2].pos_y + \
		(game->sprites[2].dir_y / vector))] > 0)
		{
			aux_1 = game->sprites[2].dir_x;
			game->sprites[2].dir_x = game->sprites[2].dir_x * \
			cos(0.78) - game->sprites[2].dir_y * sin(0.78);
			game->sprites[2].dir_y = aux_1 * sin(0.78) + \
			game->sprites[2].dir_y * cos(0.78);
		}
		else
		{
			game->sprites[2].pos_x = game->sprites[2].pos_x + \
			(game->sprites[2].dir_x / vector) * 0.08;
			game->sprites[2].pos_y = game->sprites[2].pos_y + \
			(game->sprites[2].dir_y / vector) * 0.08;
		}
	}
}

void	move_mc(t_game *game)
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	vector;

	camera_x = 2 * (screenWidth / 5 * 3.7) / (double)(screenWidth) - 1;
	raydir_x = game->map.dir_x + (game->map.plane_x * camera_x);
	raydir_y = game->map.dir_y + (game->map.plane_y * camera_x);
	vector = sqrt(raydir_x * raydir_x + raydir_y * raydir_y);
	game->sprites[0].pos_x = game->map.pos_x + (raydir_x / vector) * 0.4;
	game->sprites[0].pos_y = game->map.pos_y + (raydir_y / vector) * 0.4;
}

void	move_bowser(t_game *game)
{
	static long long	time;

	if (get_first_time() - time > 10)
	{
		time = get_first_time();
		if (game->sprites[1].pos_x >= 0 && game->sprites[1].pos_y >= 0)
		{
			if (fabs(game->sprites[1].pos_x - game->sprites[0].pos_x) > 0.016)
			{
				if (game->sprites[1].pos_x < game->sprites[0].pos_x && game->world_map[(int)(game->sprites[1].pos_x + 0.016)][(int)game->sprites[1].pos_y] < '1')
					game->sprites[1].pos_x = game->sprites[1].pos_x + 0.016;
				if (game->sprites[1].pos_x > game->sprites[0].pos_x && game->world_map[(int)(game->sprites[1].pos_x - 0.016)][(int)game->sprites[1].pos_y] < '1')
					game->sprites[1].pos_x = game->sprites[1].pos_x - 0.016;
			}
			if (fabs(game->sprites[1].pos_y - game->sprites[0].pos_y ) > 0.016)
			{
				if (game->sprites[1].pos_y < game->sprites[0].pos_y && game->world_map[(int)game->sprites[1].pos_x][(int)(game->sprites[1].pos_y + 0.016)] < '1')
					game->sprites[1].pos_y = game->sprites[1].pos_y + 0.016;
				if (game->sprites[1].pos_y > game->sprites[0].pos_y && game->world_map[(int)game->sprites[1].pos_x][(int)(game->sprites[1].pos_y - 0.016)] < '1')
					game->sprites[1].pos_y = game->sprites[1].pos_y - 0.016;
			}
		}
	}
}

void	move_sprites(t_game *game)
{
	move_mc(game);
	move_bowser(game);
	move_turtle(game);
} 