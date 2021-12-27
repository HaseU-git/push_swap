NAME := push_swap
CC := gcc
CFLAG := -Wall -Wextra -Werror
RM := rm -f
SRCS :=	srcs/main.c\
	srcs/free.c\
	srcs/quick_sort.c\
	srcs/quick_sort_utils.c\
	srcs/rule_sort_a.c\
	srcs/rule_sort_b.c\
	srcs/rule_sort_utils.c\
	srcs/list_utils.c\
	srcs/list_create.c\
	srcs/process_create.c\
	srcs/process_optimize.c\
	srcs/process_write.c\
	srcs/process_print.c\
	srcs/median.c\
	srcs/list_operate_a.c\
	srcs/list_operate_a_n.c\
	srcs/list_operate_b.c\
	srcs/list_operate_b_n.c\
	srcs/arg_check.c\
	srcs/arg_set.c\
	srcs/arg_convert.c\
	srcs/arg_utils.c\
	srcs/ft_strlcpy.c
HEADER := push_swap.h


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
