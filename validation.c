#include "cube.h"

void	invalid_map(char **new_map, t_map *map)
{
	invalid_char(new_map);
	get_mapsize(new_map, map);
}

char    **get_map(char **argv)
{
	int		fd;
	int		i;
	char	*str;
	char	*get;

	str = ft_strdup("");
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		m_erro("Invalid file.\n");
	if (ft_strrncmp(".cub", argv[1], 4) != 0)
	{
		m_erro("Invalid extension.\n");
		return NULL;
	}
	if (!ft_strrncmp(".cub", argv[1], 4))
	{
		while (1)
		{
			get = get_next_line(fd);
			if (!get)
				break ;
			str = ft_strjoin_(str, get);
		}
	}
	return (ft_split(str, '\n'));
}

void	invalid_char(char **str_map)
{
	int	i;
	int	j;

	j = 0;
	while (str_map[j])
	{
		i = 0;
		while (str_map[j][i])
		{
			if (!ft_strchr("01NS EW", str_map[j][i]))
				m_erro("Invalid char.\n");
			i++;
		}
		j++;
	}
}

void	get_pos(char **valid_map, t_map *map)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = 0;
	while(valid_map[j])
	{	
		i = 0;
		while(valid_map[j][i])
		{
			if (valid_map[j][i] == 'N' || valid_map[j][i] == 'E' ||valid_map[j][i] == 'S' || valid_map[j][i] == 'W')
			{
				map->pos_x = i;
				map->pos_y = j;
				map->plane_x = 0.0;
				map->plane_y = 0.66;
				get_direction(valid_map[j][i], map);
				size++;
			}
			i++;
		}
	j++;
	}
	if (size > 1)
		m_erro("Invalid player.\n");
}

void	invalid_config(t_map *map)
{
	if ((!map->SO) || (!map->NO) || (!map->WE) || (!map->EA) || (!map->C) || (!map->F) || (!map->pos_x) || (!map->pos_y))
		m_erro("Map configuration\n");
}

void	get_direction(char player, t_map *map)
{
	if (player == 'N')
	{
		map->dir_x = 0;
		map->dir_y = 1;
	}
	else if (player == 'W')
	{
		map->dir_x = -1;
		map->dir_y = 0;
	}
	else if (player == 'E')
	{
		map->dir_x = 1;
		map->dir_y = 0;
	}
	else if (player == 'S')
	{
		map->dir_x = 0;
		map->dir_y = -1;
	}
}
