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

	ptr = process->next;
	while (ptr != process)
	{
		ptr = opt_rr(ptr);
		ptr = opt_rrr(ptr);
		ptr = opt_ss(ptr);
		ptr = optimize_rm_extra(ptr);
		ptr = ptr->next;
	}
	return ;
}

t_prs	*opt_ss(t_prs *process)
{
	t_prs	*ptr;

	ptr = process;
	if ((ptr->operation == SA && ptr->next->operation == SB) || \
	(ptr->operation == SB && ptr->next->operation == SA))
	{
		ptr = ptr->next;
		delete_index_operation(process);
		ptr->operation = SS;
	}
	return (ptr);
}

t_prs	*opt_rrr(t_prs *process)
{
	t_prs	*ptr;

	ptr = process;
	if ((ptr->operation == RRA && ptr->next->operation == RRB) || \
	(ptr->operation == RRB && ptr->next->operation == RRA))
	{
		ptr = process->next;
		delete_index_operation(process);
		ptr->operation = RRR;
	}
	return (ptr);
}

t_prs	*opt_rr(t_prs *process)
{
	t_prs	*ptr;

	ptr = process;
	if ((ptr->operation == RA && ptr->next->operation == RB) || \
	(ptr->operation == RB && ptr->next->operation == RA))
	{
		ptr = process->next;
		delete_index_operation(process);
		ptr->operation = RR;
	}
	return (ptr);
}

t_prs	*optimize_rm_extra(t_prs *process)
{
	t_prs	*ptr;

	ptr = process;
	if ((ptr->operation == RRA && ptr->next->operation == RA) || \
	(ptr->operation == RA && ptr->next->operation == RRA) || \
	(ptr->operation == RRB && ptr->next->operation == RB) || \
	(ptr->operation == RB && ptr->next->operation == RRB) || \
	(ptr->operation == PB && ptr->next->operation == PA) || \
	(ptr->operation == PA && ptr->next->operation == PB))
	{
		ptr = process->next;
		delete_index_operation(process);
		process = ptr->next;
		delete_index_operation(ptr);
		ptr = process->prev;
	}
	return (ptr);
}
