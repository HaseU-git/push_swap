/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:45:46 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:45:47 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_args(char **str_list)
{
	int	num;

	num = 0;
	while (*str_list != NULL)
	{
		num++;
		str_list++;
	}
	return (num);
}

char	**set_args(int argc, char *argv[], char **str_list)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	else
		return (argv);
}

int	set_count(int argc, char **str_list)
{
	if (argc == 2)
		return (len_args(str_list));
	else
		return (argc);
}
