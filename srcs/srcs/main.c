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
		put_error();
	}
	return ;
}

void	sort_list(t_node *list_a, t_node *list_b, t_prs *process, int argc)
{
	if (is_sorted(list_a) != 1)
	{
		if (argc - 1 <= 5)
			rule_sort_a(list_a, list_b, process);
		else
		{
			smaller_half_a_to_b(list_a, list_b, process);
			quick_sort(list_a, list_b, process);
			larger_half_a_to_b(list_a, list_b, process);
			quick_sort(list_a, list_b, process);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_node	*list_a;
	t_node	*list_b;
	t_prs	*process;
	char	**str_list;

	str_list = set_args(argc, argv, str_list);
	argc = set_count(argc, str_list);
	arg_check(argc, str_list);
	list_a = init_node(str_list);
	list_b = init_node(str_list);
	list_null_check(list_a, list_b);
	arg_to_list(list_a, list_b, argc, str_list);
	process = init_process(list_a, list_b);
	sort_list(list_a, list_b, process, argc);
	optimize_process(list_a, list_b, process);
	print_process(process);
	return (0);
}
