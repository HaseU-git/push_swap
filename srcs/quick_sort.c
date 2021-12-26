/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:46:11 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:46:11 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_node *list_a, t_node *list_b, t_prs *process)
{
	int	len;
	int	cnt;

	len = len_list(list_b);
	if (len <= 5)
	{
		rule_sort_b(list_a, list_b, process);
		b_to_taila_n(list_a, list_b, process, len);
		return ;
	}
	cnt = larger_half_b_to_a(list_a, list_b, process);
	quick_sort(list_a, list_b, process);
	a_to_headb_n(list_a, list_b, process, cnt);
	quick_sort(list_a, list_b, process);
	return ;
}
