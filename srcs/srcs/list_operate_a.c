/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operate_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:45:35 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:45:36 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	t_node	*first;
	t_node	*second;

	first = pop_first(list_a);
	second = pop_first(list_a);
	add_node_first(list_a, first);
	add_node_first(list_a, second);
	update_prcs(list_a, list_b, process, SA);
}

void	rotate_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	add_node_last(list_a, pop_first(list_a));
	update_prcs(list_a, list_b, process, RA);
}

void	r_rotate_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	add_node_first(list_a, pop_last(list_a));
	update_prcs(list_a, list_b, process, RRA);
}

void	push_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	add_node_first(list_a, pop_first(list_b));
	update_prcs(list_a, list_b, process, PA);
}
