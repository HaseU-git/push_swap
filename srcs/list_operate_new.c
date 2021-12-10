#include "push_swap.h"

void	swap_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	t_node *first;
	t_node *second;

	first = pop_first(list_a);
	second = pop_first(list_a);
	add_node_first(list_a, first);
	add_node_first(list_a, second);
	update_process(list_a, list_b, process, SA);
}

void	swap_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	t_node *first;
	t_node *second;

	first = pop_first(list_b);
	second = pop_first(list_b);
	add_node_first(list_b, first);
	add_node_first(list_b, second);
	update_process(list_a, list_b, process, SB);
}

void	rotate_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	add_node_last(list_a, pop_first(list_a));
	update_process(list_a, list_b, process, RA);
}

void	rotate_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	add_node_last(list_b, pop_first(list_b));
	update_process(list_a, list_b, process, RB);
}

void	reverse_rotate_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	add_node_first(list_a, pop_last(list_a));
	update_process(list_a, list_b, process, RRA);
}

void	reverse_rotate_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	add_node_first(list_b, pop_last(list_b));
	update_process(list_a, list_b, process, RRB);
}

void	push_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	add_node_first(list_a, pop_first(list_b));
	update_process(list_a, list_b, process, PA);
}

void	push_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	add_node_first(list_b, pop_first(list_a));
	update_process(list_a, list_b, process, PB);
}

void show_list(t_node *dummy)
{
    t_node *ptr;
    ptr = dummy->next;

    while (ptr != dummy)
    {
        printf("%d\n", ptr->key);
        ptr = ptr->next;
    }
}