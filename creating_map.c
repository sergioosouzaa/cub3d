/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:12 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/13 18:36:13 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_map(char **old_map, int size, t_map *map)
{
	int		j;
	char	*str;

	j = 0;
	while (j < size)
	{
		str = old_map[j];
		if (!ft_strncmp("NO", str, 2))
			map->north = ft_substr(str, ft_ispace(str), still_space(str));
		else if (!ft_strncmp("SO", str, 2))
			map->south = ft_substr(str, ft_ispace(str), still_space(str));
		else if (!ft_strncmp("EA", str, 2))
			map->east = ft_substr(str, ft_ispace(str), still_space(str));
		else if (!ft_strncmp("WE", str, 2))
			map->west = ft_substr(str, ft_ispace(str), still_space(str));
		else if (!ft_strncmp("F ", str, 1))
			map->floor = ft_substr(str, ft_ispace(str), still_space(str));
		else if (!ft_strncmp("C ", str, 1))
			map->ceiling = ft_substr(str, ft_ispace(str), still_space(str));
		j++;
	}
	check_files(map);
}

void	check_files(t_map *map)
{
	int	fd;

	fd = open(map->north, O_RDONLY);
	if (fd < 0)
		m_erro("Texture doesn't exist.");
	fd = open(map->south, O_RDONLY);
	if (fd < 0)
		m_erro("Texture doesn't exist.");
	fd = open(map->west, O_RDONLY);
	if (fd < 0)
		m_erro("Texture doesn't exist.");
	fd = open(map->east, O_RDONLY);
	if (fd < 0)
		m_erro("Texture doesn't exist.");
}

char	**creating_map(char **valid_map, t_map *map)
{
	int		i;
	int		j;
	int		size;
	char	**new_map;

	i = 0;
	j = 0;
	size = 0;
	if (!valid_map[i])
		m_erro("");
	while (valid_map[i] != NULL)
		i++;
	while (is_map(valid_map[j]) == 1)
		j++;
	check_map(valid_map, j, map);
	new_map = (char **)malloc((i - j + 1) * sizeof(char *));
	while (valid_map[j])
	{
		new_map[size] = ft_substr(valid_map[j], 0, ft_strlen(valid_map[j]));
		size++;
		j++;
	}
	new_map[size] = NULL;
	return (new_map);
}

void	get_mapsize(char **str, t_map *map)
{
	int	i;
	int	j;
	int	columns;

	i = 0;
	j = 0;
	columns = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
			i++;
		if (i > columns)
			columns = i;
		j++;
	}
	map->lines = j;
	map->columns = columns;
}
