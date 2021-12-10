#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_node
{
	int key;
	struct s_node *prev;
	struct s_node *next;
}			t_node;

// return NULL if malloc fail
t_node	*init_node(t_node *node)
{
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return NULL;
	node->next = node;
	node->prev = node;

	return node;
}

// return NULL if malloc fail
t_node	*insert_first(int key, t_node *node)
{
	t_node *x;

	x = (t_node *)malloc(sizeof(t_node));
	if (!x)
		return NULL;
	x->key = key;
	x->next = node->next;
	node->next->prev = x;
	node->next = x;
	x->prev = node;

	return x;
}

// なんでnilだっったらreturn？  
void	delete_node(t_node **t, t_node *nil)
{
	if ((*t) == nil)
		return ;
	(*t)->prev->next = (*t)->next;
	(*t)->next->prev = (*t)->prev;
	free(*t);
	(*t) = NULL;
}

t_node	*insert_last(int key, t_node *nil)
{
	t_node *x;
	t_node *last;

	x = (t_node *)malloc(sizeof(t_node));
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

t_node	*pop(t_node *nil)
{
	t_node *ret;

	ret = nil->next;
	nil->next = nil->next->next;
	nil->next->prev = nil;
	return ret;
}

t_node	*pop_last(t_node *nil)
{
	t_node *last;
	t_node *ret;

	last = nil;
	while (last->next != nil)
	{
		last = last->next;
	}
	ret = last;
	nil->prev = nil->prev->prev;
	nil->prev->next = nil;
	return ret;
}

void	add_pointer_first(t_node *nil, t_node *to_add)
{
	to_add->next = nil->next;
	nil->next->prev = to_add;
	nil->next = to_add;
	to_add->prev = nil;
}

void	add_pointer_last(t_node *nil, t_node *to_add)
{
	t_node *last;
	
	last = nil;
	while (last->next != nil)
	{
		last = last->next;
	}
	to_add->next = last->next;
	last->next->prev = to_add;
	last->next = to_add;
	to_add->prev = last;
}

void	swap(t_node *nil)
{
	t_node *first;
	t_node *second;

	first = pop(nil);
	second = pop(nil);
	add_pointer_first(nil, first);
	add_pointer_first(nil, second);
}

void	rotate(t_node *list_to_do, t_node list_another, )
{
	add_pointer_last(nil, pop(nil));
}

void	reverse_rotate(t_node *nil)
{
	add_pointer_first(nil, pop_last(nil));
}

void	push(t_node *stack_one, t_node *stack_two)
{
	add_pointer_first(stack_two, pop(stack_one));
}

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
};

typedef	struct  s_num_array
{
	int *elements;
	int len;
}			t_num_array;


t_num_array *substitute_for_array(int *array_elements, int array_len)
{
	t_num_array *array_info;

	array_info = (t_num_array *)malloc(sizeof(t_num_array));
	if (array_info == NULL)
		return NULL;
	array_info->elements = array_elements;
	array_info->len = array_len;
	return array_info;
}

int count_list_elements(t_node *nil)
{
	int list_len;
	t_node *list_ptr;

	list_ptr = nil;
	list_len = 0;
	while (list_ptr->next != nil)
	{
		list_ptr = list_ptr->next;
		list_len++;
	}
	return list_len;
}

t_num_array *convert_to_array(t_node *nil)
{
	int list_len;
	int *unsorted_array;
	t_node *list_ptr;
	int i;

	list_len = count_list_elements(nil);
	unsorted_array = (int *)malloc(sizeof(int) * list_len);
	if (!unsorted_array)
		return NULL;
	list_ptr = nil->next;
	i = 0;
	while (i < list_len)
	{
		unsorted_array[i] = list_ptr->key;
		i++;
		list_ptr = list_ptr->next;
	}
	return (substitute_for_array(unsorted_array, list_len));
}

t_num_array *sort_num_array(t_num_array *array_info)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < array_info->len)
	{
		j = i + 1;
		while (j < array_info->len)
		{
			if (array_info->elements[i] > array_info->elements[j])
			{
				tmp = array_info->elements[i];
				array_info->elements[i] = array_info->elements[j];
				array_info->elements[j] = tmp;
			}

			j++;
		}
		i++;
	}
	return array_info;
}

int calculate_median(t_num_array *array_info)
{
	int array_median;

	if (array_info->len % 2 == 0)
	{
		array_median = \
		(array_info->elements[array_info->len / 2 - 1] + \
		array_info->elements[array_info->len / 2]) / 2;
	}
	else
	{
		array_median = array_info->elements[array_info->len / 2];
	}
	return array_median;
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

void put_smaller_half_to_b(t_node *stack_a_nil, t_node *stack_b_nil)
{
    t_num_array *array_a;
    int array_median;
    t_node *current_ptr;
    int i;

    array_a = convert_to_array(stack_a_nil);
    sort_num_array(array_a);
    array_median = calculate_median(array_a);
    
    current_ptr = stack_a_nil->next;
    i = 0;
    while (i < array_a->len)
    {
        current_ptr = current_ptr->next;
        if (current_ptr->prev->key > array_median)
            rotate(stack_a_nil);
        else
            push(stack_a_nil, stack_b_nil);
        i++;
    }
}


int main()
{
	t_node *stack_a;
	t_node *stack_b;
	t_node *tmp_ptr;
	
 	stack_a = init_node(stack_a);
 	stack_b = init_node(stack_b);

	insert_last(1, stack_a);
	insert_last(2, stack_a);
	insert_last(3, stack_a);
	insert_last(4, stack_a);
	insert_last(5, stack_a);
	insert_last(6, stack_a);
	insert_last(7, stack_a);
	insert_last(8, stack_a);

	tmp_ptr = stack_a->next;
    while (tmp_ptr != stack_a)
	{
        printf("key: %d\n", tmp_ptr->key);
		tmp_ptr = tmp_ptr->next;
	}
    printf("\n--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

	put_smaller_half_to_b(stack_a, stack_b);

	tmp_ptr = stack_a->next;
    while (tmp_ptr != stack_a)
	{
        printf("key: %d\n", tmp_ptr->key);
		tmp_ptr = tmp_ptr->next;
	}
    printf("\n--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

	tmp_ptr = stack_b->next;
    while (tmp_ptr != stack_b)
	{
        printf("key: %d\n", tmp_ptr->key);
		tmp_ptr = tmp_ptr->next;
	}
    printf("\n--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    
	free(stack_a->next);
	free(stack_a->prev);
	free(stack_a);
	free(stack_b->next);
	free(stack_b->prev);
	free(stack_b);

	system("leaks a.out");

	return 0;
}
