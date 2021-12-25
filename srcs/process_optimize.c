#include "push_swap.h"

void optimize_process(t_node *list_a, t_node *list_b, t_prs *process)
{
	t_prs *ptr;
	int index;

	index = 0;
	ptr = process->next;
	while (ptr != process)
	{
		optimize_r_to_rr(list_a, list_b, process, index);
		ptr = ptr->next;
		index = index + 1;
	}
	return ;
}

void optimize_r_to_rr(t_node *list_a, t_node *list_b, t_prs *process, int index)
{
	t_prs *ptr;
	int num;

	num = 0;
	ptr = process->next;
	while (num < index)
	{
		num = num + 1;
		ptr = ptr->next;
	}
	if ((ptr->operation == RA && ptr->next->operation == RB) || (ptr->operation == RB && ptr->next->operation == RA))
	{
		pop_index_operation(index, process);
		pop_index_operation(index, process);
		ptr = insert_index_operation(process, index, RR);
		if (ptr == NULL)
		{
			free_two_lists(list_a, list_b);
			free_all_process(process);
			put_error();
		}
	}
	return ;
}
