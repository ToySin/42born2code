CC = gcc
CFLAG = -Wall -Werror -Wextra -g -include get_next_line_bonus.h
RM = rm -f

SRC = \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	test.c \

OBJS = $(SRC:.c=.o)

NAME = test

all: $(NAME)

1:
	$(CC) $(CFLAG) -D BUFFER_SIZE=1 $(SRC)

42:
	$(CC) $(CFLAG) -D BUFFER_SIZE=42 $(SRC)

1000:
	$(CC) $(CFLAG) -D BUFFER_SIZE=1000 $(SRC)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -o $@ $^

clean:
	$(RM) $(OBJS) a.out

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 1 42 1000
