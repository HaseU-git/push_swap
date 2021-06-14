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
	t_node *ret;

	ret = nil->next;
	nil->next = nil->next->next;
	nil->next->prev = nil;
	return ret;
}

t_node	*pop_last(t_node *nil)
{
	t_node *last;
	t_node *ret;

	last = nil;
	while (last->next != nil)
	{
		last = last->next;
	}
	ret = last;
	nil->prev = nil->prev->prev;
	nil->prev->next = nil;
	return ret;
}

void	add_pointer_first(t_node *nil, t_node *to_add)
{
	to_add->next = nil->next;
	nil->next->prev = to_add;
	nil->next = to_add;
	to_add->prev = nil;
}

void	add_pointer_last(t_node *nil, t_node *to_add)
{
	t_node *last;
	
	last = nil;
	while (last->next != nil)
	{
		last = last->next;
	}
	to_add->next = last->next;
	last->next->prev = to_add;
	last->next = to_add;
	to_add->prev = last;
}

void	swap(t_node *nil)
{
	t_node *first;
	t_node *second;

	first = pop(nil);
	second = pop(nil);
	add_pointer_first(nil, first);
	add_pointer_first(nil, second);
}

void	rotate(t_node *nil)
{
	return (add_pointer_last(nil, pop(nil)));
}

void	reverse_rotate(t_node *nil)
{
	return (add_pointer_first(nil, pop_last(nil)));
}

int		main()
{
 	t_node *nil;
 
 	nil = init_node(nil);
 	printf("%p\n", nil);
 	printf("%p\n", nil->next);
 	printf("%p\n", nil->prev);
 
 	t_node *x;
 	
 	x = insert_first(99, nil);
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
	insert_first(98, nil);



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

	swap(nil);

	printf("----------\n");
	test = nil;
	while (test->next!= nil)
	{
		printf("%d\n", test->key);
		test = test->next;
	}
	printf("%d\n", test->key);
	printf("%d\n", test->next->key);
	printf("----------\n");

	rotate(nil);
	printf("----------\n");
	test = nil;
	while (test->next!= nil)
	{
		printf("%d\n", test->key);
		test = test->next;
	}
	printf("%d\n", test->key);
	printf("%d\n", test->next->key);
	printf("----------\n");

	reverse_rotate(nil);
	printf("----------\n");
	test = nil;
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
