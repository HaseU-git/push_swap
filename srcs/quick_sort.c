#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int larger_half_first_to_second(t_node *list_from, t_node *list_to)
{
	int *array_a;
    int len;
	int median;
	int i;

	array_a = convert_to_array(list_from, list_to);
    len = len_list(list_from);
	sort_num_array(array_a, len);
	median = calculate_median(array_a, len);

	i = 0;
	while (i < len)
	{
		if (list_from->next->key <= median)
			rotate(list_from, a_or_b);
		else
			push(list_from, list_to, a_or_b);
		i++;
	}
    free(array_a);
    array_a = NULL;
	return len / 2;
}

int smaller_half_a_to_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	int *num_array;
    int len;
	int median;
	int i;

	num_array = convert_to_array(list_a, list_b);
    len = len_list(list_a);
	sort_num_array(num_array, len);
	median = calculate_median(num_array, len);
    free(num_array);

	i = 0;
	while (i < len)
	{
		if (list_a->next->key > median)
			rotate_a(list_a, list_b, process);
		else
			push_b(list_a, list_b, process);
		i++;
	}
	return len / 2;
}

int smaller_half_first_to_second(t_node *list_from, t_node *list_to)
{
	int *num_array;
    int len;
	int median;
	int i;

	num_array = convert_to_array(list_from, list_to);
    len = len_list(list_from);
	sort_num_array(num_array, len);
	median = calculate_median(num_array, len);
    free(num_array);

	i = 0;
	while (i < len)
	{
		if (list_from->next->key > median)
			rotate(list_from);
		else
			push(list_from, list_to);
		i++;
	}
	return len / 2;
}


int smaller_half_first_to_second(t_node *list_from, t_node *list_to)
{
	int *num_array;
	// 本当はarraybのはず
    int len;
	int median;
	int i;

	num_array = convert_to_array(list_from, list_to);
    len = len_list(list_from);
	sort_num_array(num_array, len);
	median = calculate_median(num_array, len);
    free(num_array);

	i = 0;
	while (i < len)
	{
		if (list_from->next->key > median)
			rotate(list_from);
		else
			push(list_from, list_to);
		i++;
	}
	return len / 2;
}

void		some_head_to_head(t_node *list_from, t_node *list_to, int len)
{
	int cnt;

	cnt = 0;
	while (cnt < len)
	{
		push(list_from, list_to);
		cnt++;
	}
}

void	some_head_to_tail(t_node *list_from, t_node *list_to, int num)
{
	int cnt;

	cnt = 0;
	while (cnt < num)
	{
		push(list_from, list_to);
		rotate(list_to);
		cnt++;
	}
}


void    quick_sort(t_node *list_a, t_node *list_b)
{
	int len;
	int cnt;

	len = len_list(list_b);
	if (len <= 3)
	{
		rule_sort(list_a, list_b);
		some_head_to_tail(list_b, list_a, len);
		return ;
	}
	cnt = larger_half_first_to_second(list_b, list_a);
	quick_sort(list_a, list_b);
	some_head_to_head(list_a, list_b, cnt);
	quick_sort(list_a, list_b);

	return ;
}