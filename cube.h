#ifndef CUBE_H
# define CUBE_H

# include "./minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>


#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

enum	mac_e_key_codes
{
	KEY_DOWN = 125,
	KEY_UP = 126,
	KEY_ESC = 53,
	KEY_RIGHT = 123,
	KEY_LEFT = 124,
	KEY_RESET = 15,
};


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_map {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_map;

typedef	struct	s_game {
	int		floor_color;
	int		ceiling_color;
	void	*mlx;
	void	*mlx_win;
	int		size_txt;
	t_data	img;
	t_data	img_1;
	t_data	img_2;
	t_data	img_3;
	t_data	img_4;
	t_data	img_5;
	t_data	img_6;
	t_data	img_7;
	t_data	img_8;
	t_map	map;
}				t_game;

typedef struct s_ray {
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	int				line_heigh;
	int				pitch;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
	unsigned int	color;
	t_data			texture;
}				t_ray;


/* 								Utils 								*/

unsigned int	get_color(t_data *data, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);


#endif