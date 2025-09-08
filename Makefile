NAME = fdf
CFLAGS = -Wall -Wextra -Werror
CHEADERS = -I ./get_next_line -I . -I ./libft -I /usr/local/include
CLINKS = -L ./get_next_line -l get_next_line -L ./libft -l ft
EXTRA = -L /usr/local/lib -lmlx -lX11 -lm -lXext
CFILES = fn_grid_to_points.c graphics_draw_segments.c \
		fn_helpers_I.c graphics_helpers.c \
		fn_helpers_II.c graphics_main.c \
		fn_mapfromfile.c graphics_projections.c \
		fn_mapfromfile_fill_map.c graphics_zooms.c \
		fn_mapfromfile_fill_map_helper.c main.c \
		graphics_draw_line.c
		
OBJS = $(CFILES:.c=.o)

LIBFT_DIR = ./libft
GNLINE_DIR = ./get_next_line

all : LIBFT GNLINE $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) $(CLINKS) -o $(NAME) $(EXTRA) -g

GNLINE:
	make -C $(GNLINE_DIR)

LIBFT:
	make -C $(LIBFT_DIR)

%.o: %.c fdf.h
	cc $(CFLAGS) $(CHEADERS) -I. -c $< -o $@ -g

clean:
	rm -f $(OBJS)
	make -C $(GNLINE_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(GNLINE_DIR) fclean
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

