#ifndef CUBE_H
# define CUBE_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>


#define screenWidth 640
#define screenHeight 480
#define texWidth 256
#define texHeight 256
#define mapWidth 24
#define mapHeight 24
#define rot 0.08	
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
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
}				t_map;

typedef	struct	s_game {
	int		floor_color;
	int		ceiling_color;
	void	*mlx;
	void	*mlx_win;
	int		size_txt;
	t_data	img;
	t_data	img_NO;
	t_data	img_SO;
	t_data	img_WE;
	t_data	img_EA;
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
void			print_floor(t_data *img, int floor_color, int ceiling_color);

t_data	get_texture(t_ray  ray, t_game game);
void	dda(t_ray *ray);
void	side_dist_init(t_ray *ray, t_map map);
void	calc_texture(t_ray *ray, t_game game);
void	ray_init(t_ray *ray, t_game game, int x);
void	raycast(t_game game);
char    **get_map(char **argv);
int		ft_strrncmp(const char *s1, const char *s2, size_t n);
void	m_erro(char *message);
void	get_pos(char **old_map, t_map *map);
void	invalid_char(char **str_map);
char    **creating_map(char **valid_map, t_map *map);
int		is_map(char *map);
void    check_map(char **old_map, int size, t_map *map);
void	invalid_map(char **new_map, t_map *map);
void	invalid_config(t_map *map);
void	get_sprites(t_map *map, t_game *game);

int worldMap[mapWidth][mapHeight];

#endif