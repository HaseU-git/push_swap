#include "push_swap.h"

void optimize_process(t_prs *process)
{
	t_prs ptr;
	
	ptr = process->next;
	while (ptr != process)
	{
		if (ptr->operation == RA && ptr->operation == RB)
		{

		}
		ptr = ptr->process;
		
	}
}

// 

void optimize_rotate(t_prs *process)
{
	t_prs ptr;
	
	ptr = process->next;
	while (ptr != process)
	{
		ptr = ptr->process;
	}
}
