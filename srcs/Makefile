NAME := push_swap
CC := gcc
CFLAG := -Wall -Wextra -Werror
RM := rm -f
SRCS :=	main.c\
		free.c\
		quick_sort.c\
		rule_sort_a.c\
		rule_sort_b.c\
		list_utils.c\
		list_create.c\
		process.c\
		process_optimize.c\
		process_write.c\
		median.c\
		list_operate_new.c\
		arg.c\

OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
