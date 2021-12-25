#include "push_swap.h"

int *list_a_to_array(t_node *list_a, t_node *list_b, t_prs *process)
{
	int len;
	int *array;
	t_node *ptr;
	int i;

	len = len_list(list_a);
	array = (int *)malloc(sizeof(int) * len);
	if (array == NULL)
	{
		free_two_lists(list_a, list_b);
		free_all_process(process);
		write(1, "Error\n", 6);
		exit(1);
	}

	ptr = list_a->next;
	i = 0;
	while (i < len)
	{
		array[i] = ptr->key;
		i++;
		ptr = ptr->next;
	}
	return (array);
}

int *list_b_to_array(t_node *list_a, t_node *list_b, t_prs *process)
{
	int len;
	int *array;
	t_node *ptr;
	int i;

	len = len_list(list_b);
	array = (int *)malloc(sizeof(int) * len);
	if (array == NULL)
	{
		free_two_lists(list_a, list_b);
		free_all_process(process);
		write(1, "Error\n", 6);
		exit(1);
	}

	ptr = list_b->next;
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
		median = (array[len / 2 - 1] / 2 + array[len / 2] / 2);
	else
		median = (array[len / 2]);
	return median;
}
