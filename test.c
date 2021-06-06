#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_node
{
	int Key;
	struct s_node *prev;
	struct s_node *next;
}			t_node;

t_node	*init_node(t_node *nil)
{
	nil = (t_node *)malloc(sizeof(t_node));
	nil->next = nil;
	nil->prev = nil;

	return nil;
}

int		main()
{
	t_node *nil;

	nil = init_node(nil);
	printf("%p\n", nil);
	printf("%p\n", nil->next);
	printf("%p\n", nil->prev);
}
