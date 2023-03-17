/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:03 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/17 19:40:55 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	walk(t_game *game, int signal, double speed)
{
	if (check_valid_pos(game, signal, speed))
	{
		game->map.pos_x = game->map.pos_x + (signal) * \
		(game->map.dir_x * speed);
		game->map.pos_y = game->map.pos_y + (signal) * \
		(game->map.dir_y * speed);
	}
}

int	handle_key(t_game *game)
{
	double	speed;

	speed = 0.08;
	if (game->key.space)
		speed = 0.16;
	if (game->key.esc)
		exit_close(game);
	if (game->key.down && game->key.down != game->key.up)
		walk(game, -1, speed);
	if (game->key.up && game->key.down != game->key.up)
		walk(game, 1, speed);
	if (game->key.rotate_l && game->key.rotate_l != game->key.rotate_r)
		check_valid_cam(game, -1);
	if (game->key.rotate_r && game->key.rotate_l != game->key.rotate_r)
		check_valid_cam(game, 1);
	return (0);
}

int	check_valid_pos(t_game *game, int signal, double speed)
{
	size_t	pos_x;
	size_t	pos_y;
	t_ray	ray_1;
	t_ray	ray_2;

	ray_init(&ray_1, *game, (screenWidth / 2) - 0.015 * screenWidth);
	side_dist_init(&ray_1, game->map);
	dda(&ray_1, *game);
	ray_init(&ray_2, *game, (screenWidth / 2) + 0.12 * screenWidth);
	side_dist_init(&ray_2, game->map);
	dda(&ray_2, *game);
	if (game->key.shift)
		speed = 0.12;
	pos_x = (int)(game->map.pos_x + signal * game->map.dir_x * speed);
	pos_y = (int)(game->map.pos_y + signal * game->map.dir_y * speed);
	if (pos_x > 0 && pos_x < game->map.lines && pos_y > 0 && pos_y \
	< game->map.columns && (game->world_map[pos_x][pos_y] < '1' || \
	game->world_map[pos_x][pos_y] == '9'))
	{
		if ((ray_1.perpwalldist >= 1.5 && ray_2.perpwalldist >= 1.5) || \
		signal == -1)
			return (1);
	}
	return (0);
}

int	get_info(t_game *game, double *aux)
{
	game->map.dir_x = aux[0];
	game->map.plane_x = aux[1];
	game->map.dir_y = aux[2];
	game->map.plane_y = aux[3];
	return (0);
}

int	check_valid_cam(t_game *game, int signal)
{
	double	aux[4];
	t_ray	ray_1;
	t_ray	ray_2;
	double	ang;

	ang = rot * signal;
	aux[0] = game->map.dir_x;
	aux[2] = game->map.dir_y;
	game->map.dir_x = game->map.dir_x * cos(ang) - game->map.dir_y * sin(ang);
	game->map.dir_y = aux[0] * sin(ang) + game->map.dir_y * cos(ang);
	aux[1] = game->map.plane_x;
	aux[3] = game->map.plane_y;
	game->map.plane_x = game->map.plane_x * cos(ang) \
	- game->map.plane_y * sin(ang);
	game->map.plane_y = aux[1] * sin(ang) + game->map.plane_y * cos(ang);
	ray_init(&ray_1, *game, (screenWidth / 2) - 0.015 * screenWidth);
	side_dist_init(&ray_1, game->map);
	dda(&ray_1, *game);
	ray_init(&ray_2, *game, (screenWidth / 2) + 0.12 * screenWidth);
	side_dist_init(&ray_2, game->map);
	dda(&ray_2, *game);
	if ((ray_1.perpwalldist >= 1.5 && ray_2.perpwalldist >= 1.5))
		return (1);
	else
		return (get_info(game, aux));
}
