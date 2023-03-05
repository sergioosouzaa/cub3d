
#include "cube.h"

int main(int argc, char **argv)
{
	t_map	pos;
	t_game	game;
	char    **old_map;
    char    **new_map;
	if (argc == 2)
    {
		init_map(&pos);
        old_map = get_map(argv);
        new_map = creating_map(old_map, &pos);
        get_pos(new_map, &pos);
        invalid_map(new_map, &pos);
		game.world_map = new_map;
    	get_sprites(&pos, &game);
		invalid_config(&pos);
		color_rgb(pos.F, &game, 0);
		color_rgb(pos.C, &game, 1);
		game.key = init_keys();
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window(game.mlx, screenWidth, screenHeight, "window");
		game.size_txt = texWidth;
		game.img.img = mlx_new_image(game.mlx, screenWidth, screenHeight);
		game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length,
								&game.img.endian);
		game.map = pos;
		raycast(game);
		mlx_hook(game.mlx_win, 2, (1L<<0), &handle_press,  &game);
		mlx_hook(game.mlx_win, 3, (1L<<1), &handle_release,  &game);
		mlx_hook(game.mlx_win, 17, 1L << 17, exit_close, &game);
		mlx_loop_hook(game.mlx, &game_loop, &game);
		mlx_loop(game.mlx);				
	}
	else
		printf("Map not found\n");
}
