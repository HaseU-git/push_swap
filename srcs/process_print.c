#include "push_swap.h"

void write_process(t_prs *process)
{
	put_swap(process);
	put_push(process);
	put_rotate(process);
	put_reverse_rotate(process);
}

void print_process(t_prs *process)
{
	t_prs *ptr;

	ptr = process->next;
	while (ptr != process)
	{
		write_process(ptr);
		ptr = ptr->next;
	}
}
