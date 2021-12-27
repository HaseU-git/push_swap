/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:46:19 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:46:19 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_and_rotate_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	swap_a(list_a, list_b, process);
	rotate_a(list_a, list_b, process);
}

void	rotate_a_and_swap_a(t_node *list_a, t_node *list_b, t_prs *process)
{
	rotate_a(list_a, list_b, process);
	swap_a(list_a, list_b, process);
}

void	swap_b_and_rotate_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	swap_b(list_a, list_b, process);
	rotate_b(list_a, list_b, process);
}

void	rotate_b_and_swap_b(t_node *list_a, t_node *list_b, t_prs *process)
{
	rotate_b(list_a, list_b, process);
	swap_b(list_a, list_b, process);
}
