/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:03:14 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/19 19:19:21 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_index(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->door_num)
	{
		if (pow((game->doors[i].pos_x - (int)game->map.pos_x), 2) + \
		pow((game->doors[i].pos_y - (int)game->map.pos_y), 2) < 9)
			return (i);
		i++;
	}
	return (-1);
}

void	change_mode(t_game *game, int mode, int index)
{
	game->doors[index].mode = mode;
	game->doors[index].first_time = get_first_time();
	if (mode == 3)
		game->doors[index].x = 0.0;
	if (mode == 2)
		game->doors[index].x = game->doors[index].x - 0.1;
	if (mode == 4)
		game->doors[index].x = game->doors[index].x + 0.1;
}

int	handle_doors(t_game *game)
{
	int	i;
	int	cur_door;

	i = 0;
	cur_door = get_index(game);
	while (i < game->door_num)
	{
		if ((game->doors[0].mode != 2) && i == cur_door)
			change_mode(game, 2, i);
		else if (game->doors[0].mode == 2 && get_first_time() - \
		game->doors[0].first_time > 100)
			change_mode(game, 2, i);
		if (game->doors[0].mode == 2 && game->doors[0].x <= 0.0)
			change_mode(game, 3, i);
		if (game->doors[0].mode == 3 && i != cur_door)
			change_mode(game, 4, i);
		else if (game->doors[0].mode == 4 && (get_first_time() - \
		game->doors[0].first_time > 100))
			change_mode(game, 4, i);
		if (game->doors[0].mode == 4 && game->doors[0].x >= 1.0)
			change_mode(game, 1, i);
		i++;
	}
	return (0);
}

int	get_door_index(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->door_num)
	{
		if (x == game->doors[i].pos_x && y == game->doors[i].pos_y)
			return (i);
		i++;
	}
	return (-1);
}

void	create_doors(t_game *game)
{
	game->doors = malloc(sizeof(t_door));
	game->door_num = 1;
	game->doors[0].pos_x = 13;
	game->doors[0].pos_y = 13;
	game->doors[0].first_time = 0;
	game->doors[0].mode = 1;
	game->doors[0].x = 1;
}
