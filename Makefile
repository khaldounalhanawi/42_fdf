NAME = fdf
CFLAGS = -Wall -Wextra -Werror
CHEADERS = -I ./get_next_line -I . -I ./libft
CLINKS = -L ./get_next_line -l get_next_line -L ./libft -l ft
EXTRA = -L ./minilibx-linux -lmlx -lX11 -lm -lXext
CFILES = $(wildcard *.c)
OBJS = $(CFILES:.c=.o)

LIBFT_DIR = ./libft
GNLINE_DIR = ./get_next_line
MINI_LIBX_DIR = ./minilibx-linux

all : LIBFT GNLINE MINI_LIBX $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) $(CLINKS) -o $(NAME) $(EXTRA) -g

GNLINE:
	make -C $(GNLINE_DIR)

MINI_LIBX:
	make -C $(MINI_LIBX_DIR)

LIBFT:
	make -C $(LIBFT_DIR) bonus

%.o: %.c fdf.h
	cc $(CFLAGS) $(CHEADERS) -I. -c $< -o $@ -g

clean:
	rm -f $(OBJS)
	make -C $(GNLINE_DIR) clean
	make -C $(LIBFT_DIR) clean
	make -C $(MINI_LIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(GNLINE_DIR) fclean
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re