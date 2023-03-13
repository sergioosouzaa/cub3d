/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:20 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/13 18:36:20 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CUBE_H
# define CUBE_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <fcntl.h>

# define SCREENWIDTH 640
# define SCREENHEIGHT 480
# define TEXWIDTH 256
# define TEXHEIGHT 256
# define ROT 0.08

enum e_mac_e_key_codes
{
	KEY_DOWN = 125,
	KEY_UP = 126,
	KEY_ESC = 53,
	KEY_RIGHT = 123,
	KEY_LEFT = 124,
	KEY_RESET = 15,
};

typedef struct s_keys
{
	int	up;
	int	down;
	int	esc;
	int	rotate_r;
	int	rotate_l;
}	t_keys;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	size_t	lines;
	size_t	columns;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}	t_map;

typedef struct s_game
{
	int				floor_color;
	int				ceiling_color;
	void			*mlx;
	void			*mlx_win;
	int				size_txt;
	unsigned long	color_r;
	unsigned long	color_g;
	unsigned long	color_b;
	char			**world_map;
	t_data			img;
	t_data			img_north;
	t_data			img_south;
	t_data			img_west;
	t_data			img_east;
	t_map			map;
	t_keys			key;
}	t_game;

typedef struct s_ray
{
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
}	t_ray;

/* 								Utils 								*/

unsigned int	get_color(t_data *data, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			print_floor(t_data *img, int floor_color, int ceiling_color);
t_data			get_texture(t_ray ray, t_game game);
void			dda(t_ray *ray, t_game game);
void			side_dist_init(t_ray *ray, t_map map);
void			calc_texture(t_ray *ray, t_game game);
void			ray_init(t_ray *ray, t_game game, int x);
void			raycast(t_game game);
char			**get_map(char **argv);
int				ft_strrncmp(const char *s1, const char *s2, size_t n);
void			m_erro(char *message);
void			get_pos(char **old_map, t_map *map);
void			invalid_char(char **str_map);
char			**creating_map(char **valid_map, t_map *map);
int				is_map(char *map);
void			check_map(char **old_map, int size, t_map *map);
void			invalid_map(char **new_map, t_map *map);
void			invalid_config(t_map *map);
void			get_sprites(t_map *map, t_game *game);
void			init_map(t_map *map, char **argv, t_map *pos, t_game *game);
int				exit_close(t_game *game);
int				ft_ispace(char *str);
void			check_files(t_map *map);
void			get_direction(char player, t_map *map);
void			get_mapsize(char **str, t_map *map);
void			create_rgb(int *rgb, t_game *game, int var);
unsigned long	color_b(int nbr);
unsigned long	color_g(int nbr);
unsigned long	color_r(int nbr);
void			color_rgb(char *str, t_game *game, int var);
size_t			still_space(char *str);
void			is_walls(char **str_map, t_map *map);
void			all_walls(char **str_map, t_map *map);
void			changing_map(char **new_map, t_map *map);
void			fill_map(char **map, t_map *mapa);
void			fill_walls(char **map, int row, int col, t_map *info);
int				handle_press(int key, t_game *game);
int				handle_release(int key, t_game *game);
int				handle_key(t_game *game);
int				game_loop(t_game *game);
t_keys			init_keys(void);
void			set_direction(double dir, int nbr);
void			map_border(char **new_map, t_map *map);
void			functions_pixel(t_ray *ray, t_game game, int x, int y);

#endif