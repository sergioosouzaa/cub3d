
#include "cube.h"

int	handle_press(int key, t_game *game)
{

	if (key == KEY_LEFT)
		game->key.rotate_l = 1;
	if (key == KEY_RIGHT)	
		game->key.rotate_r = 1;
	if (key == KEY_DOWN)
		game->key.down = 1;
	if (key == KEY_UP)
		game->key.up = 1;
    if (key == KEY_ESC)
		game->key.esc = 1;
	return (0);
}

int handle_release(int key, t_game *game)
{
	if (key == KEY_LEFT)
		game->key.rotate_l = 0;
	if (key == KEY_RIGHT)	
		game->key.rotate_r = 0;
	if (key == KEY_DOWN)
		game->key.down = 0;
	if (key == KEY_UP)
		game->key.up = 0;
	if (key == KEY_ESC)
		game->key.esc = 0;
	return (0);
}

void	walk(t_game *game, int signal)
{
	game->map.pos_x = game->map.pos_x + (signal) * (game->map.dir_x * 0.05);
	game->map.pos_y = game->map.pos_y + (signal) * (game->map.dir_y * 0.05);
}

void	rotate(t_game *game, int signal)
{
	double aux;

	aux = game->map.dir_x;
	game->map.dir_x = game->map.dir_x * cos((signal)*(rot)) - game->map.dir_y * sin((signal)*(rot));
	game->map.dir_y = aux * sin((signal)*(rot)) + game->map.dir_y  * cos((signal)*(rot));
	aux = game->map.plane_x;
	game->map.plane_x = game->map.plane_x * cos((signal)*(rot)) - game->map.plane_y * sin((signal)*(rot));
	game->map.plane_y = aux * sin((signal)*(rot)) + game->map.plane_y * cos((signal)*(rot));
}

int	handle_key(t_game *game)
{
	if (game->key.down && game->key.down != game->key.up)
		walk(game, -1);
	if (game->key.up && game->key.down != game->key.up)
		walk(game, 1);
	if (game->key.rotate_l && game->key.rotate_l != game->key.rotate_r)
		rotate(game, -1);
	if (game->key.rotate_r && game->key.rotate_l != game->key.rotate_r)
		rotate(game, 1);
	if (game->key.esc)
		exit_close(game);
	return (0);
}

int	game_loop(t_game *game)
{
	handle_key(game);
	raycast(*game);
	return (0);
}

t_keys	init_keys(void)
{
	t_keys	key;

	key.up = 0;
	key.down = 0;
	key.esc = 0;
	key.rotate_r = 0;
	key.rotate_l = 0;
	return (key);
}
