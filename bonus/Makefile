NAME	= cube

##LIBFT	= ./libft/libft.a
MLX = minilibx

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS	= 	main.c utils.c raycast.c

OBJS	=  $(SRCS:.c=.o)

CFLAGS	= -o3 -g -Wall -Wextra -Werror

$(NAME):	$(OBJS)
			make -C ./minilibx
			cc -o $(NAME) -L $(MLX) $(LXFLAGS) $(OBJS)
##			//cc $^ -I ./minilibx -L ./minilibx -l mlx -framework OpenGl -framework Appkit -o $@

all:		$(NAME)

clean:
			rm -f $(OBJS)
			make clean -C ./minilibx

fclean:		clean
			rm -f $(NAME)
			

re:			fclean all

.PHONY:		all clean fclean re