#include "cube.h"

/*     Ok  */

t_data	get_texture(t_ray  ray, t_game game)
{
	t_data	texture;

	if (worldMap[ray.map_x][ray.map_y] == 9)
	{
		texture = game.door;
		return (texture);
	}
	if (ray.side == 1)
	{
		if (ray.raydir_y > 0)
			texture = game.img_1;
		else
			texture = game.img_2;
	}
	else
	{
		if (ray.raydir_x > 0)
			texture = game.img_3;
		else
			texture = game.img_4;

	}
	return (texture);
}