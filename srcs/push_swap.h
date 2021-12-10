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

typedef enum   e_operation 
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
} t_operation;


typedef struct s_process
{
	t_operation operation;
	struct s_process *prev;
	struct s_process *next;
} t_process;



// arg.c
int count_digit(int num);
int len_str(char *str);
long long str_to_num(char *str);
int is_int(char *str);
int	is_num(char *str);
int arg_check(int argc, char *argv[]);
int is_dupulicated(t_node *list_a);
void arg_to_list(t_node *list_a, t_node *list_b, int argc, char *argv[]);

// free.c
void    free_all_nodes(t_node *dummy);
void    free_two_lists(t_node *list_a, t_node *list_b);

// list_create.c
t_node	*init_node(t_node *dummy);
t_node	*set_node_first(int key, t_node *dummy);
void	delete_node(t_node **t, t_node *dummy);
t_node	*set_node_last(int key, t_node *dummy);

// list_operate.c
void	swap(t_node *dummy);
void	rotate(t_node *dummy);
void	reverse_rotate(t_node *dummy);
void	push(t_node *stack_one, t_node *stack_two);

// rule_sort.c
void	some_head_to_tail(t_node *list_a, t_node *list_b, int num);
void	swap_and_rotate(t_node *dummy);
void	rotate_and_swap(t_node *dummy);
void	rule_sort_three(t_node *list_a, t_node *list_b);
void	rule_sort_two(t_node *list_a, t_node *list_b);
void	rule_sort(t_node *list_a, t_node *list_b);

// list_utils.c
t_node	*pop_first(t_node *dummy);
t_node	*pop_last(t_node *dummy);
void	add_node_first(t_node *dummy, t_node *node);
void	add_node_last(t_node *dummy, t_node *node);
int len_list(t_node *dummy);

// median.c
int *convert_to_array(t_node *dummy, t_node *another_dummy);
int *sort_num_array(int *array, int len);
int calculate_median(int *array, int len);

// quick_sort.c
int larger_half_first_to_second(t_node *list_from, t_node *list_to);
int smaller_half_first_to_second(t_node *list_from, t_node *list_to);
void		some_head_to_head(t_node *list_from, t_node *list_to, int len);
void	some_head_to_tail(t_node *list_from, t_node *list_to, int num);
void    quick_sort(t_node *list_a, t_node *list_b);

// rule_sort.c
void	swap_and_rotate(t_node *dummy);
void	rotate_and_swap(t_node *dummy);
void	rule_sort_three(t_node *list_a, t_node *list_b);
void	rule_sort_two (t_node *list_a, t_node *list_b);
void	rule_sort(t_node *list_a, t_node *list_b);

#endif