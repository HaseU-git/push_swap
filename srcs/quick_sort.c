#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int len_list(t_node *dummy)
{
	int len;
	t_node *ptr;

	ptr = dummy;
	len = 0;
	while (ptr->next != dummy)
	{
		ptr = ptr->next;
		len++;
	}
	return len;
}

int *convert_to_array(t_node *dummy, t_node *another_dummy)
{
	int len;
	int *array;
	t_node *ptr;
	int i;

	len = len_list(dummy);
	array = (int *)malloc(sizeof(int) * len);
	if (!array)
    {
        free_two_lists(dummy, another_dummy);
        // exit();
    }

	ptr = dummy->next;
	i = 0;
	while (i < len)
	{
		array[i] = ptr->key;
		i++;
		ptr = ptr->next;
	}
	return (array);
}

int *sort_num_array(int *array, int len)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}

			j++;
		}
		i++;
	}
	return array;
}

int calculate_median(int *array, int len)
{
	int median;

	if (len % 2 == 0)
	{
		median = \
		(array[len / 2 - 1] + array[len / 2]) / 2;
	}
	else
	{
		median = array[len / 2];
	}
	return median;
}

t_process	*init_process(t_process *process_ptr)
{
	process_ptr = (t_process *)malloc(sizeof(t_process));
	if (!process_ptr)
		return NULL;
	process_ptr->next = process_ptr;
	process_ptr->prev = process_ptr;

	return process_ptr;
}

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
			rotate(list_from);
		else
			push(list_from, list_to);
		i++;
	}
    free(array_a);
    array_a = NULL;
	return len / 2;
}

int smaller_half_first_to_second(t_node *list_from, t_node *list_to)
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
		if (list_from->next->key > median)
			rotate(list_from);
		else
			push(list_from, list_to);
		i++;
	}
    free(array_a);
    array_a = NULL;
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

int main()
{	
	t_node *list_a;
	t_node *list_b;
	t_node *tmp_ptr;
	int i;
	
	list_a = init_node(list_a);
	list_b = init_node(list_b);
	
    set_node_last(3, list_a);
    set_node_last(14, list_a);
    set_node_last(2, list_a);
    set_node_last(13, list_a);
    set_node_last(1, list_a);
    set_node_last(8, list_a);
    set_node_last(9, list_a);
    set_node_last(6, list_a);
    set_node_last(7, list_a);
    set_node_last(11, list_a);
    set_node_last(5, list_a);
    set_node_last(7, list_a);
    set_node_last(12, list_a);
    set_node_last(10, list_a);
    set_node_last(4, list_a);

	tmp_ptr = list_a->next;
	while (tmp_ptr != list_a)
	{
		printf("key: %d\n", tmp_ptr->key);
		tmp_ptr = tmp_ptr->next;
	}
	printf("\n--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

	tmp_ptr = list_b->next;
	while (tmp_ptr != list_b)
	{
		printf("key: %d\n", tmp_ptr->key);
		tmp_ptr = tmp_ptr->next;
	}
	printf("\n--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

	smaller_half_first_to_second(list_a, list_b);
	quick_sort(list_a, list_b);
	larger_half_first_to_second(list_a, list_b);
	quick_sort(list_a, list_b);

	tmp_ptr = list_a->next;
	while (tmp_ptr != list_a)
	{
		printf("key: %d\n", tmp_ptr->key);
		tmp_ptr = tmp_ptr->next;
	}
	printf("\n--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

	tmp_ptr = list_b->next;
	while (tmp_ptr != list_b)
	{
		printf("key: %d\n", tmp_ptr->key);
		tmp_ptr = tmp_ptr->next;
	}
	printf("\n--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	system("leaks a.out");

	return 0;
}