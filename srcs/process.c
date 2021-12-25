#include "push_swap.h"

void put_error()
{
	write(1, "Error\n", 6);
	exit(0);
}

t_prs *init_process(t_node *list_a, t_node *list_b)
{
	t_prs *process;

	process = (t_prs *)malloc(sizeof(t_prs));
	if (process == NULL)
	{
		free_two_lists(list_a, list_b);
		put_error();
	}
	process->next = process;
	process->prev = process;

	return process;
}


t_prs *pop_index_operation(int index, t_prs *process)
{
	int num;
	t_prs *ptr;

	num = 0;
	process = process->next;
	while (num < index)
	{
		process = process->next;
		num = num + 1;
	}
	ptr = process;
	process = process->prev;
	process->next = process->next->next;
	process->next->prev = process;
	return (ptr);
}

t_prs *insert_index_operation(t_prs *process, int index, t_ope new_ope)
{
	int num;
	t_prs *new_ptr;

	new_ptr = (t_prs *)malloc(sizeof(t_prs));
	if (!new_ptr)
		return (NULL);
	num = 0;
	process = process->next;
	while (num < index)
	{
		process = process->next;
		num = num + 1;
	}
	new_ptr->operation = new_ope;
	process->prev->next = new_ptr;
	new_ptr->prev = process->prev;
	process->prev = new_ptr;
	new_ptr->next = process;
	return (new_ptr);
}

void update_process(t_node *list_a, t_node *list_b, t_prs *process, t_ope operation)
{
	t_prs		*new;
	t_prs		*last;

	new = (t_prs *)malloc(sizeof(t_prs));
	if (new == NULL)
	{
		free_all_process(process);
		free_two_lists(list_a, list_b);
		put_error();
	}
	last = process;
	while (last->next != process)
	{
		last = last->next;
	}
	new->operation = operation;
	new->next = last->next;
	last->next->prev = new;
	last->next = new;
	new->prev = last;
}
