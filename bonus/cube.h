#ifndef CUBE_H
# define CUBE_H

# include "./minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>

#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define rot 0.05	
#define vMove 80
enum	mac_e_key_codes
{
	KEY_DOWN = 125,
	KEY_UP = 126,
	KEY_ESC = 53,
	KEY_RIGHT = 123,
	KEY_LEFT = 124,
	KEY_SPACE = 49,
	KEY_SHIFT = 57,
	KEY_RESET = 15,
};


typedef	struct s_draw_sprites
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x; 
	double	transform_y; 
	int		sprite_screen_x; 
	int		v_move;
	int		sprite_height;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		draw_start_x;
	int		draw_end_x;
	int		tex_x;
	int		tex_y;
	int		d;
	int		color;			
} 				t_draw;

typedef	struct s_keys {
	int up;
	int	down;
	int	esc;
	int	rotate_r;
	int	rotate_l;
	int	space;
	int	shift;
}				t_keys;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef	struct s_sprite
{
	double	pos_x;
	double	pos_y;
	int		sprite;
	int		u_div;
	int		v_div;
	double	dir_x;
	double	dir_y;
	int		hp;
	t_data	*texture;
	t_data	texture_1;
	t_data	texture_2;
	t_data	texture_3;
	t_data	texture_4;
}   t_sprite;

typedef struct s_char
{
	t_data	*texture;
	t_data	txt1;
	t_data	txt2;
	t_data	txt3;
	t_data	txt4;
}	t_char;

typedef struct	s_map {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_map;

typedef struct 	s_door {
	int	pos_x;
	int	pos_y;
	int	mode;
	long long first_time;
	double	x;
} t_door;

typedef	struct	s_game {
	int			floor_color;
	int			ceiling_color;
	void		*mlx;
	void		*mlx_win;
	int			size_txt;
	long long	first_time;
	int			mode;
	double		speed;
	int			char_select;
	int			door_num;
	t_door		*doors;
	t_char		my_char;
	t_data		*menu;
	t_data		img;
	t_data		img_1;
	t_data		img_2;
	t_data		img_3;
	t_data		img_4;
	t_data		door;
	t_data		minimap;
	t_map		map;
	t_keys		key;
	t_sprite	*sprites;
	int			sprite_num;
	long long	time;
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
	int				door;
	t_data			texture;
}				t_ray;


/* 								Utils 								*/

void			get_sprites(t_game *game);



t_data	get_texture(t_ray  ray, t_game game);
void	dda(t_ray *ray, t_game game);
void	side_dist_init(t_ray *ray, t_map map);
void	calc_texture(t_ray *ray, t_game game);
void	ray_init(t_ray *ray, t_game game, int x);
void	raycast(t_game game);
void	 cpy_img(t_game *game);

void	put_img( t_game game);

//int	hsv_to_rgb(float h, float s, float v);
int	hsv_to_rgb(int hue, double saturation, double value);




/*    					Time Utils 						*/

long long	time_return(long long first_time);
long long	get_first_time(void);
void		initialize_chaos(void);


void create_sprites(t_game *game);
void game_init(t_game *game, t_map pos);


void	display_menu(t_game *game);
void	open_menu(t_game *game);
int		handle_menu(t_game *game);


int worldMap[mapWidth][mapHeight];
t_data	get_texture(t_ray  ray, t_game game);


//if in front of door return the door index, if not in front of any door return -1;

int handle_doors(t_game *game);
int    get_door_index(t_game *game, int x, int y);
int    check_doors(t_game *game);


/* Open char Select */

void			open_char_select(t_game *game);
void			open_luigi(t_game *game);
void			open_peach(t_game *game);
void			handle_char_select(t_game *game);


/* Image Utils */

void			open_image(t_data *img_ptr, char *path, t_game *game);
unsigned int	get_color(t_data *data, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* Controls */

void			display_controls(t_game *game);
void			handle_controls(t_game *game);


int				handle_press(int key, t_game *game);
int				handle_release(int key, t_game *game);
t_keys			init_keys(void);
void	open_image_size(t_data *img_ptr, char *path, t_game *game, int size);
char	*ft_itoa(int n);


void	calc_texture(t_ray *ray, t_game game);
void	ray_init(t_ray *ray, t_game game, int x);
void	side_dist_init(t_ray *ray, t_map map);
void 	door_dda(t_ray *ray, t_game game);
void	dda(t_ray *ray, t_game game);



// sprites

void    organize(t_game *game, int *sprite_order, int *sprite_distance);
void	calc_end_start(t_draw *sprites, int *sprite_order, t_game *game, int i);
void	init_sprites(t_game *game, int *sprite_order, int i, t_draw *sprites);
void	put_sprites(t_draw *sprites, t_game *game, int i, int *z_buffer);
void	draw_sprites(int *z_buffer, t_game *game);

void	sort_sprites(int *sprite_order, int *sprite_dist, int sprite_num);
void	sort_order(int *sprite_order, int size);

void	draw_minimap(t_game game);
void    put_pic_minimap(t_game game);


#endif