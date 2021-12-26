/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_optimize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:45:55 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:45:55 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_process(t_node *list_a, t_node *list_b, t_prs *process)
{
	t_prs	*ptr;
	int		index;
	int		is_optimized;
	int		is_remove;

	index = 0;
	ptr = process->next;
	while (ptr != process)
	{
		is_optimized = 0;
		is_remove = 0;
		is_optimized += opt_rr(list_a, list_b, process, index);
		is_optimized += opt_rrr(list_a, list_b, process, index);
		is_optimized += opt_ss(list_a, list_b, process, index);
		is_remove = optimize_rm_extra(process, index);
		ptr = ptr->next;
		index = index + 1;
		if (is_optimized != 0)
			index = index - 1 * is_optimized;
		if (is_remove != 0)
			index = index - 2;
	}
	return ;
}

int	opt_ss(t_node *list_a, t_node *list_b, t_prs *process, int index)
{
	t_prs	*ptr;
	int		num;

	num = 0;
	ptr = process->next;
	while (num < index)
	{
		num = num + 1;
		ptr = ptr->next;
	}
	if ((ptr->operation == SA && ptr->next->operation == SB) || \
	(ptr->operation == SB && ptr->next->operation == SA))
	{
		delete_index_operation(index, process);
		delete_index_operation(index, process);
		ptr = insert_index_operation(process, index, SS);
		if (ptr == NULL)
			free_error_exit(list_a, list_b, process);
		return (1);
	}
	return (0);
}

int	opt_rrr(t_node *list_a, t_node *list_b, t_prs *process, int index)
{
	t_prs	*ptr;
	int		num;

	num = 0;
	ptr = process->next;
	while (num < index)
	{
		num = num + 1;
		ptr = ptr->next;
	}
	if ((ptr->operation == RRA && ptr->next->operation == RRB) || \
	(ptr->operation == RRB && ptr->next->operation == RRA))
	{
		delete_index_operation(index, process);
		delete_index_operation(index, process);
		ptr = insert_index_operation(process, index, RRR);
		if (ptr == NULL)
			free_error_exit(list_a, list_b, process);
		return (1);
	}
	return (0);
}

int	opt_rr(t_node *list_a, t_node *list_b, t_prs *process, int index)
{
	t_prs	*ptr;
	int		num;

	num = 0;
	ptr = process->next;
	while (num < index)
	{
		num = num + 1;
		ptr = ptr->next;
	}
	if ((ptr->operation == RA && ptr->next->operation == RB) || \
	(ptr->operation == RB && ptr->next->operation == RA))
	{
		delete_index_operation(index, process);
		delete_index_operation(index, process);
		ptr = insert_index_operation(process, index, RR);
		if (ptr == NULL)
			free_error_exit(list_a, list_b, process);
		return (1);
	}
	return (0);
}

int	optimize_rm_extra(t_prs *process, int index)
{
	t_prs	*ptr;
	int		num;

	num = 0;
	ptr = process->next;
	while (num < index)
	{
		num = num + 1;
		ptr = ptr->next;
	}
	if ((ptr->operation == RRA && ptr->next->operation == RA) || \
	(ptr->operation == RA && ptr->next->operation == RRA) || \
	(ptr->operation == RRB && ptr->next->operation == RB) || \
	(ptr->operation == RB && ptr->next->operation == RRB) || \
	(ptr->operation == PB && ptr->next->operation == PA) || \
	(ptr->operation == PA && ptr->next->operation == PB))
	{
		delete_index_operation(index, process);
		delete_index_operation(index, process);
		return (1);
	}
	return (0);
}
