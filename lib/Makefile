NAME = libdonshin.a

CC = gcc
CFLAG = -Wall -Werror -Wextra

AR = ar
ARFLAGS = -rcs

GNL = get_next_line_bonus.c get_next_line_utils_bonus.c

all: $(NAME)

$(NAME): libft gnl

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $<
	$(AR) $(ARFLAGS) $(NAME) $@

libft:
	$(make) bonus -C ./src/libft

gnl:
	
clean:

fclean: clean

re: fclean all

.PHONY: all libft gnl ft_print clean fclean re