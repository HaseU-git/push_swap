/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:46:01 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:46:01 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_swap(t_prs *process)
{
	if (process->operation == SA)
		write(1, "sa\n", 3);
	else if (process->operation == SB)
		write(1, "sb\n", 3);
	else if (process->operation == SS)
		write(1, "ss\n", 3);
}

void	put_push(t_prs *process)
{
	if (process->operation == PA)
		write(1, "pa\n", 3);
	else if (process->operation == PB)
		write(1, "pb\n", 3);
}

void	put_rotate(t_prs *process)
{
	if (process->operation == RA)
		write(1, "ra\n", 3);
	else if (process->operation == RB)
		write(1, "rb\n", 3);
	else if (process->operation == RR)
		write(1, "rr\n", 3);
}

void	put_reverse_rotate(t_prs *process)
{
	if (process->operation == RRA)
		write(1, "rra\n", 4);
	else if (process->operation == RRB)
		write(1, "rrb\n", 4);
	else if (process->operation == RRR)
		write(1, "rrr\n", 4);
}
