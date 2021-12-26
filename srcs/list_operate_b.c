#include "push_swap.h"

void	swap_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	t_node	*first;
	t_node	*second;

	first = pop_first(list_b);
	second = pop_first(list_b);
	add_node_first(list_b, first);
	add_node_first(list_b, second);
	update_prcs(list_a, list_b, process, SB);
}

void	rotate_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	add_node_last(list_b, pop_first(list_b));
	update_prcs(list_a, list_b, process, RB);
}

void	r_rotate_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	add_node_first(list_b, pop_last(list_b));
	update_prcs(list_a, list_b, process, RRB);
}

void	push_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	add_node_first(list_b, pop_first(list_a));
	update_prcs(list_a, list_b, process, PB);
}
