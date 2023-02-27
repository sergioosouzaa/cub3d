NAME	= libft.a

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		  ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
		  ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin_.c ft_strlcat.c \
		  ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		  ft_tolower.c ft_toupper.c ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_printf_utils3.c ft_find.c

SRCS_B	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
		   ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c


OBJS	=  $(SRCS:.c=.o)

OBJS_B	=	$(SRCS_B:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./libft.h

$(NAME):	$(OBJS)
			make -C ./get_next_line
			cp ./get_next_line/get_next_line.a ./$(NAME)
			ar rcs $(NAME) $(OBJS)
			
bonus:		$(OBJS_B)
			ar rcs $(NAME) $(OBJS_B)

all:		$(NAME)

clean:
			make clean -C ./get_next_line
			rm -f $(OBJS) $(OBJS_B)

fclean:		clean
			make fclean -C ./get_next_line
			rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
