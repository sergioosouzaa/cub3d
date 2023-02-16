
#include<stdio.h>
#include "cube.h"
#include "./minilibx/mlx.h"
#include <math.h>
#include <unistd.h>


#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int get_color(t_data *data, int x, int y)
{
    char	*dst;

	  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    return (*(unsigned int*)dst);
}

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

int main(void)
{
  double posX = 22.0, posY = 11.5;  //x and y start position
  double dirX = -1.0, dirY = 0.0; //initial direction vector
  double planeX = 0.0, planeY = 0.66; //the 2d raycaster version of camera plane


    void *mlx = mlx_init();
    void *mlx_win = mlx_new_window(mlx, screenWidth, screenWidth, "window");
    int w = screenWidth;
    int h = screenHeight;
  	t_data	img;
	  img.img = mlx_new_image(mlx, screenWidth, screenWidth);
	  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
      int size_txt = texWidth;
      t_data img_1;
      img_1.img = mlx_png_file_to_image(mlx, "./sprits/eagle.png", &size_txt, &size_txt);
	    img_1.addr = mlx_get_data_addr(img_1.img, &img_1.bits_per_pixel, &img_1.line_length,
								&img_1.endian);
      t_data img_2;
      img_2.img = mlx_png_file_to_image(mlx, "./sprits/redbrick.png", &size_txt, &size_txt);
	    img_2.addr = mlx_get_data_addr(img_2.img, &img_2.bits_per_pixel, &img_2.line_length,
								&img_2.endian);
      t_data img_3;
      img_3.img = mlx_png_file_to_image(mlx, "./sprits/purplestone.png", &size_txt, &size_txt);
	    img_3.addr = mlx_get_data_addr(img_3.img, &img_3.bits_per_pixel, &img_3.line_length,
								&img_3.endian);
      t_data img_4;
      img_4.img = mlx_png_file_to_image(mlx, "./sprits/purplestone.png", &size_txt, &size_txt);
	    img_4.addr = mlx_get_data_addr(img_4.img, &img_4.bits_per_pixel, &img_4.line_length,
								&img_4.endian);
      t_data img_5;
      img_5.img = mlx_png_file_to_image(mlx, "./sprits/bluestone.png", &size_txt, &size_txt);
	    img_5.addr = mlx_get_data_addr(img_5.img, &img_5.bits_per_pixel, &img_5.line_length,
								&img_5.endian);
      t_data img_6;
      img_6.img = mlx_png_file_to_image(mlx, "./sprits/mossy.png", &size_txt, &size_txt);
	    img_6.addr = mlx_get_data_addr(img_6.img, &img_6.bits_per_pixel, &img_6.line_length,
								&img_6.endian);
      t_data img_7;
      img_7.img = mlx_png_file_to_image(mlx, "./sprits/wood.png", &size_txt, &size_txt);
	    img_7.addr = mlx_get_data_addr(img_7.img, &img_7.bits_per_pixel, &img_7.line_length,
								&img_7.endian);
      t_data img_8;
      img_8.img = mlx_png_file_to_image(mlx, "./sprits/colorstone.png", &size_txt, &size_txt);
	    img_8.addr = mlx_get_data_addr(img_8.img, &img_8.bits_per_pixel, &img_8.line_length,
								&img_8.endian);

    for(int x = 0; x < w; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
      double rayDirX = dirX + planeX*cameraX;
      double rayDirY = dirY + planeY*cameraX;

      //which box of the map we're in
      int mapX = (int)posX;
      int mapY = (int)posY;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

      //length of ray from one x or y-side to next x or y-side
      double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?

      //calculate step and initial sideDist
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if(worldMap[mapX][mapY] > 0) hit = 1;
      }

      //Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(h / perpWallDist);


      int pitch = 100;

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
      else          wallX = posX + perpWallDist * rayDirX;
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
      for(int y = drawStart; y < drawEnd; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        unsigned int color = get_color(&texture, texHeight * texX, texHeight * texY);

        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(side == 1) color = (color >> 1) & 8355711;
        my_mlx_pixel_put(&img, y, x, color);
      }
    }


      mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
        mlx_loop(mlx);
}
