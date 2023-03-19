/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:58:45 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/19 19:51:37 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	start_game(t_game *game)
{
	long long	time;
	char		*fps;
	int			x;
	int			y;

	time = get_first_time();
	mlx_mouse_get_pos(game->mlx_win, &x, &y);
	if (x > game->init_x)
		check_valid_cam(game, -1, ROT);
	else if (x < game->init_x)
		check_valid_cam(game, 1, ROT);
	game->init_x = x;
	handle_key(game);
	handle_doors(game);
	move_sprites(game);
	animate(game);
	check_hp(game);
	raycast(*game);
	fps = ft_itoa(60 / (get_first_time() - time));
	mlx_string_put(game->mlx, game->mlx_win, 5, 10, 0x00FF00FF, fps);
	if (game->sprites[1].hp > 0)
		mlx_string_put(game->mlx, game->mlx_win, \
		(SCREENWIDTH / 2) - 10, 30, 0x00FF0000, "BOWSER HP");
	if (game->sprites[0].hp > 0)
		mlx_string_put(game->mlx, game->mlx_win, \
		90, 30, 0x0000FF00, "YOUR HP");
	free(fps);
}

void	start_menu(t_game *game)
{
	display_menu(game);
	handle_menu(game);
}

void	start_select(t_game *game)
{
	display_char_select(game);
	handle_char_select(game);
}

void	start_controls(t_game *game)
{
	display_controls(game);
	handle_controls(game);
}

int	mouse_event(int button, int x, int y, t_game *game)
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;

	(void)x;
	(void)y;
	camera_x = 2 * (SCREENWIDTH / 5 * 3.7) / (double)(SCREENWIDTH) - 1;
	raydir_x = game->map.dir_x + (game->map.plane_x * camera_x);
	raydir_y = game->map.dir_y + (game->map.plane_y * camera_x);
	if (button == 1)
	{
		game->sprites[2].pos_x = game->sprites[0].pos_x;
		game->sprites[2].pos_y = game->sprites[0].pos_y;
		game->sprites[2].dir_x = raydir_x;
		game->sprites[2].dir_y = raydir_y;
	}
	if (game->sprites[1].hp <= 0)
	{
		game->sprites[1].pos_x = -1;
		game->sprites[1].pos_y = -1;
	}
	if (button == 2)
		game->sky = (game->sky + 1) % 2;
	return (0);
}
