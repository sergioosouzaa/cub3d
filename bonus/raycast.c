#include "cube.h"

char	*ft_itoa(int n);

int sky_color(void)
{
	int i;
	int	j;

	i = rand() % 2000;
	j = rand() % 7;
	if (i  == 10)
	{
		if (j == 0)
			return (0x9400D3);
		if (j == 1)
			return (0x4B0082);
		if (j == 2)
			return (0x0000FF);
		if (j == 3)
			return (0x00FF00);
		if (j == 4)
			return (0xFFFF00);
		if (j == 5)
			return (0xFF7F00);
		if (j == 6)
			return (0xFF0000);
	}
	return (0x00000000);
}

int floor_color(int y, int f)
{
	int j;
	int	h[7];

	h[0] = 0xf94144;
	h[1] = 0xf3722c;
	h[2] = 0xf8961e;
	h[3] = 0xf9844a;
	h[4] = 0xf9c74f;
	h[5] = 0x90be6d;
	h[6] = 0x43aa8b;
	j = ((y / 30));
	return (h[(f + j) % 7]);
}

int	return_f(void)
{
	static int f;
	static long long last_time;

	if (get_first_time() - last_time > 100)
	{
		f = (f + 1) % 7;
		last_time = get_first_time();
	}
	return (f);
}

void	raycast(t_game game)
{
	t_ray	ray;
	int		x;
	int		y;
	int		*perpedist;
	int		f;
	
	x = 0;
	f = return_f();
	perpedist = malloc(sizeof(int) * screenWidth);
	while (x < screenWidth)
	{
		ray_init(&ray, game, x);
		side_dist_init(&ray, game.map);
		dda(&ray, game);
		calc_texture(&ray, game);
		y = 0;
		while (y < screenHeight)
		{
			if (y < ray.draw_start)
				my_mlx_pixel_put(&game.img, x, y, sky_color());
			else if(y < ray.draw_end)
			{
				ray.tex_y = (int)ray.tex_pos;
				if (ray.tex_y > texHeight  - 1)
					ray.tex_y = texHeight  - 1;
				ray.tex_pos += ray.step;
				ray.color = get_color(&ray.texture,  ray.tex_x, ray.tex_y);
				if (ray.side == 1)
					ray.color = (ray.color >> 1) & 8355711;
				my_mlx_pixel_put(&game.img, x, y, ray.color);
			}
			else
				my_mlx_pixel_put(&game.img, x, y, floor_color(y, f));
			y++;
		}
		perpedist[x] = ray.perpwalldist;
		x++;
	}
	draw_sprites(perpedist, &game);
	draw_minimap(game);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img.img, 0, 0);
	put_pic_minimap(game);
	free(perpedist);
}



//VAI ESTAR NA LIBFT

static size_t	count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*numb(char *s, unsigned int n, size_t len)
{
	while (n > 0)
	{
		s[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	d;

	d = count(n);
	str = malloc(d + 1 * sizeof (char));
	if (!str)
		return (NULL);
	str[d--] = '\0';
	if (n < 0)
	{	
		n *= (-1);
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	str = numb(str, n, d);
	return (str);
}

