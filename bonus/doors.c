#include "cube.h"

int get_index(t_game *game)
{
    int i;

    i = 0;
    while (i< game->door_num)
    {
        if ((((game->doors[i].pos_x - (int)game->map.pos_x) * (game->doors[i].pos_x - (int)game->map.pos_x)) \
            +  (game->doors[i].pos_y - (int)game->map.pos_y) * (game->doors[i].pos_y - (int)game->map.pos_y)) < 9)
            return (i);
        i++;
    }
    return (-1);

}

int handle_doors(t_game *game)
{
    int i;
    int cur_door;

    i  = 0;
    cur_door = get_index(game);
    // printf("%d current_door \n",cur_door);
    while (i < game->door_num)
    {
        if ((game->doors[0].mode == 1 || game->doors[0].mode == 3 || game->doors[0].mode == 4) && i == cur_door)
        {
            game->doors[0].mode = 2;
            game->doors[0].first_time = get_first_time();
        }
        if (game->doors[0].mode == 2 && game->doors[0].x <= 0)
            game->doors[0].mode = 3;
        if (game->doors[0].mode == 2 && get_first_time() - game->doors[0].first_time > 100)
        {
            game->doors[0].first_time = get_first_time();
            game->doors[0].x = game->doors[0].x - 0.1;
        }
        if (game->doors[0].mode == 3 && i != cur_door)
        {
            game->doors[0].first_time = get_first_time();
            game->doors[0].mode = 4;
        }
        if (game->doors[0].mode == 4 && game->doors[0].x >= 1)
            game->doors[0].mode = 1;
        if (game->doors[0].mode == 4 && get_first_time() - game->doors[0].first_time > 100)
        {
            game->doors[0].x = game->doors[0].x + 0.1;
            game->doors[0].first_time = get_first_time();
        }
        // printf("%d %d %f\n", game->doors[i].mode, i, game->doors[i].x);
        i++;
    }
    return (0);
}

int    get_door_index(t_game *game, int x, int y)
{
    int i;

    i = 0;
    while (i < game->door_num)
    {
        if (x == game->doors[i].pos_x && y == game->doors[i].pos_y )
            return (i);
        i++;
    }

    return (0);
}