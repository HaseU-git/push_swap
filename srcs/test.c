#include "push_swap.h"

int smaller_half_a_to_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	int *num_array;
    int len;
	int median;
	int i;

	num_array = convert_to_array(list_a, list_b);
    len = len_list(list_a);
	sort_num_array(num_array, len);
	median = calculate_median(num_array, len);
    free(num_array);

	i = 0;
	while (i < len / 2)
	{
		if (list_a->next->key > median)
			rotate_a(list_a, list_b, process);
		else
			push_b(list_a, list_b, process);
		i++;
	}
	return len / 2;
}

void show_prs(t_prs *dummy)
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
    t_node *list_a;
    t_node *list_b;
    t_prs *process;


    list_a = init_node(list_a);
    list_b = init_node(list_b);

    set_node_last(1, list_a);
    set_node_last(2, list_a);
    set_node_last(3, list_a);
    set_node_last(4, list_a);
    set_node_last(5, list_a);
    set_node_last(6, list_a);
    set_node_last(7, list_a);
    set_node_last(8, list_a);
    set_node_last(9, list_a);
    set_node_last(10, list_a);
    set_node_last(11, list_a);

    process = init_process(list_a, list_b);
	smaller_half_a_to_b(list_a, list_b, process);

    printf("%s", "---=====--\n");
    show_list(list_a);
    printf("%s", "---------\n");
    show_list(list_b); 

    printf("%s", "---------\n");
    show_prs(process);

}