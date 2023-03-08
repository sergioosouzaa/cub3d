#include "cube.h"


void	display_controls(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->menu[0].img, 0 , 0);
}

void	handle_controls(t_game *game)
{
    if (game->key.space == 1)
    {
        game->mode = 4;
		mlx_destroy_image(game->mlx, game->menu[0].img);
		free(game->menu);
    }
    game->key.space = 0;
}
