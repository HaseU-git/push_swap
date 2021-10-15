#include "push_swap.h"

t_node	*init_node(t_node *dummy)
{
	dummy = (t_node *)malloc(sizeof(t_node));
	if (!dummy)
		return NULL;
	dummy->next = dummy;
	dummy->prev = dummy;
	return (dummy)
}

t_node	*set_node_first(int key, t_node *dummy)
{
	t_node		*x;

	x = (t_node *)malloc(sizeof(t_node));
	if (!x)
		return (NULL);
	x->key = key;
	x->next = dummy->next;
	dummy->next->prev = x;
	dummy->next = x;
	x->prev = dummy;
	return (x);
}

void	delete_node(t_node **t, t_node *dummy)
{
	if ((*t) == dummy)
		return ;
	(*t)->prev->next = (*t)->next;
	(*t)->next->prev = (*t)->prev;
	free(*t);
	(*t) = NULL;
}

t_node	*set_node_first(int key, t_node *dummy)
{
	t_node		*x;
	t_node		*last;

	x = (t_node *)malloc(sizeof(t_node));
	if (!x)
		return (NULL);
	last = dummy;
	while (last->next != dummy)
	{
		last = last->next;
	}
	x->key = key;
	x->next = last->next;
	last->next->prev = x;
	last->next = x;
	x->prev = last;
	return (x);
}
