/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:26 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/14 11:25:53 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_map	pos;
	t_game	game;

	if (argc == 2)
	{
		init_map(&pos, argv, &pos, &game);
		invalid_config(&pos);
		color_rgb(pos.floor, &game, 0);
		color_rgb(pos.ceiling, &game, 1);
		get_sprites(&pos, &game);
		game.map = pos;
		raycast(game);
		mlx_hook(game.mlx_win, 2, (1L << 0), &handle_press, &game);
		mlx_hook(game.mlx_win, 3, (1L << 1), &handle_release, &game);
		mlx_hook(game.mlx_win, 17, 1L << 17, exit_close, &game);
		mlx_loop_hook(game.mlx, &game_loop, &game);
		mlx_loop(game.mlx);
	}
	printf("Map not found\n");
}

void	walk_side(t_game *game, int signal)
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;

	dir_x = game->map.dir_x * cos((signal) * (1.571))
		- game->map.dir_y * sin((signal) * (1.571));
	dir_y = game->map.dir_x  * sin((signal) *(1.571)) + game->map.dir_y
		* cos((signal) *(1.571));
	pos_x = game->map.pos_x + (dir_x * 0.05);
	pos_y = game->map.pos_y + (dir_y * 0.05);
	if (game->world_map[(int)pos_x][(int)pos_y] < '1')
	{
		game->map.pos_x = pos_x;
		game->map.pos_y = pos_y;
	}
}
