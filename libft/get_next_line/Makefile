NAME	= get_next_line.a

SRCS	= get_next_line.c get_next_line_utils.c

OBJS	=  $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./get_next_line.h

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
