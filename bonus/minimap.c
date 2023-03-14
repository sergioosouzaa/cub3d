#include "cube.h"

/* função sprite */
void draw_square(int x_screen, int y_screen, int color, int title_size, t_game game)
{
	int i;
	int j;

	i = 0;
	while (i < title_size)
	{
		j = 0;
		while (j < title_size)
		{
			my_mlx_pixel_put(&game.img, (x_screen + i), screenHeight - (y_screen + j), color);
			j++;
		}
		i++;
	}
}

/* função minimap */

int     get_title_size(void)
{
	int	max_side;
	int	side;
    int	title_size;


	if (mapHeight > mapWidth)
	{
		max_side = mapHeight;
		side = 0.2 * screenHeight;
	}
	else
	{
		max_side = mapWidth;
		side = 0.2 * screenWidth;
	}
	title_size = side / max_side;
    return (title_size);
}

void    put_pic_minimap(t_game game)
{
	int y;
	int x;
    int	y_screen;
	int x_screen;

    x = 0;
    x_screen = screenWidth - (mapWidth * get_title_size());
    while (x < mapWidth)
	{
		y = 0;
		y_screen = screenHeight - (mapHeight * get_title_size());
		while (y < mapHeight)
		{
			if (x == (int)game.sprites[1].pos_x && y == (int)game.sprites[1].pos_y)
                mlx_put_image_to_window(game.mlx, game.mlx_win, game.sprites[1].texture_3.img, \
                x_screen, screenHeight - y_screen - get_title_size() * 1.5);
			else if (x == (int)game.sprites[0].pos_x && y == (int)game.sprites[0].pos_y)
                mlx_put_image_to_window(game.mlx, game.mlx_win, game.minimap.img, x_screen, \
                screenHeight - y_screen - get_title_size() * 1.5);
			y_screen += get_title_size();
			y++;
		}
		x_screen += get_title_size();
		x++;
	}
}

void	draw_minimap(t_game game)
{
	int	y_screen;
	int x_screen;
	int color;
	int y;
	int x;

	x = 0;
	x_screen = screenWidth - (mapWidth * get_title_size());
	while (x < mapWidth)
	{
		y = 0;
		y_screen = screenHeight - (mapHeight * get_title_size());
		while (y < mapHeight)
		{
			if (worldMap[x][y] >= 1)
				color = 0x474564;
			if (worldMap[x][y] < 1 || (worldMap[x][y] == 9 && \
            game.doors[0].mode == 4))
				color = 0x00CACACA;
			draw_square(x_screen, y_screen, color, get_title_size(), game);
			y_screen += get_title_size();
			y++;
		}
		x_screen += get_title_size();
		x++;
	}
}