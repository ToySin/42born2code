NAME = so_long

LIBFT_DIR = ./lib
LIBFT_NAME = ft

MLX_DIR = ./mlx
MLX_NAME = mlx

CC = gcc
CFLAG = -Wall -Werror -Wextra

SRCS = src/*.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(SRCS)
	$(MAKE) all -C ./lib
	$(MAKE) all -C ./mlx
	$(CC) $(CFLAG) -o $@ $^ -L$(LIBFT_DIR) -l$(LIBFT_NAME) -L$(MLX_DIR) -l$(MLX_NAME)

all: $(NAME)

clean:
	$(MAKE) clean -C ./lib
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./lib
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
