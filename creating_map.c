#include "cube.h"

void    check_map(char **old_map, int size, t_map *map)
{
    int j;
    int i;
 
    j = 0;
    i = 0;
    while(j < size)
    {
	    if (!ft_strncmp("NO", old_map[j], 2))
            map->NO = ft_substr(old_map[j], ft_ispace(old_map[j], 2), ft_strlen(old_map[j]));
        else if (!ft_strncmp("SO", old_map[j], 2))
            map->SO = ft_substr(old_map[j], ft_ispace(old_map[j], 2), ft_strlen(old_map[j]));
        else if (!ft_strncmp("EA", old_map[j], 2))
            map->EA = ft_substr(old_map[j], ft_ispace(old_map[j], 2), ft_strlen(old_map[j]));
        else if (!ft_strncmp("WE", old_map[j], 2))
            map->WE = ft_substr(old_map[j], ft_ispace(old_map[j], 2), ft_strlen(old_map[j]));     
        else if (!ft_strncmp("F ", old_map[j], 1))
            map->F = ft_substr(old_map[j], ft_ispace(old_map[j], 1), ft_strlen(old_map[j]));
        else if (!ft_strncmp("C ", old_map[j], 1))
            map->C = ft_substr(old_map[j], ft_ispace(old_map[j], 1), ft_strlen(old_map[j]));
        j++;
    }
    check_files(map);
}

void    check_files(t_map *map)
{
    int fd;

    fd = open(map->NO, O_RDONLY);
    if (fd < 0)
        m_erro("Texture doesn't exist.");
    fd = open(map->SO, O_RDONLY);
    if (fd < 0)
        m_erro("Texture doesn't exist.");
    fd = open(map->WE, O_RDONLY);
    if (fd < 0)
        m_erro("Texture doesn't exist.");
    fd = open(map->EA, O_RDONLY);
    if (fd < 0)
        m_erro("Texture doesn't exist.");
}


int ft_ispace(char *str, int size)
{
    int i;

    i = size;
    while((str[i] == ' ') || (str[i] == '\t') || (str[i] > 'A' && str[i] < 'Z'))
        i++;
    return (i);
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

void    get_mapsize(char **str, t_map *map)
{
    int i;
    int j;
    int columns;

    i = 0;
    j = 0;
    columns = 0;
    while(str[j])
    {
        i = 0;
        while(str[j][i])
            i++;
        if (i > columns)
            columns = i;
        j++;
    }
    map->lines = j;
    map->columns = columns;
}