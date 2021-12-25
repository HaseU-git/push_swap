#include "push_swap.h"

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
