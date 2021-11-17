#include "push_swap.h"

// テストしてない
void    free_all_nodes(t_node *dummy)
{
    t_node    *ptr;
    t_node    *tmp;

    ptr = dummy->next;
    while (ptr != dummy)
    {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
    free(ptr);
    return ;
}

void    free_two_lists(t_node *list_a, t_node *list_b)
{
    free_all_nodes(list_a);
    free_all_nodes(list_b);
}