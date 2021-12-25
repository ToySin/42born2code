CC = gcc
CFLAG = -Wall -Werror -Wextra -g
RM = rm -f

SRC = \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	test.c \

OBJS = $(SRC:.c=.o)

NAME = test

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -o -I get_next_line_bonus.h $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
