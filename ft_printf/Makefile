# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:38:58 by donshin           #+#    #+#              #
#    Updated: 2022/01/13 15:28:21 by donshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a

CC = gcc
CFLAG = -Wall -Werror -Wextra

SRCS = \
	ft_printf.c \
	is_valid_format.c \
	parse_conversion.c \
	print_arg.c \
	print_char.c \
	print_nbr.c \
	print_string.c

OBJS = $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp $(LIBFT) $(NAME)
	ar rcus $@ $^

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

test:
	$(CC) $(CFLAG) -o test1 test_ft_printf.c $(SRCS) libft/*.c
	$(CC) $(CFLAG) -o test2 test_printf.c

.PHONY: all clean fclean re