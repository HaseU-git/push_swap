#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

void show_list(t_prs *dummy)
{
    t_prs *ptr;
    ptr = dummy->next;

    while (ptr != dummy)
    {
        printf("%d\n", ptr->operation);
        ptr = ptr->next;
    }
}


int main()
{
    t_prs *process;
    t_node *list_a;
    t_node *list_b;

    list_a = init_node(list_a);
    list_b = init_node(list_b);

    process = init_process(list_a, list_b);
    update_process(PA, process, list_a, list_b);
    update_process(PA, process, list_a, list_b);
    update_process(PA, process, list_a, list_b);
    update_process(PA, process, list_a, list_b);
    update_process(PA, process, list_a, list_b);
    show_list(process);
}