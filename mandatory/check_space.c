/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:04 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/16 18:28:29 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_ispace(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t')
		|| (str[i] >= 'A' && str[i] <= 'Z'))
	i++;
	return (i);
}

size_t	still_space(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (!ft_isalnum(str[len]))
		len--;
	return (len - ft_ispace(str) + 1);
}

void	free_matriz(char **str)
{
	int	i;

	i = 0;
	while (str[i++])
		free (str[i]);
	str = NULL;
}

void	init_game(t_game *game)
{
	game->key = init_keys();
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, SCREENWIDTH,
			SCREENHEIGHT, "cub3d");
	game->size_txt = TEXWIDTH;
	game->img.img = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
}
