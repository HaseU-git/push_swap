#ifndef PUSH_SWAP

# define PUSH_SWAP
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int key;
	struct s_node *prev;
	struct s_node *next;
} t_node;

typedef struct s_num_array
{
	int *elements;
	int len;
} t_num_array;

typedef struct s_process
{
	enum e_operation *operation;
	struct s_process *prev;
	struct s_process *next;
} t_process;

enum   e_operation 
{
    SA,
    SB,
    SS,
    PA,
    PB,
    RA,
    RB,
    RR,
    RRA,
    RRB,
    RRR
};

t_node	*init_node(t_node *dummy);
t_node	*set_node_last(int key, t_node *dummy);

void    free_all_nodes(t_node *dummy);
void    free_two_lists(t_node *list_a, t_node *list_b);

#endif

// arg.c
int	is_num(char *str);
int arg_check(int argc, char *argv[]);
int	ft_atoi(const char *str);
int	ft_atoi(const char *str);
void arg_to_list(t_node *list_a, t_node *list_b, int argc, char *argv[]);

// rule_sort.c
void	some_head_b_to_tail_a(t_node *list_a, t_node *list_b, int num);
void	swap_and_rotate(t_node *dummy);
void	rotate_and_swap(t_node *dummy);
void	rule_sort_three(t_node *list_a, t_node *list_b);

// list_operate.c
void	swap(t_node *dummy);
void	rotate(t_node *dummy);
void	reverse_rotate(t_node *dummy);
void	push(t_node *stack_one, t_node *stack_two);

// list_utils_two.c
t_node	*pop_first(t_node *dummy);
t_node	*pop_last(t_node *dummy);
void	add_node_first(t_node *dummy, t_node *node);
void	add_node_last(t_node *dummy, t_node *node);