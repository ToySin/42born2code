# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:38:58 by donshin           #+#    #+#              #
#    Updated: 2022/01/03 15:25:50 by donshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a

CC = gcc
CFLAG = -Wall -Werror -Wextra -c

SRCS = \
	ft_printf.c \
	is_valid_format.c \
	parse_conversion.c \
	print_arg.c \
	print_char.c \
	print_nbr.c \
	print_string.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rcus $@ $^

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all


test:
	$(CC) -Wall -Wextra -Werror test.c $(SRCS) libft/*.c

.PHONY: all clean fclean re

