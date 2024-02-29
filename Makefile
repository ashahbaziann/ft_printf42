NAME = libftprintf.a

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c c_print.c s_print.c d_print.c p_print.c u_print.c x_print.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
