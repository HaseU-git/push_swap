/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:45:52 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:45:53 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_prs	*init_process(t_node *list_a, t_node *list_b)
{
	t_prs	*process;

	process = (t_prs *)malloc(sizeof(t_prs));
	if (process == NULL)
	{
		free_two_lists(list_a, list_b);
		put_error();
	}
	process->next = process;
	process->prev = process;
	return (process);
}

void	delete_index_operation(t_prs *process)
{
	t_prs	*ptr_prev;

	ptr_prev = process->prev;
	process->next->prev = ptr_prev;
	ptr_prev->next = process->next;
	free(process);
	return ;
}

void	update_prcs(t_node *list_a, t_node *list_b, t_prs *prcs, t_ope ope)
{
	t_prs	*new;
	t_prs	*last;

	new = (t_prs *)malloc(sizeof(t_prs));
	if (new == NULL)
	{
		free_all_process(prcs);
		free_two_lists(list_a, list_b);
		put_error();
	}
	last = prcs;
	while (last->next != prcs)
	{
		last = last->next;
	}
	new->operation = ope;
	new->next = last->next;
	last->next->prev = new;
	last->next = new;
	new->prev = last;
}
