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

	list_a = init_node(list_a);
	list_b = init_node(list_b);

	arg_to_list(list_a, list_b, argc, argv);

	list_null_check(list_a, list_b);

	process = init_process(list_a, list_b);
	
	printf("%d\n", argc);

	if (argc - 1 <= 3)
		rule_sort_a(list_a, list_b, process);
	else
	{
		smaller_half_a_to_b(list_a, list_b, process);
		quick_sort(list_a, list_b, process);
		larger_half_a_to_b(list_a, list_b, process);
		quick_sort(list_a, list_b, process);
	}

	printf("%s", "---=a===--\n");
	show_list(list_a);
	printf("%s", "----b----\n");
	show_list(list_b);
	printf("%s", "----p----\n");
	print_process(process);
	printf("%s", "--pop_p----\n");
	write_process(pop_index_operation(0, process));
	printf("%s", "----p----\n");
	print_process(process);
	printf("%s", "----insert_p----\n");
	insert_index_operation(process, 1, RRB);
	printf("%s", "----p----\n");
	print_process(process);
	// printf("%s", "--leaks----\n");
	// system("leaks a.out");

	// write(1, "Error\n", 7); //7であってる？  
	// 引数を受け取る  
	// 引数エラーチェック
	// 連想配列に格納する(nodeA, nodeBをマロックする) 
	// mallocのエラーチェック  
	//  クイックソート（Array情報をmallocする）
	// 操作系を格納する  
	// mallocエラーチェック 
	// 出力する関数  
	return (0);
}
