#include "push_swap.h"

void	swap(t_node *dummy)
{
	t_node *first;
	t_node *second;

	first = pop_first(dummy);
	second = pop_first(dummy);
	add_node_first(dummy, first);
	add_node_first(dummy, second);
}

void	rotate(t_node *dummy)
{
	add_node_last(dummy, pop_first(dummy));
}

void	reverse_rotate(t_node *dummy)
{
	add_node_first(dummy, pop_last(dummy));
}

void	push(t_node *stack_one, t_node *stack_two)
{
	add_node_first(stack_two, pop_first(stack_one));
}