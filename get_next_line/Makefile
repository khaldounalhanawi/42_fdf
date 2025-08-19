NAME = libget_next_line.a
CFLAGS = -Wall -Wextra -Werror
Cfiles = $(wildcard *.c)
OBJS = $(Cfiles:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	ar rsc $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re