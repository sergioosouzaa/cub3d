
#include "cube.h"


int worldMap[mapWidth][mapHeight]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};


t_map	get_pos(void)
{
	t_map map;

	map.pos_x = 10.0;
	map.pos_x = 9.0;
	map.dir_x = -1.0;
	map.dir_y = 0.0;
	map.plane_x = 0.0;
	map.plane_y = 0.66;
	return (map);
}

void	get_sprites(t_game *game)
{
	game->img_1.img = mlx_xpm_file_to_image(game->mlx, "./sprits/eagle.xpm", &game->size_txt, &game->size_txt);
	game->img_1.addr = mlx_get_data_addr(game->img_1.img, &game->img_1.bits_per_pixel, &game->img_1.line_length,
							&game->img_1.endian);
	game->img_2.img = mlx_xpm_file_to_image(game->mlx, "./sprits/redbrick.xpm", &game->size_txt, &game->size_txt);
	game->img_2.addr = mlx_get_data_addr(game->img_2.img, &game->img_2.bits_per_pixel, &game->img_2.line_length,
							&game->img_2.endian);
	game->img_3.img = mlx_xpm_file_to_image(game->mlx, "./sprits/purplestone.xpm", &game->size_txt, &game->size_txt);
	game->img_3.addr = mlx_get_data_addr(game->img_3.img, &game->img_3.bits_per_pixel, &game->img_3.line_length,
							&game->img_3.endian);
	game->img_4.img = mlx_xpm_file_to_image(game->mlx, "./sprits/purplestone.xpm", &game->size_txt, &game->size_txt);
	game->img_4.addr = mlx_get_data_addr(game->img_4.img, &game->img_4.bits_per_pixel, &game->img_4.line_length,
							&game->img_4.endian);
	game->img_5.img = mlx_xpm_file_to_image(game->mlx, "./sprits/bluestone.xpm", &game->size_txt, &game->size_txt);
	game->img_5.addr = mlx_get_data_addr(game->img_5.img, &game->img_5.bits_per_pixel, &game->img_5.line_length,
							&game->img_5.endian);
	game->img_6.img = mlx_xpm_file_to_image(game->mlx, "./sprits/mossy.xpm", &game->size_txt, &game->size_txt);
	game->img_6.addr = mlx_get_data_addr(game->img_6.img, &game->img_6.bits_per_pixel, &game->img_6.line_length,
							&game->img_6.endian);
	game->img_7.img = mlx_xpm_file_to_image(game->mlx, "./sprits/wood.xpm", &game->size_txt, &game->size_txt);
	game->img_7.addr = mlx_get_data_addr(game->img_7.img, &game->img_7.bits_per_pixel, &game->img_7.line_length,
							&game->img_7.endian);
	game->img_8.img = mlx_xpm_file_to_image(game->mlx, "./sprits/colorstone.xpm", &game->size_txt, &game->size_txt);
	game->img_8.addr = mlx_get_data_addr(game->img_8.img, &game->img_8.bits_per_pixel, &game->img_8.line_length,
							&game->img_8.endian);
}

void	handle_key(void *game)
{


}

void	side_dist_init(t_ray *ray, t_map map)
{
	if(ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (map.pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - map.pos_x) * ray->deltadist_x;
	}
	if(ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (map.pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - map.pos_y) * ray->deltadist_y;
	}
}

void	dda(t_ray *ray)
{
	while (ray->hit == 0)
	{
		if(ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if(worldMap[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
	if(ray->side == 0)
		ray->perpwalldist = (ray->sidedist_x - ray->deltadist_x);
	else          
		ray->perpwalldist = (ray->sidedist_y - ray->deltadist_y);
}

void	raycast(t_game game)
{
	t_ray	ray;
	int		w; 
	int		h;
	int		x;
	
	h = screenHeight;
	w = screenWidth;
	x = 0;
	while (x < h)
	{
		ray.camera_x = 2 * x / (double)w - 1;
		ray.raydir_x = game.map.dir_x + game.map.plane_x * ray.camera_x;
		ray.raydir_y = game.map.dir_y + game.map.plane_y * ray.camera_x;;
		ray.map_x = (int)game.map.pos_x;
		ray.map_y = (int)game.map.pos_y;
		ray.hit = 0;
		if (ray.raydir_x == 0)
			ray.deltadist_x = 1e30;
		else
			ray.deltadist_x = fabs( 1 / ray.raydir_x);
		if (ray.raydir_y == 0)
			ray.deltadist_y = 1e30;
		else
			ray.deltadist_y = fabs( 1 / ray.raydir_y);
		side_dist_init(&ray, game.map);
		dda(&ray);
		ray.line_heigh = (int)(h / ray.perpwalldist);
		ray.pitch = 100;
		
		x++;
	}
    for(int x = 0; x < w; x++)
    {
      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + h / 2 + pitch;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + h / 2 + pitch;
      if(drawEnd >= h) drawEnd = h - 1;

      //texturing calculations
        t_data texture;
        if (worldMap[mapX][mapY] - 1 == 0)
            texture = img_1;
        else if (worldMap[mapX][mapY] - 1 == 1)
            texture = img_2;   
        else if (worldMap[mapX][mapY] - 1 == 2)
            texture = img_3;   
        else if (worldMap[mapX][mapY] - 1 == 3)
            texture = img_4;               
        else if (worldMap[mapX][mapY] - 1 == 4)
            texture = img_5;   
        else if (worldMap[mapX][mapY] - 1 == 5)
            texture = img_6;   
        else if (worldMap[mapX][mapY] - 1 == 6)
            texture = img_7; 
        else //if (worldMap[mapX][mapY] - 1 == 7)
            texture = img_8;     
      double wallX; //where exactly the wall was hit
      if(side == 0) wallX = posY + perpWallDist * rayDirY;
      else          wallX = posX + perpWallDist * ray->raydir_x;
      wallX -= floor((wallX));

      //x coordinate on the texture
      int texX = (int)(wallX * (double)texWidth);
      if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
      if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

      // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
      // How much to increase the texture coordinate per screen pixel
      double step = 1.0 * texHeight / lineHeight;
      // Starting texture coordinate
      double texPos = (drawStart - pitch - h / 2 + lineHeight / 2) * step;
      printf("%d \n", drawStart);
      for(int y = drawStart; y < drawEnd; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        unsigned int color = get_color(&texture, texX, texY);

        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(side == 1) color = (color >> 1) & 8355711;
        my_mlx_pixel_put(&img, x, y, color);
      }
    }


      mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}

int main(void)
{
	t_map	pos;
	t_game	game;

	pos = get_pos();
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, screenWidth, screenWidth, "window");
	game.size_txt = texWidth;
	get_sprites(&game);
	game.img.img = mlx_new_image(game.mlx, screenWidth, screenWidth);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length,
								&game.img.endian);
	game.map = pos;
	raycast(game);
	mlx_key_hook(game.mlx_win, handle_key, &game);
	mlx_loop(game.mlx);			
}
