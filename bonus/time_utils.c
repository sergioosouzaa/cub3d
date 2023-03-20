/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:28:04 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/19 21:06:59 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/* initialize the seed to the random funciton */

void	initialize_chaos(void)
{
	time_t	t;

	srand((unsigned) time(&t));
}

/*  Get the time at the start of the program, so
it can know the that that passed while it was running */

long long	get_first_time(void)
{
	struct timeval	first;

	gettimeofday(&first, NULL);
	return ((first.tv_sec) * 1000 + (first.tv_usec) * 0.001);
}

void	play_music(void)
{
	static long long	time;

	if (get_first_time() - time > 120000)
	{
		system("killall afplay");
		system("afplay ./sounds/game.mp3 &");
	}
}

void	game_over(t_game *game)
{
	if (game->sprites[0].hp <= 0)
		exit_close(game);
}

void	continue_game(t_game *game)
{
	if (game->sprites[1].hp <= 0)
	{
		game->sprites[1].pos_x = -1;
		game->sprites[1].pos_y = -1;
	}
	if (game->sprites[1].hp > 0)
		mlx_string_put(game->mlx, game->mlx_win, \
		(SCREENWIDTH / 2) - 10, 30, 0x00FF0000, "BOWSER HP");
	if (game->sprites[0].hp > 0)
		mlx_string_put(game->mlx, game->mlx_win, \
		90, 30, 0x0000FF00, "YOUR HP");
	play_music();
	game_over(game);
}
