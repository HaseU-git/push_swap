
#include "push_swap.h"

t_process	*init_process(/*t_node *list_a, t_node *list_b, */t_process *process_ptr)
{
	process_ptr = (t_process *)malloc(sizeof(t_process));
	if (!process_ptr)
    {
        // free_two_lists(list_a, list_b);
        // wirte(1, "Error\n", 6);
		exit(1);
    }
	process_ptr->next = process_ptr;
	process_ptr->prev = process_ptr;

	return process_ptr;
}

t_process	*set_process_last(t_operation operation, t_process *dummy)
{
	t_process		*x;
	t_process		*last;

	x = (t_process *)malloc(sizeof(t_process));
	if (!x)
		return (NULL);
	last = dummy;
	while (last->next != dummy)
	{
		last = last->next;
	}
	x->operation = operation;
	x->next = last->next;
	last->next->prev = x;
	last->next = x;
	x->prev = last;
	return (x);
}

int main()
{
    t_process *test; 
    test = init_process(test);

    set_process_last(SB, test);
    set_process_last(SA, test);
    printf("%d\n", test->next->next->operation);
}