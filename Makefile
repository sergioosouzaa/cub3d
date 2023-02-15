NAME	= cube

##LIBFT	= ./libft/libft.a

SRCS	= 	main.c

OBJS	=  $(SRCS:.c=.o)

CFLAGS	= -g -Wall -Wextra -Werror

$(NAME):	$(OBJS)
			make -C ./minilibx
			cc $^ -I ./minilibx -L ./minilibx -l mlx -framework OpenGl -framework Appkit -o $@

all:		$(NAME)

clean:
			rm -f $(OBJS)
			make clean -C ./minilibx

fclean:		clean
			rm -f $(NAME)
			

re:			fclean all

.PHONY:		all clean fclean re