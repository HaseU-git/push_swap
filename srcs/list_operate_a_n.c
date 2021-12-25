#include "push_swap.h"

void	rotate_a_n(t_node *list_a, t_node *list_b, t_prs *process, int n)
{
	int count;

	count = 0;
	while (count < n)
	{
		rotate_a(list_a, list_b, process);
		count = count + 1;
	}
}

void	reverse_rotate_a_n(t_node *list_a, t_node *list_b, t_prs *process, int n)
{
	int count;

	count = 0;
	while (count < n)
	{
		reverse_rotate_a(list_a, list_b, process);
		count = count + 1;
	}
}