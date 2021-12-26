/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:45:58 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:45:59 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_process(t_prs *process)
{
	put_swap(process);
	put_push(process);
	put_rotate(process);
	put_reverse_rotate(process);
}

void	print_process(t_prs *process)
{
	t_prs	*ptr;

	ptr = process->next;
	while (ptr != process)
	{
		write_process(ptr);
		ptr = ptr->next;
	}
}
