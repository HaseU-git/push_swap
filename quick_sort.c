typedef struct  s_process
{
    enum e_operation    *operation;
    struct s_process    *prev;
    struct s_process    *next;
}               t_process;

enum   e_operation 
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
}

t_process	*init_process(t_process *process_ptr)
{
	process_ptr = (t_process *)malloc(sizeof(t_process));
	if (!process_ptr)
		return NULL;
	process_ptr->next = process_ptr;
	process_ptr->prev = process_ptr;

	return process_ptr;
}

t_process	*append_process(char *process, t_process *node)
{
	t_process *x;

	x = (t_process *)malloc(sizeof(t_process));
	if (!x)
		return NULL;
	last = nil;
	while (last->next != nil)
	{
		last = last->next;
	}
	x->key = key;
	x->next = last->next;
	last->next->prev = x;
	last->next = x;
	x->prev = last;

	return x;
}

void put_smaller_half_to_b(t_node *stack_a_nil, t_node *stack_b_nil)
{
    t_num_array *list_a;
    int array_median;
    t_node  *current_ptr;

    list_a = convert_to_array(stack_a_nil);
    sort_num_array(list_a);
    array_median = calculate_median(test_array);
    
    current_ptr = stack_a_nil->next;
    while (current_ptr != stack_a_nil)
    {
        if (current_ptr->key < array_median)
            rotate(stack_a_nil);
        else
            push(stack_a, stack_b);
        current_ptr = current_ptr->next;
    }
}