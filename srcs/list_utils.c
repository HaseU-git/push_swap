#include "push_swap.h"

t_node	*pop_first(t_node *dummy)
{
	t_node	*node;

	node = dummy->next;
	dummy->next = dummy->next->next;
	dummy->next->prev = dummy;
	return (node);
}

t_node	*pop_last(t_node *dummy)
{
	t_node *last;
	t_node *node;

	last = dummy;
	while (last->next != dummy)
	{
		last = last->next;
	}
	node = last;
	dummy->prev = dummy->prev->prev;
	dummy->prev->next = dummy;
	return (node);
}

void	add_node_first(t_node *dummy, t_node *node)
{
	node->next = dummy->next;
	dummy->next->prev = node;
	dummy->next = node;
	node->prev = dummy;
}

void	add_node_last(t_node *dummy, t_node *node)
{
	t_node	*last;

	last = dummy;
	while (last->next != dummy)
	{
		last = last->next;
	}
	node->next = last->next;
	last->next->prev = node;
	last->next = node;
	node->prev = last;
}

int len_list(t_node *dummy)
{
	int len;
	t_node *ptr;

	ptr = dummy;
	len = 0;
	while (ptr->next != dummy)
	{
		ptr = ptr->next;
		len++;
	}
	return len;
}
