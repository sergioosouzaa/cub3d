/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:44 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/17 19:25:30 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_map(char *map)
{
	if ((!ft_strncmp("NO", map, 2)) || (!ft_strncmp("SO", map, 2))
		|| (!ft_strncmp("EA", map, 2)) || (!ft_strncmp("F ", map, 2))
		|| (!ft_strncmp("C ", map, 2)) || (!ft_strncmp("WE", map, 2))
		|| (!ft_strncmp("\n", map, 2) || (!ft_strncmp("\t", map, 1))))
		return (1);
	else
		return (0);
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
			if (!ft_strchr("01NS EW9", str_map[j][i]))
				m_erro("Invalid char.\n");
			i++;
		}
		j++;
	}
}

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str1;
	size_t			size_s1;
	size_t			size_s2;

	str = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (n == 0)
		return (0);
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

int	exit_close(t_game *game)
{
	int	i;

	i = 0;
	system("killall afplay");
	while (i < (int)game->map.lines)
	{
		free(game->world_map[i]);
		i++;
	}
	free(game->world_map);
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_image(game->mlx, game->img_east.img);
	mlx_destroy_image(game->mlx, game->img_north.img);
	mlx_destroy_image(game->mlx, game->img_south.img);
	mlx_destroy_image(game->mlx, game->img_west.img);
	mlx_clear_window(game->mlx, game->mlx_win);
	exit(0);
	return (0);
}
