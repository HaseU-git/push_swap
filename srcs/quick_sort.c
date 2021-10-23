
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

void put_smaller_half_to_b(t_node *list_a, t_node *list_b)
{
	int *array_a;
    int len;
	int median;
	t_node *ptr;
	int i;

	array_a = convert_to_array(list_a, list_b);
    len = len_list(list_a);
	sort_num_array(array_a, len);
	median = calculate_median(array_a, len);

	ptr = list_a->next;
	i = 0;
	while (i < len)
	{
		ptr = ptr->next;
		if (ptr->prev->key > median)
			rotate(list_a);
		else
			push(list_a, list_b);
		i++;
	}
    free(array_a);
    array_a = NULL;
}

int main()
{	
	t_node *stack_a;
	t_node *stack_b;
	t_node *tmp_ptr;
	int i;
	
	stack_a = init_node(stack_a);
	stack_b = init_node(stack_b);
	
    set_node_last(1, stack_a);
    set_node_last(2, stack_a);
    set_node_last(3, stack_a);
    set_node_last(4, stack_a);
    set_node_last(5, stack_a);
    set_node_last(6, stack_a);
    set_node_last(7, stack_a);
    set_node_last(8, stack_a);

	tmp_ptr = stack_a->next;
	while (tmp_ptr != stack_a)
	{
		printf("key: %d\n", tmp_ptr->key);
		tmp_ptr = tmp_ptr->next;
	}
	printf("\n--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

	put_smaller_half_to_b(stack_a, stack_b);

	tmp_ptr = stack_a->next;
	while (tmp_ptr != stack_a)
	{
		printf("key: %d\n", tmp_ptr->key);
		tmp_ptr = tmp_ptr->next;
	}
	printf("\n--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

	tmp_ptr = stack_b->next;
	while (tmp_ptr != stack_b)
	{
		printf("key: %d\n", tmp_ptr->key);
		tmp_ptr = tmp_ptr->next;
	}
	printf("\n--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

	system("leaks a.out");

	return 0;
}
