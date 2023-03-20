/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:50 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/20 11:44:53 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	**get_map(char **argv)
{
	int		fd;
	char	*str;
	char	*get;
	char	*aux;

	str = ft_strdup("");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		m_erro("Invalid file.\n");
	if (ft_strrncmp(".cub", argv[1], 4) != 0)
		m_erro("Invalid extension.\n");
	if (!ft_strrncmp(".cub", argv[1], 4))
	{
		while (1)
		{
			get = get_next_line(fd);
			if (!get)
				break ;
			aux = str;
			str = ft_strjoin_(str, get);
			free(aux);
			free(get);
		}
	}
	return (ft_split(str, '\n'));
}

void	get_pos(char **valid_map, t_map *map)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	size = 0;
	while (valid_map[j])
	{
		i = -1;
		while (valid_map[j][++i])
		{
			if (valid_map[j][i] == 'N' || valid_map[j][i] == 'E'
				|| valid_map[j][i] == 'S' || valid_map[j][i] == 'W')
			{
				map->pos_x = j;
				map->pos_y = i;
				get_direction(valid_map[j][i], map);
				valid_map[j][i] = '0';
				size++;
			}
		}
		j++;
	}
	if (size > 1)
		m_erro("Invalid player.\n");
}

void	get_direction(char player, t_map *map)
{
	map->dir_x = 0;
	map->dir_y = 1;
	if (player == 'N')
		set_direction(&map->dir_y, 1);
	else if (player == 'W')
		set_direction(&map->dir_x, -1);
	else if (player == 'E')
		set_direction(&map->dir_x, 1);
	else if (player == 'S')
		set_direction(&map->dir_y, -1);
	if (map->dir_x != 0)
	{
		map->plane_y = 0.66;
		map->plane_x = 0;
	}
	else
	{
		map->plane_y = 0;
		map->plane_x = 0.66;
	}
}

void	fill_map(char **map, t_map *mapa)
{
	char	**new;
	size_t	i;
	int		j;

	new = malloc((mapa->lines + 3) * sizeof(char **));
	j = 0;
	i = 0;
	new[i] = ft_strdup(map[0]);
	while (new[i][j])
	{
		new[i][j] = '3';
		j++;
	}
	j = 0;
	while (i < mapa->lines)
		new[++i] = ft_strdup(map[j++]);
	new[++i] = ft_strdup(map[0]);
	j = -1;
	while (new[i][++j])
		new[i][j] = '3';
	new[++i] = NULL;
	map_border(new, mapa);
	fill_walls(new, 0, 0, mapa);
}

void	fill_walls(char **map, int row, int col, t_map *info)
{
	int	y;
	int	x;

	y = (int)info->lines + 2;
	x = (int)info->columns + 2;
	{
		if ((row < 0 || col < 0 || row >= y || col >= x)
			|| (map[row][col] != '3' && map[row][col] != '0'))
			return ;
		if (map[row][col] == '0')
			m_erro("Not closed by walls.\n");
		map[row][col] = '2';
		fill_walls(map, row + 1, col, info);
		fill_walls(map, row, col + 1, info);
		fill_walls(map, row - 1, col, info);
		fill_walls(map, row, col - 1, info);
	}
}
