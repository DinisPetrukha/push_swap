NAME = push_swap
CC = cc
INCLUDES = -I./includes
SRCDIR = src
SRCS = 	src/errors_free.c src/ft_split.c src/init_nodes.c src/main.c src/mini_swap.c src/push.c \
		src/push_swap.c src/reverse_rotate.c src/rotate.c src/set_node.c src/stack_init.c \
		src/stack_init_utils.c src/swap.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all