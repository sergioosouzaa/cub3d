#include "cube.h"

int main(int argc, char **argv)
{
    char    **map;
    if (argc == 2)
    {
        map = get_map(argv);
        get_pos(map);
    }
    else
        printf("Map not found!\n");
    return (0);
}