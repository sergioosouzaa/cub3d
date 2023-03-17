/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:12 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/14 19:11:45 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	**creating_map(char **valid_map, t_map *map)
{
	int		i;
	int		j;
	int		size;
	char	**new_map;

	i = 0;
	j = 0;
	size = 0;
	(void)map;
	if (!valid_map[i])
		m_erro("");
	while (valid_map[i] != NULL)
		i++;
	while (is_map(valid_map[j]) == 1)
		j++;
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
