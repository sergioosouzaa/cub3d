#include "cube.h"

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

void	invalid_char(char **str_map, t_map *map)
{
	int	i;
	int	j;

	(void)map;
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

void	get_pos(char **valid_map)
{
	t_map	map;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = 0;
	while(valid_map[j])
	{	
		while ((!ft_strncmp("NO", valid_map[j], 2)) || (!ft_strncmp("SO", valid_map[j], 2)) || (!ft_strncmp("EA", valid_map[j], 2)) \
		|| (!ft_strncmp("F ", valid_map[j], 2)) || (!ft_strncmp("C ", valid_map[j], 2)) || (!ft_strncmp("WE", valid_map[j], 2)))
		{
			j++;
			size++;
		}
		i = 0;
		while(valid_map[j][i])
		{
			if (valid_map[j][i] == 'N' || valid_map[j][i] == 'E' ||valid_map[j][i] == 'S' || valid_map[j][i] == 'W')
			{
				map.pos_x = i;
				map.pos_y = j - size;
				map.dir_x = -1.0;
				map.dir_y = 0.0;
				map.plane_x = 0.0;
				map.plane_y = 0.66;
				printf("%f POS X\n", map.pos_x);
				printf("%f POS Y\n", map.pos_y);
			}
			i++;
		}
	j++;
	}
}


// void	is_walls(char **str_map, t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	rows;
// 	int	cols;

// 	i = 0;
// 	j = 0;
// 	rows = map->lines - 1;
// 	cols = map->column - 1;
// 	while (str_map[i][0] == '1' && str_map[i][cols] == '1' && i < rows)
// 		i++;
// 	while (str_map[0][j] == '1' && str_map[rows][j] == '1' && j <= cols)
// 		j++;
// 	if (i != rows || j - 1 != cols)
// 		m_erro("Invalid map: walls.\n");
// }