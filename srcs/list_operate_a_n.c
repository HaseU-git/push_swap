/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operate_a_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:45:33 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:45:33 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_n(t_node *list_a, t_node *list_b, t_prs *process, int n)
{
	int	count;

	count = 0;
	while (count < n)
	{
		rotate_a(list_a, list_b, process);
		count = count + 1;
	}
}

void	r_rotate_an(t_node *list_a, t_node *list_b, t_prs *process, int n)
{
	int	count;

	count = 0;
	while (count < n)
	{
		r_rotate_a(list_a, list_b, process);
		count = count + 1;
	}
}
