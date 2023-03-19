NAME	= cub3D

LIBFT	= ../libft/libft.a
MLX = ../minilibx

LXFLAGS = -lmlx -lm -framework OpenGL -framework AppKit

SRCS	= 	main.c utils.c raycast.c time_utils.c texture.c menu.c char_select.c controls.c doors.c image_utils.c\
			keyboard_events.c dda.c sprites.c sprite_utils.c minimap.c creating_map.c check_space.c\
			utils_map.c utils_validation.c validation.c movements.c enemies.c gaming.c movements2.c utils2.c

OBJS	=  $(SRCS:.c=.o)

CFLAGS	= -O3 -g -Wall -Wextra -Werror

$(NAME):	$(OBJS)
			make -C ../libft && make -C ../minilibx
			cc -o $(NAME) -lm -L $(MLX) $(LXFLAGS) $(LIBFT) $(OBJS)
##			//cc $^ -I ./minilibx -L ./minilibx -l mlx -framework OpenGl -framework Appkit -o $@

all:		$(NAME)

clean:
			rm -f $(OBJS)
			make clean -C ../minilibx

fclean:		clean
			rm -f $(NAME)
			

re:			fclean all

.PHONY:		all clean fclean re