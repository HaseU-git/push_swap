/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:44:48 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:44:50 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_check(int argc, char *argv[])
{
	int	is_error_flag;
	int	i;

	i = 1;
	is_error_flag = 0;
	if (argc == 1)
		exit(0);
	else
	{
		while (i < argc && is_error_flag != 1)
		{
			if (is_num(argv[i]) == 0 || is_int(argv[i]) == 0)
				is_error_flag = 1;
			i++;
		}
	}
	if (is_error_flag == 1)
		put_error();
}

int	is_dupulicated(t_node *list_a)
{
	t_node	*fixed_node;
	t_node	*variable_node;
	int		is_dup_flag;

	fixed_node = list_a->next;
	is_dup_flag = 0;
	while (fixed_node != list_a)
	{
		variable_node = fixed_node->next;
		while (variable_node != list_a)
		{
			if (fixed_node->key == variable_node->key)
				is_dup_flag = 1;
			variable_node = variable_node->next;
		}
		fixed_node = fixed_node->next;
	}
	return (is_dup_flag);
}

int	is_sorted(t_node *list_a)
{
	int		flag_sorted;
	t_node	*ptr;

	flag_sorted = 1;
	ptr = list_a->next;
	while (ptr->next != list_a)
	{
		if (ptr->key > ptr->next->key)
			flag_sorted = 0;
		ptr = ptr->next;
	}
	return (flag_sorted);
}

void	arg_to_list(t_node *list_a, t_node *list_b, int argc, char *argv[])
{
	int		i;
	t_node	*new_node;

	i = 1;
	while (i < argc)
	{
		new_node = set_node_last((int)str_to_num(argv[i]), list_a);
		if (new_node == NULL)
		{
			free_two_lists(list_a, list_b);
			put_error();
		}
		i++;
	}
	if (is_dupulicated(list_a))
	{
		free_two_lists(list_a, list_b);
		put_error();
	}
}
