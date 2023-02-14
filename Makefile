NAME	= cub3d

##LIBFT	= ./libft/libft.a

SRCS	= 	main.c

OBJS	=  $(SRCS:.c=.o)

CFLAGS	= -g -Wall -Wextra -Werror

$(NAME):	$(OBJS)
			make -C ./mlx_linux
			$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all:		$(NAME)

clean:
			rm -f $(OBJS)
			##make clean -C ./mlx_linux

fclean:		clean
			rm -f $(NAME)
##			make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re