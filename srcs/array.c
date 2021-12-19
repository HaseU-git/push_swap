#include "push_swap.h"

t_num_array	*set_num_array(int *array_elements, int array_len)
{
	t_num_array	*array;

	array = (t_num_array *)malloc(sizeof(t_num_array));
	if (array == NULL)
		return (NULL);
	array->elements = array_elements;
	array->len = array_len;
	return (array);
}

int	len_list(t_node *dummy)
{
	int	len;
	t_node	*ptr;

	ptr = dummy;
	len = 0;
	while (ptr->next != dummy)
	{
		ptr = ptr->next;
		len++;
	}
	return (len);
}

t_num_array	*list_to_array(t_node *dummy)
{
	int	len;
	int	*array;
	t_node	*ptr;
	int	i;

	len = len_list(dummy);
	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	ptr = dummy->next;
	i = 0;
	while (i < len)
	{
		array[i] = ptr->key;
		i++;
		ptr = ptr->next;
	}
	return (set_num_array(len, array));
}

int	calculate_median(t_num_array *array)
{
	int	median;

	if (array->len % 2 == 0)
	{
		median = (array->elements[array->len / 2 - 1] + \
			array->elements[array->len / 2]) / 2;
	}
	else
	{
		median = array->elements[array->len / 2];
	}
	return (median);
}
