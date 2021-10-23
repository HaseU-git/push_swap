#include "push_swap.h"


// テストしてない
void    free_all_nodes(t_node *dummy)
{
    t_node *ptr;

    ptr = dummy->next;
    while (ptr != dummy)
    {
        free(ptr);
        ptr = ptr->next;
    }
    free(ptr);
    ptr = NULL
    return ;
}

void    free_