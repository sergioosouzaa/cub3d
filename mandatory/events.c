/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:23 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/14 16:38:51 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	handle_press(int key, t_game *game)
{
	if (key == KEY_LEFT)
		game->key.rotate_l = 1;
	if (key == KEY_RIGHT)
		game->key.rotate_r = 1;
	if (key == KEY_DOWN)
		game->key.down = 1;
	if (key == KEY_UP)
		game->key.up = 1;
	if (key == KEY_ESC)
		game->key.esc = 1;
	if (key == KEY_WALK_LEFT)
		game->key.left = 1;
	if (key == KEY_WALK_RIGHT)
		game->key.right = 1;
	return (0);
}

int	handle_release(int key, t_game *game)
{
	if (key == KEY_LEFT)
		game->key.rotate_l = 0;
	if (key == KEY_RIGHT)
		game->key.rotate_r = 0;
	if (key == KEY_DOWN)
		game->key.down = 0;
	if (key == KEY_UP)
		game->key.up = 0;
	if (key == KEY_ESC)
		game->key.esc = 0;
	if (key == KEY_WALK_LEFT)
		game->key.left = 0;
	if (key == KEY_WALK_RIGHT)
		game->key.right = 0;
	return (0);
}

void	walk(t_game *game, int signal)
{
	double	pos_x;
	double	pos_y;

	pos_x = game->map.pos_x + (signal) * (game->map.dir_x * 0.05);
	pos_y = game->map.pos_y + (signal) * (game->map.dir_y * 0.05);
	if (game->world_map[(int)pos_x][(int)pos_y] < '1')
	{
		game->map.pos_x = pos_x;
		game->map.pos_y = pos_y;
	}
}

void	rotate(t_game *game, int signal)
{
	double	aux;

	aux = game->map.dir_x;
	game->map.dir_x = game->map.dir_x * cos((signal) * (ROT))
		- game->map.dir_y * sin((signal) * (ROT));
	game->map.dir_y = aux * sin((signal) *(ROT)) + game->map.dir_y
		* cos((signal) *(ROT));
	aux = game->map.plane_x;
	game->map.plane_x = game->map.plane_x * cos((signal) *(ROT))
		- game->map.plane_y * sin((signal) *(ROT));
	game->map.plane_y = aux * sin((signal) *(ROT)) + game->map.plane_y
		* cos((signal) *(ROT));
}

int	handle_key(t_game *game)
{
	if (game->key.down && game->key.down != game->key.up)
		walk(game, -1);
	if (game->key.up && game->key.down != game->key.up)
		walk(game, 1);
	if (game->key.left && game->key.left != game->key.right)
		walk_side(game, -1);
	if (game->key.right && game->key.right != game->key.left)
		walk_side(game, 1);
	if (game->key.rotate_l && game->key.rotate_l != game->key.rotate_r)
		rotate(game, -1);
	if (game->key.rotate_r && game->key.rotate_l != game->key.rotate_r)
		rotate(game, 1);
	if (game->key.esc)
		exit_close(game);
	return (0);
}
