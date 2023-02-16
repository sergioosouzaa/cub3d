#ifndef CUBE_H
# define CUBE_H

# include "./minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct cube
{	
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double sidedist_y;
	double deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		map_x;
	int		map_y;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	//double time = 0;
	//double oldTime = 0; 

} t_cube;
#endif