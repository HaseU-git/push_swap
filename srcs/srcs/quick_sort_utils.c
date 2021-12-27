/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:46:05 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:46:06 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	larger_half_b_to_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	int	*array_b;
	int	len;
	int	median;
	int	i;
	int	min;

	array_b = list_b_to_array(list_a, list_b, process);
	len = len_list(list_b);
	sort_num_array(array_b, len);
	median = calculate_median(array_b, len);
	min = array_b[0];
	free(array_b);
	i = -1;
	while (++i < len)
	{
		if (list_b->next->key == min)
			b_to_taila_n(list_a, list_b, process, 1);
		else if (list_b->next->key <= median)
			rotate_b(list_a, list_b, process);
		else
			push_a(list_a, list_b, process);
	}
	return (len / 2);
}

int	larger_half_a_to_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	int	*array_a;
	int	len;
	int	median;
	int	i;

	array_a = list_a_to_array(list_a, list_b, process);
	len = len_list(list_a);
	sort_num_array(array_a, len);
	median = calculate_median(array_a, len);
	free(array_a);
	i = 0;
	while (i < len)
	{
		if (list_a->next->key <= median)
			rotate_a(list_a, list_b, process);
		else
			push_b(list_a, list_b, process);
		i++;
	}
	return (len / 2);
}

int	smaller_half_a_to_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	int	*num_array;
	int	len;
	int	median;
	int	i;

	num_array = list_a_to_array(list_a, list_b, process);
	len = len_list(list_a);
	sort_num_array(num_array, len);
	median = calculate_median(num_array, len);
	free(num_array);
	i = 0;
	while (i < len)
	{
		if (list_a->next->key > median)
			rotate_a(list_a, list_b, process);
		else
			push_b(list_a, list_b, process);
		i++;
	}
	return (len / 2);
}

void	a_to_headb_n(t_node *list_a, t_node *list_b, t_prs *process, int n)
{
	int	cnt;

	cnt = 0;
	while (cnt < n)
	{
		push_b(list_a, list_b, process);
		cnt++;
	}
}

void	b_to_taila_n(t_node *list_a, t_node *list_b, t_prs *process, int n)
{
	int	cnt;

	cnt = 0;
	while (cnt < n)
	{
		push_a(list_a, list_b, process);
		rotate_a(list_a, list_b, process);
		cnt++;
	}
}
