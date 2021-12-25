#include "push_swap.h"

void show_list(t_node *dummy)
{
	t_node *ptr;
	ptr = dummy->next;

	while (ptr != dummy)
	{
		printf("%d\n", ptr->key);
		ptr = ptr->next;
	}
}

void show_ope(t_prs *dummy)
{
	t_prs *ptr;
	ptr = dummy->next;

	while (ptr != dummy)
	{
		printf("%d\n", ptr->operation);
		ptr = ptr->next;
	}
}

void list_null_check(t_node *list_a, t_node *list_b)
{
	if (list_a == NULL || list_b == NULL)
	{
		if (list_a == NULL && list_b != NULL)
			free_all_nodes(list_b);
		else if (list_a != NULL && list_b == NULL)
			free_all_nodes(list_a);
		else if (list_a == NULL && list_b == NULL)
			free_two_lists(list_a, list_b);
		write(1, "Error\n", 6);
		exit(1);
	}
	return ;
}


int main(int argc, char *argv[])
{
	t_node *list_a;
	t_node *list_b;
	t_prs *process;

	arg_check(argc, argv);
	list_a = NULL;
	list_b = NULL;
	list_a = init_node(list_a);
	list_b = init_node(list_b);
	arg_to_list(list_a, list_b, argc, argv);
	list_null_check(list_a, list_b);
	process = init_process(list_a, list_b);
	if (argc - 1 <= 3)
		rule_sort_a(list_a, list_b, process);
	else
	{
		smaller_half_a_to_b(list_a, list_b, process);
		quick_sort(list_a, list_b, process);
		larger_half_a_to_b(list_a, list_b, process);
		quick_sort(list_a, list_b, process);
	}
	optimize_process(list_a, list_b, process);
	print_process(process);
	printf("%s", "--leaks----\n");
	system("leaks push_swap");
	return (0);
}
