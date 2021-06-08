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
t_node	*insert_first(int key, t_node *node)
{
	t_node *x;

	x = (t_node *)malloc(sizeof(t_node));
	if (!x)
		return NULL;
	x->key = key;
	x->next = node->next;
	node->next->prev = x;
	node->next = x;
	x->prev = node;

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

t_node	*insert_last(int key, t_node *nil)
{
	t_node *x;
	t_node *last;

	x = (t_node *)malloc(sizeof(t_node));
	if (!x)
		return NULL;
	last = nil;
	while (last->next != nil)
	{
		last = last->next;
	}
	x->key = key;
	x->next = last->next;
	last->next->prev = x;
	last->next = x;
	x->prev = last;

	return x;
}


t_node	*pop(t_node *nil)
{
	return nil->next;
}

int		main()
{
 	t_node *nil;
 
 	nil = init_node(nil);
 	printf("%p\n", nil);
 	printf("%p\n", nil->next);
 	printf("%p\n", nil->prev);
 
 	t_node *x;
 	
 	x = insert_first(99, &nil);
 	printf("%d\n", x->key);
 	printf("%p\n", x);

// 	delete_node(&x, nil);
//	printf("%d\n", x->key);
//	printf("%p\n", x);

//	free(nil->prev);
//	free(nil->next);
//	nil->prev = NULL;
//	nil->next = NULL;

//	printf("%d\n", pop(nil)->key);

	t_node *last = insert_last(100, nil);
	printf("%d\n", last->key);

	insert_last(101, nil);
	insert_first(98, &nil);

	printf("----------\n");
	t_node *test = nil;
	while (test->next!= nil)
	{
		printf("%d\n", test->key);
		test = test->next;
	}
	printf("%d\n", test->key);
	printf("%d\n", test->next->key);
	printf("----------\n");

	free(nil);
	nil = NULL;


//もしmallocがうまくできたら以下の挙動になる  
//	int	*test = (int *)malloc(999999999);
//	free(test);

	system("leaks a.out");

	return 0;
}
