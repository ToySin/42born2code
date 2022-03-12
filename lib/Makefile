# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 16:04:27 by donshin           #+#    #+#              #
#    Updated: 2022/03/12 16:06:33 by donshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAG = -Wall -Werror -Wextra

AR = ar
ARFLAGS = -rcs

LIBFT_DIR = src/libft
GNL_DIR = src/get_next_line

LIBFT_SRC = \
$(LIBFT_DIR)/ft_atoi.c \
$(LIBFT_DIR)/ft_bzero.c \
$(LIBFT_DIR)/ft_calloc.c \
$(LIBFT_DIR)/ft_isalnum.c \
$(LIBFT_DIR)/ft_isalpha.c \
$(LIBFT_DIR)/ft_isascii.c \
$(LIBFT_DIR)/ft_isdigit.c \
$(LIBFT_DIR)/ft_isprint.c \
$(LIBFT_DIR)/ft_itoa.c \
$(LIBFT_DIR)/ft_memchr.c \
$(LIBFT_DIR)/ft_memcmp.c \
$(LIBFT_DIR)/ft_memcpy.c \
$(LIBFT_DIR)/ft_memmove.c \
$(LIBFT_DIR)/ft_memset.c \
$(LIBFT_DIR)/ft_putchar_fd.c \
$(LIBFT_DIR)/ft_putendl_fd.c \
$(LIBFT_DIR)/ft_putnbr_fd.c \
$(LIBFT_DIR)/ft_putstr_fd.c \
$(LIBFT_DIR)/ft_split.c \
$(LIBFT_DIR)/ft_strchr.c \
$(LIBFT_DIR)/ft_strdup.c \
$(LIBFT_DIR)/ft_strjoin.c \
$(LIBFT_DIR)/ft_strlcat.c \
$(LIBFT_DIR)/ft_strlcpy.c \
$(LIBFT_DIR)/ft_strlen.c \
$(LIBFT_DIR)/ft_strmapi.c \
$(LIBFT_DIR)/ft_strncmp.c \
$(LIBFT_DIR)/ft_strnstr.c \
$(LIBFT_DIR)/ft_strrchr.c \
$(LIBFT_DIR)/ft_strtrim.c \
$(LIBFT_DIR)/ft_substr.c \
$(LIBFT_DIR)/ft_tolower.c \
$(LIBFT_DIR)/ft_striteri.c \
$(LIBFT_DIR)/ft_toupper.c \
$(LIBFT_DIR)/ft_lstnew.c \
$(LIBFT_DIR)/ft_lstadd_front.c \
$(LIBFT_DIR)/ft_lstsize.c \
$(LIBFT_DIR)/ft_lstlast.c \
$(LIBFT_DIR)/ft_lstadd_back.c \
$(LIBFT_DIR)/ft_lstdelone.c \
$(LIBFT_DIR)/ft_lstclear.c \
$(LIBFT_DIR)/ft_lstiter.c \
$(LIBFT_DIR)/ft_lstmap.c
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

GNL_SRC = \
$(GNL_DIR)/get_next_line.c \
$(GNL_DIR)/get_next_line_utils.c
GNL_OBJ = $(GNL_SRC:.c=.o)

all: $(NAME)

$(NAME): libft gnl

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $<
	$(AR) $(ARFLAGS) $(NAME) $@

libft: $(LIBFT_OBJ)

gnl: $(GNL_OBJ)

clean:
	rm -f $(LIBFT_OBJ)
	rm -f $(GNL_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re libft gnl
