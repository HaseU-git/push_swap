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

    show_list(list_a);
    
    list_null_check(list_a, list_b);

    process = init_process(list_a, list_b);
	smaller_half_a_to_b(list_a, list_b, process);
	// quick_sort(list_a, list_b);
	// larger_half_first_to_second(list_a, list_b);
	// quick_sort(list_a, list_b);

    // printf("%s", "---=====--\n");
    // show_list(list_a);
    // printf("%s", "---------\n");
    // show_list(list_b);

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
