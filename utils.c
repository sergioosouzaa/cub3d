#include "cube.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int get_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void	print_floor(t_data *img, int floor_color, int ceiling_color)
{
	int i;
	int	j;
	i = 0;
	j = 0;
	while (i < screenWidth)
	{
		j = 0;
		while (j < screenHeight)
		{
			if (j < (screenHeight / 4) * 3)
				my_mlx_pixel_put(img, i, j, floor_color);
			else
				my_mlx_pixel_put(img, i, j, ceiling_color);
			j++;
		}
		i++;
	}
}

void	get_sprites(t_map *map, t_game *game)
{
	game->img_NO.img = mlx_xpm_file_to_image(game->mlx, map->NO, &game->size_txt, &game->size_txt);

	game->img_NO.addr = mlx_get_data_addr(game->img_NO.img, &game->img_NO.bits_per_pixel, &game->img_NO.line_length,
							&game->img_NO.endian);
	game->img_SO.img = mlx_xpm_file_to_image(game->mlx, map->SO, &game->size_txt, &game->size_txt);
	game->img_SO.addr = mlx_get_data_addr(game->img_SO.img, &game->img_SO.bits_per_pixel, &game->img_SO.line_length,
							&game->img_SO.endian);
	game->img_WE.img = mlx_xpm_file_to_image(game->mlx, map->WE, &game->size_txt, &game->size_txt);
	game->img_WE.addr = mlx_get_data_addr(game->img_WE.img, &game->img_WE.bits_per_pixel, &game->img_WE.line_length,
							&game->img_WE.endian);
	game->img_EA.img = mlx_xpm_file_to_image(game->mlx, map->EA, &game->size_txt, &game->size_txt);
	game->img_EA.addr = mlx_get_data_addr(game->img_EA.img, &game->img_EA.bits_per_pixel, &game->img_EA.line_length,
							&game->img_EA.endian);
}

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	*str1;
	size_t			size_s1;
	size_t			size_s2;

	str = (unsigned char *) s1;
	str1 = (unsigned char *) s2;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (n == 0)
		return (0);
	i = 0;
	while (n--)
	{
		if (str[size_s1] != str1[size_s2])
			return (str[size_s1] - str1[size_s2]);
		size_s1--;
		size_s2--;
	}
	return (0);
}

void	m_erro(char *message)
{
	ft_printf("Error\n%s", message);
	exit(0);
}

int		is_map(char *map)
{
	if ((!ft_strncmp("NO", map, 2)) || (!ft_strncmp("SO", map, 2)) || (!ft_strncmp("EA", map, 2)) \
	|| (!ft_strncmp("F ", map, 2)) || (!ft_strncmp("C ", map, 2)) || (!ft_strncmp("WE", map, 2)) \
       || (!ft_strncmp("", map, ft_strlen(map))))
		return (1);
	else
		return (0);
}

void	init_map(t_map *map)
{
	map->C = 0;
	map->EA = 0;
	map->dir_x = 0;
	map->dir_y = 0;
	map->NO = 0;
	map->WE = 0;
	map->SO = 0;
	map->F = 0;
}
	
int	exit_close(void)
{
	exit(0);
	return (0);
}