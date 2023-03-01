#include "cube.h"
#include <stdio.h>

void    check_map(char **old_map, int size, t_map *map)
{
    int j;
 
    j = 0;
    while(j < size)
    {
	    if (!ft_strncmp("NO", old_map[j], 2))
            map->NO = ft_substr(old_map[j], 2, ft_strlen(old_map[j]));
        else if (!ft_strncmp("SO", old_map[j], 2))
            map->SO = ft_substr(old_map[j], 2, ft_strlen(old_map[j]));
        else if (!ft_strncmp("EA", old_map[j], 2))
            map->EA = ft_substr(old_map[j], 2, ft_strlen(old_map[j]));
        else if (!ft_strncmp("WE", old_map[j], 2))
            map->WE = ft_substr(old_map[j], 2, ft_strlen(old_map[j]));     
        else if (!ft_strncmp("F ", old_map[j], 2))
            map->F = ft_substr(old_map[j], 2, ft_strlen(old_map[j]));
        else if (!ft_strncmp("C ", old_map[j], 2))
            map->C = ft_substr(old_map[j], 2, ft_strlen(old_map[j]));
        j++;
    }
}

char    **creating_map(char **valid_map, t_map *map)
{
    int     i;
    int     j;
    int		size;
    char    **new_map;

	i = 0;
	j = 0;
	size = 0;
    if (!valid_map[i])
        m_erro("");
    while(valid_map[i])
        i++;
	while (is_map(valid_map[j]) == 1)
        j++;
    check_map(valid_map, j, map);
    new_map = (char **)malloc((i - j) * sizeof(char *));
    while(valid_map[j])
    {
        new_map[size] = ft_substr(valid_map[j], 0, ft_strlen(valid_map[j]));
        size++;
        j++;
    }
    new_map[size] = NULL;
    return (new_map);
}