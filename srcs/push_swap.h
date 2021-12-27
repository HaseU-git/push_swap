/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:46:03 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:46:04 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				key;
	struct s_node	*prev;
	struct s_node	*next;
}		t_node;

typedef enum e_ope
{
	DUMMY,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_ope;

typedef struct s_prs
{
	t_ope			operation;
	struct s_prs	*prev;
	struct s_prs	*next;
}	t_prs;

// arg.c
void		arg_check(int argc, char *argv[]);
int			is_dupulicated(t_node *list_a);
int			is_sorted(t_node *list_a);
void		arg_to_list(t_node *list_a, t_node *list_b, int argc, char *argv[]);

//arg_utils.c
int			count_digit(int num);
int			len_str(char *str);
long long	str_to_num(char *str);
int			is_int(char *str);
int			is_num(char *str);

// free.c
void		put_error(void);
void		free_error_exit(t_node *list_a, t_node *list_b, t_prs *process);
void		free_all_nodes(t_node *dummy);
void		free_all_process(t_prs *dummy);
void		free_two_lists(t_node *list_a, t_node *list_b);

// list_create.c
t_node		*init_node(void);
t_node		*set_node_first(int key, t_node *dummy);
void		delete_node(t_node **t, t_node *dummy);
void		replace_index_operation(t_prs *process, int index, t_ope new_ope);
t_node		*set_node_last(int key, t_node *dummy);

// rule_sort_b.c
void		rule_sort_five_b(t_node *list_a, t_node *list_b, t_prs *process);
void		rule_sort_four_b(t_node *list_a, t_node *list_b, t_prs *process);
void		rule_sort_three_b(t_node *list_a, t_node *list_b, t_prs *process);
void		rule_sort_two_b(t_node *list_a, t_node *list_b, t_prs *process);
void		rule_sort_b(t_node *list_a, t_node *list_b, t_prs *process);

// rule_sort_a.c
void		rule_sort_five_a(t_node *list_a, t_node *list_b, t_prs *process);
void		rule_sort_four_a(t_node *list_a, t_node *list_b, t_prs *process);
void		rule_sort_three_a(t_node *list_a, t_node *list_b, t_prs *process);
void		rule_sort_two_a(t_node *list_a, t_node *list_b, t_prs *process);
void		rule_sort_a(t_node *list_a, t_node *list_b, t_prs *process);

//rule_sort_utils.c
void		swap_a_and_rotate_a(t_node *list_a, t_node *list_b, t_prs *process);
void		rotate_a_and_swap_a(t_node *list_a, t_node *list_b, t_prs *process);
void		swap_b_and_rotate_b(t_node *list_a, t_node *list_b, t_prs *process);
void		rotate_b_and_swap_b(t_node *list_a, t_node *list_b, t_prs *process);

// list_utils.c
t_node		*pop_first(t_node *dummy);
t_node		*pop_last(t_node *dummy);
void		add_node_first(t_node *dummy, t_node *node);
void		add_node_last(t_node *dummy, t_node *node);
int			len_list(t_node *dummy);

// median.c
int			*list_a_to_array(t_node *list_a, t_node *list_b, t_prs *process);
int			*list_b_to_array(t_node *list_a, t_node *list_b, t_prs *process);
int			*sort_num_array(int *array, int len);
int			calculate_median(int *array, int len);

// quick_sort.c
int			larger_half_b_to_a(t_node *list_a, t_node *list_b, t_prs *process);
int			larger_half_a_to_b(t_node *list_a, t_node *list_b, t_prs *process);
int			smaller_half_a_to_b(t_node *list_a, t_node *list_b, t_prs *process);
void		b_to_taila_n(t_node *list_a, t_node *list_b, t_prs *process, int n);
void		a_to_headb_n(t_node *list_a, t_node *list_b, t_prs *process, int n);
void		quick_sort(t_node *list_a, t_node *list_b, t_prs *process);

// process_create.c
t_prs		*init_process(t_node *list_a, t_node *list_b);
void		update_prcs(t_node *list_a, t_node *list_b, t_prs *prcs, t_ope ope);
void		delete_index_operation(t_prs *process);

// list_operate_a.c
void		swap_a(t_node *list_a, t_node *list_b, t_prs *process);
void		rotate_a(t_node *list_a, t_node *list_b, t_prs *process);
void		r_rotate_a(t_node *list_a, t_node *list_b, t_prs *process);
void		push_a(t_node *list_a, t_node *list_b, t_prs *process);

// list_operate_a_n.c
void		rotate_a_n(t_node *list_a, t_node *list_b, t_prs *process, int n);
void		r_rotate_an(t_node *list_a, t_node *list_b, t_prs *process, int n);

// list_operate_b.c
void		swap_b(t_node *list_a, t_node *list_b, t_prs *process);
void		rotate_b(t_node *list_a, t_node *list_b, t_prs *process);
void		r_rotate_b(t_node *list_a, t_node *list_b, t_prs *process);
void		push_b(t_node *list_a, t_node *list_b, t_prs *process);

// list_operate_b_n.c
void		rotate_b_n(t_node *list_a, t_node *list_b, t_prs *process, int n);
void		r_rotate_bn(t_node *list_a, t_node *list_b, t_prs *process, int n);

// process_printe.c
void		write_process(t_prs *process);
void		print_process(t_prs *process);

// process_write.c
void		put_swap(t_prs *process);
void		put_push(t_prs *process);
void		put_rotate(t_prs *process);
void		put_reverse_rotate(t_prs *process);

// process_optimize.c
void		optimize_process(t_node *list_a, t_node *list_b, t_prs *process);
t_prs			*opt_rr(t_prs *process);
t_prs			*opt_rrr(t_prs *process);
t_prs			*opt_ss(t_prs *process);
t_prs			*optimize_rm_extra(t_prs *process);

// main.c
void		show_list(t_node *dummy);

#endif
