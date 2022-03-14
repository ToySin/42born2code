# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 16:14:52 by donshin           #+#    #+#              #
#    Updated: 2022/03/14 14:34:59 by donshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
	$(MAKE) -C ./lib
	$(MAKE) -C ./mlx_beta
	cp $(MLX_DIR)/$(MLX) ./$(MLX)
	$(CC) $(CFLAG) -o $@ $^ -L$(LIBFT_DIR) -l$(LIBFT_NAME) -L./ -l$(MLX_NAME)

all: $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./lib
	rm -f $(NAME)
	rm -f $(MLX)

re: fclean all


test:
	$(MAKE) -C ./mlx_beta
	cp $(MLX_DIR)/$(MLX) ./$(MLX)
	gcc -L./ -lmlx test.c -o test.out


.PHONY: all clean fclean re
