/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_sort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:46:13 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:46:14 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rule_sort_five_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	int		*array;
	int		min;
	t_node	*ptr;
	int		index;

	array = list_a_to_array(list_a, list_b, process);
	array = sort_num_array(array, 5);
	min = array[0];
	free(array);
	index = 0;
	ptr = list_a->next;
	while (ptr->key != min)
	{
		ptr = ptr->next;
		index = index + 1;
	}
	if (index < 3)
		rotate_a_n(list_a, list_b, process, index);
	else if (index >= 3)
		r_rotate_an(list_a, list_b, process, 5 - index);
	push_b(list_a, list_b, process);
	rule_sort_four_a(list_a, list_b, process);
	push_a(list_a, list_b, process);
}

void	rule_sort_four_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	int		*array;
	int		min;
	t_node	*ptr;
	int		index;

	array = list_a_to_array(list_a, list_b, process);
	array = sort_num_array(array, 4);
	min = array[0];
	free(array);
	index = 0;
	ptr = list_a->next;
	while (ptr->key != min)
	{
		ptr = ptr->next;
		index = index + 1;
	}
	if (index < 3)
		rotate_a_n(list_a, list_b, process, index);
	else if (index == 3)
		r_rotate_an(list_a, list_b, process, 1);
	push_b(list_a, list_b, process);
	rule_sort_three_a(list_a, list_b, process);
	push_a(list_a, list_b, process);
}

void	rule_sort_three_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	int	first;
	int	second;
	int	third;

	first = list_a->next->key;
	second = list_a->next->next->key;
	third = list_a->next->next->next->key;
	if (first < second && second > third && first < third)
		swap_a_and_rotate_a(list_a, list_b, process);
	else if (first < second && second > third && first > third)
		r_rotate_a(list_a, list_b, process);
	else if (first > second && second < third && first < third)
		swap_a(list_a, list_b, process);
	else if (first > second && second < third && first > third)
		rotate_a(list_a, list_b, process);
	else if (first > second && second > third && first > third)
		rotate_a_and_swap_a(list_a, list_b, process);
}

void	rule_sort_two_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	if (list_a->next->key > list_a->next->next->key)
		rotate_a(list_a, list_b, process);
}

void	rule_sort_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	int	len_list_a;

	len_list_a = len_list(list_a);
	if (len_list_a == 2)
		rule_sort_two_a(list_a, list_b, process);
	else if (len_list_a == 3)
		rule_sort_three_a(list_a, list_b, process);
	else if (len_list_a == 4)
		rule_sort_four_a(list_a, list_b, process);
	else if (len_list_a == 5)
		rule_sort_five_a(list_a, list_b, process);
}
