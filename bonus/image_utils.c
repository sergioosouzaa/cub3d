/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:58:06 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/19 19:01:50 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	open_image(t_data *img_ptr, char *path, t_game *game)
{
	int	width;
	int	height;

	width = SCREENWIDTH;
	height = SCREENHEIGHT;
	img_ptr->img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	img_ptr->addr = mlx_get_data_addr(img_ptr->img, &img_ptr->bits_per_pixel, \
					&img_ptr->line_length, &img_ptr->endian);
}

void	open_image_size(t_data *img_ptr, char *path, t_game *game, int size)
{
	img_ptr->img = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	img_ptr->addr = mlx_get_data_addr(img_ptr->img, &img_ptr->bits_per_pixel, \
					&img_ptr->line_length, &img_ptr->endian);
}
