/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:01:56 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/19 19:50:25 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_hp(int x_screen, int y_screen, int color, t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			my_mlx_pixel_put(&game.img, (x_screen + i), SCREENHEIGHT \
			- (y_screen + j), color);
			j++;
		}
		i++;
	}
}

void	draw_health(t_game *game)
{
	int	hp;

	if(game->sprites[1].hp > 0)
	{
		hp = game->sprites[1].hp;
		while (hp > 0)
		{
			draw_hp((SCREENWIDTH / 2 - 100) + 20 * hp, \
			(SCREENHEIGHT - 50), 0x00FF0000, *game);
			hp--;
		}
	}
	if(game->sprites[0].hp > 0)
	{
		hp = game->sprites[0].hp;
		while (hp > 0)
		{
			draw_hp(5 + 20 * hp, (SCREENHEIGHT - 50), 0x0000FF00, *game);
			hp--;
		}
	}
}

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
