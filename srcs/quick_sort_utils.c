#include "push_swap.h"

int larger_half_b_to_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	int *array_b;
	int len;
	int median;
	int i;

	array_b = list_b_to_array(list_a, list_b, process);
	len = len_list(list_b);
	sort_num_array(array_b, len);
	median = calculate_median(array_b, len);
	free(array_b);

	i = 0;
	while (i < len)
	{
		if (list_b->next->key <= median)
			rotate_b(list_a, list_b, process);
		else
			push_a(list_a, list_b, process);
		i++;
	}
	return len / 2;
}

int larger_half_a_to_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	int *array_a;
	int len;
	int median;
	int i;

	array_a = list_a_to_array(list_a, list_b, process);
	len = len_list(list_a);
	sort_num_array(array_a, len);
	median = calculate_median(array_a, len);

	i = 0;
	while (i < len)
	{
		if (list_a->next->key <= median)
			rotate_a(list_a, list_b, process);
		else
			push_b(list_a, list_b, process);
		i++;
	}
	free(array_a);
	array_a = NULL;
	return len / 2;
