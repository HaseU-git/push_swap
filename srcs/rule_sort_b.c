#include "push_swap.h"

void	swap_b_and_rotate_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	swap_b(list_a, list_b, process);
	rotate_b(list_a, list_b, process);
}

void	rotate_b_and_swap_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	rotate_b(list_a, list_b, process);
	swap_b(list_a, list_b, process);
}

void	rule_sort_four_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	int *array;
	int min;
	t_node *ptr;
	int index;

	array = list_b_to_array(list_a, list_b, process);
	min = array[0];
	free(array);
	index = 0;
	ptr = list_b->next;
	while (ptr->key != min)
	{
		ptr = ptr->next;
		index = index + 1;
	}
	if (0 < index && index < 3)
		rotate_b(list_a, list_b, process);
	if (index == 2)
		rotate_b(list_a, list_b, process);
	else if(index == 3)
		reverse_rotate_b(list_a, list_b, process);
	some_head_b_to_tail_a(list_a, list_b, process, 1);
	rule_sort_three_b(list_a, list_b, process->next);
}

void	rule_sort_three_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	int	first;
	int	second;
	int	third;

	first = list_b->next->key;
	second = list_b->next->next->key;
	third = list_b->next->next->next->key;

	if (first < second && second > third && first < third)
		swap_b_and_rotate_b(list_a, list_b, process);
	else if (first < second && second > third && first > third)
		reverse_rotate_b(list_a, list_b, process);
	else if (first > second && second < third && first < third)
		swap_b(list_a, list_b, process);
	else if (first > second && second < third && first > third)
		rotate_b(list_a, list_b, process);
	else if (first > second && second > third && first > third)
		rotate_b_and_swap_b(list_a, list_b, process);
}

void	rule_sort_two_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	if (list_b->next->key > list_b->next->next->key)
		rotate_b(list_a, list_b, process);
}

void	rule_sort_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	int len_list_b;

	len_list_b = len_list(list_b);
	if (len_list_b == 2)
		rule_sort_two_b(list_a, list_b, process);
	else if (len_list_b == 3)
		rule_sort_three_b(list_a, list_b, process);
	else if (len_list_b == 4)
		rule_sort_four_b(list_a, list_b, process);
}
