#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_node
{
	int key;
	struct s_node *prev;
	struct s_node *next;
}			t_node;

t_node	*init_node(t_node *node)
{
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return NULL;
	node->next = node;
	node->prev = node;

	return node;
}

t_node	*insert(int key, t_node **node)
{
	t_node *x;

	x = (t_node *)malloc(sizeof(t_node));
	x->key = key;
	x->next = *node->next;
	*node->next->prev = x;
	*node->next = x;
	x->prev = *node;

	return x;
}

int		main()
{
	t_node *node;

	node = init_node(node);
	printf("%p\n", node);
	printf("%p\n", node->next);
	printf("%p\n", node->prev);

	t_node *x;
	
	x = insert(99, &node);
	printf("%d\n", *x);
}
