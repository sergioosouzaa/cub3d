/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:12:14 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/19 19:52:32 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*ft_itoa(int n);

int	sky_color(t_game *game)
{
	int	i;
	int	j;

	i = rand() % 2000;
	j = rand() % 7;
	if (i == 10)
	{
		if (j == 0)
			return (0x9400D3);
		if (j == 1)
			return (0x4B0082);
		if (j == 2)
			return (0x0000FF);
		if (j == 3)
			return (0x00FF00);
		if (j == 4)
			return (0xFFFF00);
		if (j == 5)
			return (0xFF7F00);
		if (j == 6)
			return (0xFF0000);
	}
	if (game->sky == 0)
		return (0xdff0ff);
	return (0x00000000);
}

int	floor_color(int y, int f)
{
	int	j;
	int	h[7];

	h[0] = 0xf94144;
	h[1] = 0xf3722c;
	h[2] = 0xf8961e;
	h[3] = 0xf9844a;
	h[4] = 0xf9c74f;
	h[5] = 0x90be6d;
	h[6] = 0x43aa8b;
	j = ((y / 30));
	return (h[(f + j) % 7]);
}

int	return_f(void)
{
	static int			f;
	static long long	last_time;

	if (get_first_time() - last_time > 100)
	{
		f = (f + 1) % 7;
		last_time = get_first_time();
	}
	return (f);
}

void	paint_raycast(t_game game, t_ray *ray, int x, int f)
{
	int		y;

	y = 0;
	while (y < SCREENHEIGHT)
	{
		if (y < ray->draw_start)
			my_mlx_pixel_put(&game.img, x, y, sky_color(&game));
		else if (y < ray->draw_end)
		{
			ray->tex_y = (int)ray->tex_pos;
			if (ray->tex_y > TEXHEIGHT - 1)
				ray->tex_y = TEXHEIGHT - 1;
			ray->tex_pos += ray->step;
			ray->color = get_color(&ray->texture, ray->tex_x, ray->tex_y);
			if (ray->side == 1)
				ray->color = (ray->color >> 1) & 8355711;
			my_mlx_pixel_put(&game.img, x, y, ray->color);
		}
		else
			my_mlx_pixel_put(&game.img, x, y, floor_color(y, f));
		y++;
	}
}

void	raycast(t_game game)
{
	t_ray	ray;
	int		x;
	int		*perpedist;
	int		f;

	x = 0;
	f = return_f();
	perpedist = malloc(sizeof(int) * SCREENWIDTH);
	while (x < SCREENWIDTH)
	{
		ray_init(&ray, game, x);
		side_dist_init(&ray, game.map);
		dda(&ray, game);
		calc_texture(&ray, game);
		paint_raycast(game, &ray, x, f);
		perpedist[x] = ray.perpwalldist;
		x++;
	}
	draw_sprites(perpedist, &game);
	draw_minimap(game);
	draw_health(&game);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img.img, 0, 0);
	put_pic_minimap(game);
	free(perpedist);
}
