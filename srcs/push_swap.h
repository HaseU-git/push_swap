#ifndef PUSH_SWAP

# define PUSH_SWAP
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

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

#endif