# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 14:10:12 by sdos-san          #+#    #+#              #
#    Updated: 2023/03/20 13:49:53 by sdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#      NAME       #
NAME		=	cub3D

#      FLAGS      #

CC			=	cc
FLAGS		=	-g -Wall -Wextra -Werror 
RM			=	rm -rf

#      INCLUDES    #

LIBFT	= ./libft/libft.a

#       MANDATORY    #

FILES	=	./mandatory/main ./mandatory/utils ./mandatory/validation\
			./mandatory/creating_map ./mandatory/raycast\
			./mandatory/events ./mandatory/utils_validation\
			./mandatory/utils_colors ./mandatory/utils_map\
			./mandatory/check_space
			
SRCS_DIR =
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = 
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

FILES_BONUS	=	./bonus/main ./bonus/utils ./bonus/raycast ./bonus/time_utils\
                ./bonus/texture ./bonus/menu ./bonus/char_select ./bonus/controls\
                ./bonus/doors ./bonus/image_utils ./bonus/keyboard_events ./bonus/dda\
                ./bonus/sprites ./bonus/sprite_utils ./bonus/minimap ./bonus/creating_map\
                ./bonus/check_space ./bonus/utils_map ./bonus/utils_validation\
                ./bonus/validation ./bonus/movements ./bonus/enemies ./bonus/gaming \
				./bonus/movements2 ./bonus/utils2
			
BSRCS_DIR = 
BSRCS = $(addprefix $(BSRCS_DIR), $(addsuffix .c, $(FILES_BONUS)))

BOBJS_DIR = 
BOBJS = $(addprefix $(BOBJS_DIR), $(addsuffix .o, $(FILES_BONUS)))

.c.o: $(SRCS) $(BSRCS_DIR)
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
		@cd libft && $(MAKE)
		@cd minilibx && $(MAKE)
		cc $^ -I ./minilibx -L ./minilibx -l mlx -framework OpenGl -framework Appkit $(LIBFT) -o $@
		@printf "$(GREEN)cub3D Compiled 😎\n"

all: $(NAME)

bonus: $(BOBJS)
		@cd libft && $(MAKE)
		@cd minilibx && $(MAKE)
		cc $^ -I ./minilibx -L ./minilibx -l mlx -framework OpenGl -framework Appkit $(LIBFT) -o $(NAME)
		@printf "$(GREEN)cub3D Bonus Compiled 😎\n"
		./bonus/cub3D ./bonus/maps/1.cub
#		@cd bonus && $(MAKE)
clean:
		@printf "$(YELLOW)Deleting cub3D Objects...\n"
		@cd libft && $(MAKE) clean
		@$(RM) $(OBJS) $(BOBJS)
		@printf "$(GREEN)cub3D Objects Deleted 😎 🗑\n"

fclean:	clean
		@printf "$(YELLOW)Deleting cub3D ...\n"
		@cd libft && $(MAKE) fclean
		@$(RM) $(NAME)
		@printf "$(GREEN)cub3D file Deleted 😎 🗑\n"

re:				fclean all

.PHONY:		all clean fclean re libft

GREEN=\033[0;32m
YELLOW=\033[0;33m
