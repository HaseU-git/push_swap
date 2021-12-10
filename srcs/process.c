
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

void update_process(t_ope operation, t_prs *process, t_node *list_a, t_node *list_b)
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