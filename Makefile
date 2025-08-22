NAME = fdf
CFLAGS = -Wall -Wextra -Werror
CHEADERS = -I ./get_next_line -I . -I ./libft
CLINKS = -L ./get_next_line -l get_next_line -L ./libft -l ft
EXTRA = -L . -lmlx -framework OpenGL -framework AppKit
CFILES = $(wildcard *.c)
OBJS = $(CFILES:.c=.o)
#cc hooktest.c -L . -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) $(CLINKS) $(EXTRA) -o $(NAME)

%.o: %.c fdf.h
	cc $(CFLAGS) $(CHEADERS) -I. -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re