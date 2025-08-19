NAME = fdf
CFLAGS = -Wall -Wextra -Werror
CHEADERS = -I ./get_next_line -I . -I ./libft
CLINKS = -L ./get_next_line -l get_next_line -L ./libft -l ft
EXTRA = -L . -lmlx -framework OpenGL -framework AppKit
CFILES = main.c
OBJS = main.o
#cc hooktest.c -L . -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) $(EXTRA) -o $(NAME) -g

%.o: %.c fdf.h
	cc $(CFLAGS) -I. -c $< -o $@ -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re