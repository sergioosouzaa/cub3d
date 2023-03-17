/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:29:14 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/16 17:12:59 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*     Ok  */

t_data	get_texture(t_ray ray, t_game game)
{
	t_data	texture;

	if (game.world_map[ray.map_x][ray.map_y] == '9')
	{
		texture = game.door;
		return (texture);
	}
	if (ray.side == 1)
	{
		if (ray.raydir_y > 0)
			texture = game.img_north;
		else
			texture = game.img_south;
	}
	else
	{
		if (ray.raydir_x > 0)
			texture = game.img_west;
		else
			texture = game.img_east;
	}
	return (texture);
}
