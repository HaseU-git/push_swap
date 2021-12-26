NAME := push_swap
CC := gcc
CFLAG := -Wall -Wextra -Werror
RM := rm -f
SRCS :=	main.c\
		free.c\
		quick_sort.c\
		quick_sort_utils.c\
		rule_sort_a.c\
		rule_sort_b.c\
		rule_sort_utils.c\
		list_utils.c\
		list_create.c\
		process_create.c\
		process_optimize.c\
		process_write.c\
		process_print.c\
		median.c\
		list_operate_a.c\
		list_operate_a_n.c\
		list_operate_b.c\
		list_operate_b_n.c\
		arg_check.c\
		arg_utils.c\

OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -o $@ $^


all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
