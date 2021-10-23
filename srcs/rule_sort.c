#include "push_swap.h"

void	swap_and_rotate(t_node *dummy, char a_or_b)
{
	swap(dummy, a_or_b);
	rotate(dummy, a_or_b);
}

void	rotate_and_swap(t_node *dummy, char a_or_b)
{
	rotate(dummy, a_or_b);
	swap(dummy, a_or_b);
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
		swap_and_rotate(list_b, 'b');
	else if (first < second && second > third && first > third)
		reverse_rotate(list_b, 'b');
	else if (first > second && second < third && first < third)
		swap(list_b, 'b');
	else if (first > second && second < third && first > third)
		rotate(list_b, 'b');
	else if (first > second && second > third && first > third)
		rotate_and_swap(list_b, 'b');
}

void	rule_sort_two (t_node *list_a, t_node *list_b)
{
	if (list_b->next->key > list_b->next->next->key)
		rotate(list_b, 'b');
}

void	rule_sort(t_node *list_a, t_node *list_b)
{
	int len_list_b;

	len_list_b = len_list(list_b);
	if (len_list_b == 2)
		rule_sort_two(list_a, list_b);
	else if (len_list_b == 3)
		rule_sort_three(list_a, list_b);
}