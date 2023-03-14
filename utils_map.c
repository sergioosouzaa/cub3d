/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:41 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/11 17:09:56 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	invalid_map(char **new_map, t_map *map)
{
	invalid_char(new_map);
	get_mapsize(new_map, map);
	fill_map(new_map, map);
}

void	init_map(t_map *map, char **argv, t_map *pos, t_game *game)
{
	char	**old_map;
	char	**new_map;

	map->ceiling = 0;
	map->east = 0;
	map->dir_x = 0;
	map->dir_y = 0;
	map->north = 0;
	map->west = 0;
	map->south = 0;
	map->floor = 0;
	old_map = get_map(argv);
	new_map = creating_map(old_map, pos);
	get_pos(new_map, pos);
	invalid_map(new_map, pos);
	game->world_map = new_map;
}

void	invalid_config(t_map *map)
{
	if ((!map->south) || (!map->north) || (!map->west) || (!map->east)
		|| (!map->floor) || (!map->ceiling) || (!map->pos_x) || (!map->pos_y))
		m_erro("Missing map configuration.\n");
}

void	set_direction(double *dir, int nbr)
{
	*dir = nbr;
}

void	map_border(char **new_map, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (new_map[y])
	{
		new_map[y] = ft_strjoin_("3", new_map[y]);
		while (ft_strlen(new_map[y]) < map->columns + 2)
			new_map[y] = ft_strjoin_(new_map[y], "3");
		x = 0;
		while (new_map[y][x] != '\0')
		{
			if (new_map[y][x] == ' ' || new_map[y][x] == '\t')
				new_map[y][x] = '3';
			else
				x++;
		}
		y++;
	}
}
