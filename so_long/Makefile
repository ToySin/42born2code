NAME = so_long

LIBFT_DIR = ./lib
LIBFT_NAME = ft

MLX_DIR = ./mlx_beta
MLX_NAME = mlx
MLX = libmlx.dylib

CC = gcc
CFLAG = -Wall -Werror -Wextra

SRCS = src/*.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(SRCS)
	$(MAKE) all -C ./lib
	$(MAKE) all -C ./mlx_beta
	mv $(MLX_DIR)/$(MLX) ./$(MLX)
	$(CC) $(CFLAG) -o $@ $^ -L$(LIBFT_DIR) -l$(LIBFT_NAME) -L. -l$(MLX_NAME)

all: $(NAME)

clean:
	$(MAKE) clean -C ./lib
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./lib
	rm -f $(NAME)
	rm -f $(MLX)

re: fclean all


test:
	gcc -L./ -lmlx test.c


.PHONY: all clean fclean re
