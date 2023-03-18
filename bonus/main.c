/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:38:43 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/14 16:33:32 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	animate(t_game *game)
{
	static long long time_1;
	static long long time_2;
	static	int			i;
	static	int			j;

	if (game->key.rotate_l)
		game->sprites[0].texture = &game->sprites[0].texture_2;
	else if (game->key.rotate_r)
		game->sprites[0].texture = &game->sprites[0].texture_3;
	else if (game->key.down)
		game->sprites[0].texture = &game->sprites[0].texture_4;
	else
		game->sprites[0].texture = &game->sprites[0].texture_1;
	if (get_first_time() -  time_1 > 100)
	{
		i = (i + 1) % 2;
		if (i == 0)
			game->sprites[1].texture = &game->sprites[1].texture_1;
		else
			game->sprites[1].texture = &game->sprites[1].texture_2	;
		time_1 = get_first_time();
	}
	if (get_first_time() -  time_2 > 100)
	{
		j = (j + 1) % 3;
		if (j == 0)
			game->sprites[2].texture = &game->sprites[2].texture_1;
		else if (j == 1)
			game->sprites[2].texture = &game->sprites[2].texture_2;
		else
			game->sprites[2].texture = &game->sprites[2].texture_3;
		time_2 = get_first_time();
	}
}

void	check_hp(t_game *game)
{
	static long long time;

	if (game->sprites[1].hp > 0)
	{
		if (fabs(game->sprites[1].pos_x - game->sprites[2].pos_x) < 0.08)
		{
			if (fabs(game->sprites[1].pos_y - game->sprites[2].pos_y) < 0.08)
			{
				if (get_first_time() - time > 400)
				{
					game->sprites[1].hp = game->sprites[1].hp - 1;
					time = get_first_time();
					game->sprites[2].pos_x = -1;
					game->sprites[2].pos_y = -1;
				}
			}
		}
	}
	if (fabs(game->sprites[1].pos_x - game->sprites[0].pos_x) < 0.08)
	{
		if (fabs(game->sprites[1].pos_y - game->sprites[0].pos_y) < 0.08)
		{
			if (get_first_time() - time > 400)
			{
				game->sprites[0].hp = game->sprites[0].hp - 1;
				time = get_first_time();
			}
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

int main(int argc, char **argv)
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
		game.doors = malloc(sizeof(t_door));
		game.door_num = 1;
		game.doors[0].pos_x = 13;
		game.doors[0].pos_y = 13;
		game.doors[0].first_time = 0;
		game.doors[0].mode = 1;
		game.doors[0].x = 1;
		mlx_hook(game.mlx_win, 2, (1L<<0), &handle_press,  &game);
		mlx_hook(game.mlx_win, 3, (1L<<1), &handle_release,  &game);
		mlx_hook(game.mlx_win, 17, 1L << 17, exit_close, &game);
		mlx_mouse_hook(game.mlx_win, &mouse_event, &game);
		mlx_loop_hook(game.mlx, &game_loop, &game);
		mlx_loop(game.mlx);			
	}
	m_erro("Map not valid.\n");
};