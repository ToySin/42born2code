# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 14:03:47 by donshin           #+#    #+#              #
#    Updated: 2022/03/28 16:31:54 by donshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_DIR = ./lib
LIBFT_NAME = ft
LIBFT = libft.a

MLX_DIR = ./mlx_beta
MLX_NAME = mlx
MLX = libmlx.dylib

CC = gcc
CFLAG = -Wall -Wextra -Werror

INCLUDE_DIR = ./include

SRC_DIR = ./src
SRCS = $(SRC_DIR)/draw.c $(SRC_DIR)/end.c $(SRC_DIR)/file.c \
	$(SRC_DIR)/ft_mlx.c $(SRC_DIR)/init.c $(SRC_DIR)/lst_add.c \
	$(SRC_DIR)/move.c $(SRC_DIR)/process.c $(SRC_DIR)/so_long.c \
	$(SRC_DIR)/utils.c $(SRC_DIR)/check.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAG) -o $@ $^ \
		-L$(LIBFT_DIR) -l$(LIBFT_NAME) -L$(MLX_DIR) -l$(MLX_NAME)
	install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $@

%.o: %.c
	$(CC) $(CFLAG) -o $@ -c $^

all: $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -f $(MLX_DIR)/$(MLX)

re: fclean all

test:
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CLFAG) -o test.out test.c \
		-L$(LIBFT_DIR) -l$(LIBFT_NAME) -L$(MLX_DIR) -l$(MLX_NAME)
	install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) test.out

ctest: fclean
	$(MAKE) -C $(MLX_DIR)
	rm -f test.out

.PHONY: all clean fclean re
