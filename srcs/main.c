/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:45:46 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:45:47 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_list(t_node *dummy)
{
	t_node	*ptr;

	ptr = dummy->next;
	while (ptr != dummy)
	{
		printf("%d\n", ptr->key);
		ptr = ptr->next;
	}
}

void	show_ope(t_prs *dummy)
{
	t_prs	*ptr;

	ptr = dummy->next;
	while (ptr != dummy)
	{
		printf("%d\n", ptr->operation);
		ptr = ptr->next;
	}
}

void	list_null_check(t_node *list_a, t_node *list_b)
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

void	split_sort(t_node *list_a, t_node *list_b, t_prs *process)
{
	smaller_half_a_to_b(list_a, list_b, process);
	quick_sort(list_a, list_b, process);
	larger_half_a_to_b(list_a, list_b, process);
	quick_sort(list_a, list_b, process);
}

int	main(int argc, char *argv[])
{
	t_node	*list_a;
	t_node	*list_b;
	t_prs	*process;

	arg_check(argc, argv);
	list_a = init_node();
	list_b = init_node();
	arg_to_list(list_a, list_b, argc, argv);
	list_null_check(list_a, list_b);
	process = init_process(list_a, list_b);
	if (is_sorted(list_a) != 1)
	{
		if (argc - 1 <= 5)
			rule_sort_a(list_a, list_b, process);
		else
			split_sort(list_a, list_b, process);
	}
//	update_prcs(list_a, list_b, process, RA);
//	update_prcs(list_a, list_b, process, RRA);
//	update_prcs(list_a, list_b, process, SA);
//	update_prcs(list_a, list_b, process, SB);
//	update_prcs(list_a, list_b, process, SB);
//	update_prcs(list_a, list_b, process, SA);
//	update_prcs(list_a, list_b, process, RB);
//	update_prcs(list_a, list_b, process, RRB);
	optimize_process(list_a, list_b, process);
	print_process(process);
	//system("leaks push_swap");
	return (0);
}
