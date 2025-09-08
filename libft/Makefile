CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
CFILES = ft_strnstr.c ft_isdigit.c ft_putstr_fd.c ft_strlcpy.c \
	ft_strlen.c ft_memcmp.c ft_putnbr_fd.c ft_strchr.c ft_striteri.c \
	ft_bzero.c ft_strjoin.c ft_isascii.c ft_memcpy.c ft_isprint.c \
	ft_putendl_fd.c ft_toupper.c ft_split.c ft_strrchr.c ft_isalpha.c \
	ft_memchr.c ft_putchar_fd.c ft_memset.c ft_substr.c ft_strncmp.c ft_strmapi.c \
	ft_strtrim.c ft_memmove.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_atoi.c \
	ft_isalnum.c ft_itoa.c ft_tolower.c

OBJS = ft_strnstr.o ft_isdigit.o ft_putstr_fd.o ft_strlcpy.o ft_strlen.o \
	ft_memcmp.o ft_putnbr_fd.o ft_strchr.o ft_striteri.o ft_bzero.o ft_strjoin.o \
	ft_isascii.o ft_memcpy.o ft_isprint.o ft_putendl_fd.o ft_toupper.o ft_split.o \
	ft_strrchr.o ft_isalpha.o ft_memchr.o ft_putchar_fd.o ft_memset.o ft_substr.o \
	ft_strncmp.o ft_strmapi.o ft_strtrim.o ft_memmove.o ft_strlcat.o ft_calloc.o \
	ft_strdup.o ft_atoi.o ft_isalnum.o ft_itoa.o ft_tolower.o
	
BFILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BOBJS = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o \
	ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o

all: $(NAME)

$(NAME): $(OBJS) $(BOBJS)
	ar rcs $(NAME) $(OBJS) $(BOBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
	


.PHONY: all clean fclean re 
