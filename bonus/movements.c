/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:03 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/18 19:13:30 by sdos-san         ###   ########.fr       */
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

int	check_mc_pos(t_game *game, double pos_x, double pos_y)
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	vector;

	camera_x = 2 * (screenWidth / 5 * 3.7) / (double)(screenWidth) - 1;
	raydir_x = game->map.dir_x + (game->map.plane_x * camera_x);
	raydir_y = game->map.dir_y + (game->map.plane_y * camera_x);
	vector = sqrt(raydir_x * raydir_x + raydir_y * raydir_y);
	if (game->world_map[(int)(pos_x + (raydir_x / vector) * 0.4)][(int) \
	(pos_y + (raydir_y / vector) * 0.4)] < '1')
		return (1);
	else
		return (0);
}

//  || (game->world_map[(int) \
// 	(pos_x + (raydir_x / vector) * 1.5)][(int)(pos_y + (raydir_y / vector) \
// 	* 0.4)] == '9' && game->doors[0].mode == 4))

int	check_valid_side(t_game *game, int signal, double speed)
{
	size_t	pos_x;
	size_t	pos_y;
	t_ray	ray_1;
	t_ray	ray_2;

	ray_init(&ray_1, *game, screenWidth);
	side_dist_init(&ray_1, game->map);
	dda(&ray_1, *game);
	ray_init(&ray_2, *game, (0));
	side_dist_init(&ray_2, game->map);
	dda(&ray_2, *game);
	if (game->key.space)
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


void	walk_side(t_game *game, int signal)
{
	// double	pos_x;
	// double	pos_y;
	// double	dir_x;
	// double	dir_y;
	t_game	test;


	test.map.dir_x = game->map.dir_x;
	test.map.dir_y = game->map.dir_y;
	test.map.plane_x = game->map.plane_x;
	test.map.plane_y = game->map.plane_y;
	test.map.pos_x = game->map.pos_x;
	test.map.pos_y = game->map.pos_y;
	test.world_map = game->world_map;
	test.doors = game->doors;
	if (check_valid_cam(&test, signal, 1.571))
	{
		if(check_valid_pos(&test, signal, 0.12))
		{
			game->map.pos_x = game->map.pos_x +  (test.map.dir_x * 0.12);
			game->map.pos_y = game->map.pos_y +  (test.map.dir_y * 0.12);
		}
	}

	// dir_x = game->map.dir_x * cos((signal) * (1.571))
	// 	- game->map.dir_y * sin((signal) * (1.571));
	// dir_y = game->map.dir_x * sin((signal) *(1.571)) + game->map.dir_y
	// 	* cos((signal) *(1.571));
	// pos_x = game->map.pos_x + (dir_x * 0.05);
	// pos_y = game->map.pos_y + (dir_y * 0.05);

	// if (check_mc_pos(game, signal, 0.12))
	// {
	// 	game->map.pos_x = pos_x;
	// 	game->map.pos_y = pos_y;
	// }
	// if (game->world_map[(int)pos_x][(int)pos_y] < '1' && check_mc_pos(game, pos_x, pos_y))
	// {
	// 	game->map.pos_x = pos_x;
	// 	game->map.pos_y = pos_y;
	// }
}

// void	walk_side(t_game *game, int signal)
// {
// 	// double	pos_x;
// 	// double	pos_y;
// 	t_game	test;

// 	test.map.dir_x = game->map.dir_x * cos((signal) * (1.571))
// 		- game->map.dir_y * sin((signal) * (1.571));
// 	test.map.dir_y = game->map.dir_x * sin((signal) *(1.571)) + game->map.dir_y
// 		* cos((signal) *(1.571));
// 	test.map.pos_x = game->map.pos_x;
// 	test.map.pos_y = game->map.pos_y;
// 	test.map.plane_x =  game->map.plane_x * cos((signal) * (1.571)) - game->map.plane_y * sin((signal) * (1.571));
// 	test.map.plane_y =  game->map.plane_x * sin((signal) *(1.571)) + game->map.plane_y * cos((signal) *(1.571));
// 	test.world_map = game->world_map;
// 	test.doors = game->doors;

// 	double	camera_x;
// 	double	raydir_x;
// 	double	raydir_y;
// 	double	vector;
// 	double	pos_x;
// 	double	pos_y;

// 	camera_x = 2 * (screenWidth / 5 * 3.7) / (double)(screenWidth) - 1;
// 	raydir_x = test.map.dir_x + (test.map.plane_x * camera_x);
// 	raydir_y = test.map.dir_y + (test.map.plane_y * camera_x);
// 	vector = sqrt(raydir_x * raydir_x + raydir_y * raydir_y);
// 	pos_x = test.map.pos_x + (raydir_x / vector) * 0.4;
// 	pos_y = test.map.pos_y + (raydir_y / vector) * 0.4;
// 	test.map.pos_x = pos_x;
// 	test.map.pos_y = pos_y;
// 	if (check_valid_pos(&test, 1, 0.12))
// 	{
// 		game->map.pos_x = game->map.pos_x +  (test.map.dir_x * 0.12);
// 		game->map.pos_y = game->map.pos_y +  (test.map.dir_y * 0.12);
// 	}
// }

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
		check_valid_cam(game, -1, rot);
	if (game->key.rotate_r && game->key.rotate_l != game->key.rotate_r)
		check_valid_cam(game, 1, rot);
	if (game->key.walk_l && game->key.walk_l != game->key.walk_r)
		walk_side(game, -1);
	if (game->key.walk_r && game->key.walk_l != game->key.walk_r)
		walk_side(game, 1);
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
	if (game->key.space)
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

int	check_valid_cam(t_game *game, int signal, double rotation)
{
	double	aux[4];
	t_ray	ray_1;
	t_ray	ray_2;
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
