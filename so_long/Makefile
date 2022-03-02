NAME = so_long
LIBFT = lib/libft.a

CC = gcc
CFLAG = -Wall -Werror -Wextra

SRCS = src/*.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(SRCS)
	$(MAKE) -C ./lib
	$(CC) $(CFLAG) -o $@ $^ $(LIBFT)

all: $(NAME)

clean:
	$(MAKE) clean -C ./lib
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./lib
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
