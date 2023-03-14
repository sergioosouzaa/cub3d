#include "cube.h"

void	sort_sprites(int *sprite_order, int *sprite_dist, int sprite_num)
{
	int	i;
	int aux;

	i = 0;
	while (i < sprite_num - 1)
	{
		if (sprite_dist[i] < sprite_dist[i + 1])
		{
			aux = sprite_order[i + 1];
			sprite_order[i + 1] = sprite_order[i];
			sprite_order[i] = aux;
			aux = sprite_dist[i + 1];
			sprite_dist[i + 1] = sprite_dist[i];
			sprite_dist[i] = aux;
			i = 0;
		}
		else
			i++;
	}
}

void	sort_order(int *sprite_order, int size)
{
	int	i;
	int	aux;

	i = 0;
	while (sprite_order[i] != 0)
		i++;
	while (i < size - 1)
	{
		aux = sprite_order[i];
		sprite_order[i] = sprite_order[i + 1];
		sprite_order[i + 1] = aux;
		i++;
	}
}
