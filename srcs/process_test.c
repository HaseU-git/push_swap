#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef enum   e_ope 
{
    SA,
    SB,
    SS,
    PA,
    PB,
    RA,
    RB,
    RR,
    RRA,
    RRB,
    RRR
} t_ope;


typedef struct s_prs
{
	t_ope operation;
	struct s_prs *prev;
	struct s_prs *next;
} t_prs;

void put_error(t_prs *process)
{
    free(process);
    write(1, "Error\n", 6);
    exit(0);
}

t_prs *init_process()
{
    t_prs *process;

    process = (t_prs *)malloc(sizeof(t_prs));
    if (process == NULL)
    {
        return NULL;
    }
    process->next = process;
	process->prev = process;

	return process;
}

void update_process(t_ope operation, t_prs *process)
{
   	t_prs		*new;
	t_prs		*last;

	new = (t_prs *)malloc(sizeof(t_prs));
	if (!new)
    {
       put_error(process);
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

    process = init_process();
    update_process(PA, process);
    update_process(PA, process);
    update_process(PA, process);
    update_process(PA, process);
    update_process(PA, process);
    update_process(PA, process);
    show_list(process);
}