
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

void	get_sprites(t_game *game)
{
	game->img_1.img = mlx_xpm_file_to_image(game->mlx, "./sprits/Wood.xpm", &game->size_txt, &game->size_txt);
	game->img_1.addr = mlx_get_data_addr(game->img_1.img, &game->img_1.bits_per_pixel, &game->img_1.line_length,
							&game->img_1.endian);
	game->img_2.img = mlx_xpm_file_to_image(game->mlx, "./sprits/Circle.xpm", &game->size_txt, &game->size_txt);
	game->img_2.addr = mlx_get_data_addr(game->img_2.img, &game->img_2.bits_per_pixel, &game->img_2.line_length,
							&game->img_2.endian);
	game->img_3.img = mlx_xpm_file_to_image(game->mlx, "./sprits/Yellow.xpm", &game->size_txt, &game->size_txt);
	game->img_3.addr = mlx_get_data_addr(game->img_3.img, &game->img_3.bits_per_pixel, &game->img_3.line_length,
							&game->img_3.endian);
	game->img_4.img = mlx_xpm_file_to_image(game->mlx, "./sprits/Brick.xpm", &game->size_txt, &game->size_txt);
	game->img_4.addr = mlx_get_data_addr(game->img_4.img, &game->img_4.bits_per_pixel, &game->img_4.line_length,
							&game->img_4.endian);
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