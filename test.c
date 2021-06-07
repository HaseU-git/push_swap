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
t_node	*insert(int key, t_node **node)
{
	t_node *x;

	x = (t_node *)malloc(sizeof(t_node));
	if (!x)
		return NULL;
	x->key = key;
	x->next = (*node)->next;
	(*node)->next->prev = x;
	(*node)->next = x;
	x->prev = (*node);

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

int		main()
{
 	t_node *nil;
 
 	nil = init_node(nil);
 	printf("%p\n", nil);
 	printf("%p\n", nil->next);
 	printf("%p\n", nil->prev);
 
 	t_node *x;
 	
 	x = insert(99, &nil);
 	printf("%d\n", x->key);
 	printf("%p\n", x);

// 	delete_node(&x, nil);
//	printf("%d\n", x->key);
//	printf("%p\n", x);

//	free(nil->prev);
//	free(nil->next);
	nil->prev = NULL;
	nil->next = NULL;

	free(nil);
	nil = NULL;

//もしmallocがうまくできたら以下の挙動になる  
//	int	*test = (int *)malloc(999999999);
//	free(test);

	system("leaks a.out");

	return 0;
}
