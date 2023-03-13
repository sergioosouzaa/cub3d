/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:26 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/13 18:36:27 by thsousa          ###   ########.fr       */
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
