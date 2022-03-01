NAME = so_long
LIBFT = -L./libft -lft

CC = gcc
CFLAG = -Wall -Werror -Wextra

SRCS = src/*.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(SRCS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAG) -o $@ $^ $(LIBFT)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
