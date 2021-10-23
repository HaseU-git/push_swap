#include "push_swap.h"

void	some_head_b_to_tail_a(t_node *list_a, t_node *list_b, int num)
{
	int cnt;

	cnt = 0;
	while (cnt < num)
	{
		push(list_b, list_a);
		rotate(list_a);
		cnt++;
	}
}

void	swap_and_rotate(t_node *dummy)
{
	swap(dummy);
	rotate(dummy);
}

void	rotate_and_swap(t_node *dummy)
{
	rotate(dummy);
	swap(dummy);
}

void	rule_sort_three(t_node *list_a, t_node *list_b)
{
	int	first;
	int	second;
	int	third;

	first = list_b->next->key;
	second = list_b->next->next->key;
	third = list_b->next->next->next->key;

	if (first < second && second > third && first < third)
		swap_and_rotate(list_b);
	else if (first < second && second > third && first > third)
		reverse_rotate(list_b);
	else if (first > second && second < third && first < third)
		swap(list_b);
	else if (first > second && second < third && first > third)
		rotate(list_b);
	else if (first > second && second > third && first > third)
		rotate_and_swap(list_b);
	some_head_b_to_tail_a(list_a, list_b, 3);
}