# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 14:03:47 by donshin           #+#    #+#              #
#    Updated: 2022/03/31 13:01:25 by donshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_DIR = ./lib
LIBFT_NAME = ft
LIBFT = libft.a

MLX_DIR = ./mlx
MLX_NAME = mlx
MLX = libmlx.a

CC = gcc
CFLAG = -Wall -Wextra -Werror
CLIB = -L$(LIBFT_DIR) -l$(LIBFT_NAME) -L$(MLX_DIR) -l$(MLX_NAME) \
	-framework OpenGL -framework AppKit

SRC_DIR = ./src
SRCS = $(SRC_DIR)/draw.c $(SRC_DIR)/end.c $(SRC_DIR)/file.c \
	$(SRC_DIR)/ft_mlx.c $(SRC_DIR)/init.c $(SRC_DIR)/lst_add.c \
	$(SRC_DIR)/move.c $(SRC_DIR)/process.c $(SRC_DIR)/so_long.c \
	$(SRC_DIR)/utils.c $(SRC_DIR)/check.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAG) $(CLIB) -o $@ $^

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
