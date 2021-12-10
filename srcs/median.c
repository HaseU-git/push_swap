
#include "push_swap.h"

int *convert_to_array(t_node *dummy, t_node *another_dummy)
{
	int len;
	int *array;
	t_node *ptr;
	int i;

	len = len_list(dummy);
	array = (int *)malloc(sizeof(int) * len);
	if (array == NULL)
    {
        free_two_lists(dummy, another_dummy);
        write(1, "Error\n", 6);
        exit(1);
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