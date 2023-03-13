# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 18:36:34 by thsousa           #+#    #+#              #
#    Updated: 2023/03/13 18:36:34 by thsousa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cube

LIBFT	= ./libft/libft.a
MLX = minilibx

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS	= 	main.c utils.c validation.c creating_map.c raycast.c\
			events.c utils_validation.c utils_colors.c utils_map.c\
			check_space.c

OBJS	=  $(SRCS:.c=.o)

CFLAGS	= -o3 -g -Wall -Wextra -Werror

$(NAME):	$(OBJS)
			make -C ./libft && make -C ./minilibx
#cc $^ $(LIBFT)  -o $@
			cc $^ -I ./minilibx -L ./minilibx -l mlx -framework OpenGl -framework Appkit $(LIBFT) -o $@

all:		$(NAME)

clean:
			rm -f $(OBJS)
			make clean -C ./libft
			make clean -C ./minilibx

fclean:		clean
			rm -f $(NAME)
			

re:			fclean all

.PHONY:		all clean fclean re
