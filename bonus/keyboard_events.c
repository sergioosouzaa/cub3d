/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:56:39 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/18 17:29:17 by sdos-san         ###   ########.fr       */
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
	if (key == KEY_SPACE)
		game->key.space = 1;
	if (key == KEY_WALK_LEFT)
		game->key.walk_l = 1;
	if (key == KEY_WALK_RIGHT)
		game->key.walk_r = 1;
	if (key == KEY_ESC)
	{
		system("killall afplay");
		system("afplay ./sounds/finish.mp3 &");
		game->key.esc = 1;
	}
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
	if (key == KEY_SPACE)
		game->key.space = 0;
	if (key == KEY_WALK_LEFT)
		game->key.walk_l = 0;
	if (key == KEY_WALK_RIGHT)
		game->key.walk_r = 0;	
	return (0);
}

t_keys	init_keys(void)
{
	t_keys	key;

	key.up = 0;
	key.down = 0;
	key.esc = 0;
	key.rotate_r = 0;
	key.rotate_l = 0;
	key.space = 0;
	key.walk_r = 0;
	key.walk_l = 0;
	return (key);
}
