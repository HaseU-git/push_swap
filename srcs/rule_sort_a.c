#include "push_swap.h"

void	swap_a_and_rotate_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	swap_a(list_a, list_b, process);
	rotate_a(list_a, list_b, process);
}

void	rotate_a_and_swap_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	rotate_a(list_a, list_b, process);
	swap_a(list_a, list_b, process);
}

void	rule_sort_three_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	int	first;
	int	second;
	int	third;

	first = list_a->next->key;
	second = list_a->next->next->key;
	third = list_a->next->next->next->key;

	if (first < second && second > third && first < third)
		swap_a_and_rotate_a(list_a, list_b, process);
	else if (first < second && second > third && first > third)
		reverse_rotate_a(list_a, list_b, process);
	else if (first > second && second < third && first < third)
		swap_a(list_a, list_b, process);
	else if (first > second && second < third && first > third)
		rotate_a(list_a, list_b, process);
	else if (first > second && second > third && first > third)
		rotate_a_and_swap_a(list_a, list_b, process);
}

void	rule_sort_two_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	if (list_a->next->key > list_a->next->next->key)
		rotate_b(list_a, list_b, process);
}

void	rule_sort_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	int len_list_a;

	len_list_a = len_list(list_a);
	if (len_list_a == 2)
		rule_sort_two_a(list_a, list_b, process);
	else if (len_list_a == 3)
		rule_sort_three_a(list_a, list_b, process);
}
