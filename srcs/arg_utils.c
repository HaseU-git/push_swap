/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:45:00 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:45:07 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_digit(int num)
{
	int	digit;

	digit = 1;
	num = num / 10;
	while (num % 10 != 0)
	{
		digit = digit + 1;
		num = num / 10;
	}
	return (digit);
}

int	len_str(char *str)
{
	int	len;

	len = 0;
	if (*str == '-')
		str = str + 1;
	while (*str != '\0')
	{
		len = len + 1;
		str = str + 1;
	}
	return (len);
}

long long	str_to_num(char *str)
{
	int				i;
	int				sign;
	unsigned long	ret;

	i = 0;
	ret = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret *= 10;
		ret += str[i] - '0';
		i += 1;
	}
	return (sign * ret);
}

int	is_int(char *str)
{
	int	int_flag;
	int	max_digit;

	int_flag = 1;
	max_digit = count_digit(INT_MAX);
	if (max_digit < len_str(str))
		int_flag = 0;
	else if (str_to_num(str) < INT_MIN)
		int_flag = 0;
	else if (INT_MAX < str_to_num(str))
		int_flag = 0;
	return (int_flag);
}

int	is_num(char *str)
{
	int	is_num_flag;
	int	i;

	is_num_flag = 1;
	i = 0;
	if (str[i] == '-')
	{
		i = i + 1;
		if (!('1' <= str[i] && str[i] <= '9'))
			is_num_flag = 0;
	}
	else if ((str[i] == '0' && str[i + 1] != '\0') || str[i] == '\0')
		is_num_flag = 0;
	while (str[i] != '\0' && is_num_flag != 0)
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			is_num_flag = 0;
		i = i + 1;
	}
	return (is_num_flag);
}
