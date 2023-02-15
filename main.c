#include "cube.h"

char worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


t_cube  initialize_cube(void)
{
	t_cube	cube;

 	//pegar posição inicial e a direção
	cube.pos_x = 22;
	cube.pos_y = 12;
	cube.dir_x = -1;
	cube.dir_y = 0;

	return (cube);
}



void draw_line(int x, int start, int end, void *mlx, void *mlx_win)
{
	int y;

	y = start;
	while (y < end)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0xFF00FF);
		y++;
	}
}

void  game_loop(void *mlx, void *mlx_win, char worldMap[mapWidth][mapHeight])
{
	int	x;
	t_cube	cube;

	cube = initialize_cube();
	x = 0;
	while (x < screenWidth)
	{
		cube.camera_x = 2 * x / (double)screenWidth - 1;
		cube.raydir_x = cube.dir_x + cube.plane_x + cube.camera_x;
		cube.raydir_y = cube.dir_y + cube.plane_y * cube.camera_x;
		cube.map_x =  (int)cube.pos_x;
		cube.map_y = (int)cube.pos_y;
		if (cube.raydir_x == 0)
			cube.deltaDistX = 1e30;
		else
			cube.deltaDistX = fabs(1 / cube.raydir_x);
		if (cube.raydir_y == 0)
			cube.deltaDistY = 1e30;
		else
			cube.deltaDistY = fabs(1 / cube.raydir_y);
		cube.hit = 0;
		if (cube.raydir_x < 0)
		{
			cube.stepX = -1;
			cube.sidedist_x = (cube.pos_x - cube.map_x) * cube.deltaDistX;
		}
		else
		{
			cube.stepX = 1;
			cube.sidedist_x = (cube.map_x + 1.0 - cube.pos_x) * cube.deltaDistX;
		}
		if (cube.raydir_y < 0)
		{
			cube.stepY = -1;
			cube.sidedist_y = (cube.pos_y - cube.map_y) * cube.deltaDistY;
		}
		else
		{
			cube.stepY = 1;
			cube.sidedist_y = (cube.map_y + 1.0 - cube.pos_y) * cube.deltaDistY;
		}
		while (cube.hit == 0)
      	{
			if (cube.sidedist_x < cube.sidedist_y)
			{
			cube.sidedist_x += cube.deltaDistX;
			cube.map_x += cube.stepX;
			cube.side = 0;
			}
			else
			{
			cube.sidedist_y += cube.deltaDistY;
			cube.map_y += cube.stepY;
			cube.side = 1;
			}
			if (worldMap[cube.map_x][cube.map_y] > 0)
				cube.hit = 1;
      	}
		if(cube.side == 0) 
			cube.perpWallDist = (cube.sidedist_x - cube.deltaDistX);
      	else          
			cube.perpWallDist = (cube.sidedist_y - cube.deltaDistY);
		cube.lineHeight = (int)(screenHeight / cube.perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		cube.drawStart = -cube.lineHeight / 2 +screenHeight / 2;
		if(cube.drawStart < 0)
			cube.drawStart = 0;
		cube.drawEnd = cube.lineHeight / 2 +screenHeight / 2;
		if(cube.drawEnd >= screenHeight)
			cube.drawEnd = screenHeight - 1;
		draw_line(x, cube.drawStart, cube.drawEnd, mlx, mlx_win);
		x++;
	}
	while (1)
		;
}



int main (int argc, char **argv)
{
	//t_cube cube;
	
	(void)argv;
	if (argc == 2)
	{
		void	*mlx;
		void	*mlx_win;

		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, screenWidth, screenHeight, "Cub3d");
		game_loop(mlx, mlx_win, worldMap);
		//mlx_loop_hook(mlx, game, cube);
		//mlx_loop(mlx);
		mlx_destroy_window(mlx, mlx_win);
	}
	return (0);
}