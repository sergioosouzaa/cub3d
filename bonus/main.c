/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:38:43 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/19 20:43:48 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	time_counter(t_game *game)
{
	static long long	time_1;
	static long long	time_2;
	static int			i;
	static int			j;

	if (get_first_time() - time_1 > 100)
	{
		i = (i + 1) % 2;
		game->sprites[1].texture = &game->sprites[1].texture_2;
		if (i == 0)
			game->sprites[1].texture = &game->sprites[1].texture_1;
		time_1 = get_first_time();
	}
	if (get_first_time() - time_2 > 100)
	{
		j = (j + 1) % 3;
		game->sprites[2].texture = &game->sprites[2].texture_3;
		if (j == 0)
			game->sprites[2].texture = &game->sprites[2].texture_1;
		else if (j == 1)
			game->sprites[2].texture = &game->sprites[2].texture_2;
		time_2 = get_first_time();
	}
}

void	animate(t_game *game)
{
	if (game->key.rotate_l || game->key.walk_l)
		game->sprites[0].texture = &game->sprites[0].texture_2;
	else if (game->key.rotate_r || game->key.walk_r)
		game->sprites[0].texture = &game->sprites[0].texture_3;
	else if (game->key.down)
		game->sprites[0].texture = &game->sprites[0].texture_4;
	else
		game->sprites[0].texture = &game->sprites[0].texture_1;
	time_counter(game);
}

void	check_hp(t_game *g)
{
	static long long	time;
	long long			c_time;

	c_time = get_first_time();
	if (g->sprites[1].hp > 0 && \
	fabs(g->sprites[1].pos_x - g->sprites[2].pos_x) < 0.12)
	{
		if (fabs(g->sprites[1].pos_y - g->sprites[2].pos_y) < 0.12 \
		&& c_time - time > 400)
		{
			g->sprites[1].hp = g->sprites[1].hp - 1;
			time = get_first_time();
			g->sprites[2].pos_x = -1;
			g->sprites[2].pos_y = -1;
		}
	}
	if (fabs(g->sprites[1].pos_x - g->sprites[0].pos_x) < 0.12)
	{
		if (fabs(g->sprites[1].pos_y - g->sprites[0].pos_y) < 0.12 \
		&& c_time - time > 400)
		{
			g->sprites[0].hp = g->sprites[0].hp - 1;
			time = get_first_time();
		}
	}
}

int	game_loop(t_game *game)
{
	if (game->mode == 4)
		start_game(game);
	else if (game->mode == 1)
		start_menu(game);
	else if (game->mode == 2)
		start_select(game);
	else if (game->mode == 3)
		start_controls(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	pos;
	t_game	game;

	if (argc == 2)
	{
		game.first_time = get_first_time();
		initialize_chaos();
		init_map(&pos, argv, &game);
		game_init(&game, pos);
		create_sprites(&game);
		game.map = pos;
		game.key = init_keys();
		system("afplay ./sounds/init.mp3 &");
		open_menu(&game);
		create_doors(&game);
		mlx_hook(game.mlx_win, 2, (1L << 0), &handle_press, &game);
		mlx_hook(game.mlx_win, 3, (1L << 1), &handle_release, &game);
		mlx_hook(game.mlx_win, 17, 1L << 17, exit_close, &game);
		mlx_mouse_hook(game.mlx_win, &mouse_event, &game);
		mlx_loop_hook(game.mlx, &game_loop, &game);
		mlx_loop(game.mlx);
	}
	m_erro("Map not valid.\n");
}
