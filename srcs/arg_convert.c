/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhasegaw <yhasegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:44:48 by yhasegaw          #+#    #+#             */
/*   Updated: 2021/12/26 14:44:50 by yhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_str_list(char const *s, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			num++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (num);
}

int	len_el(char const *s, char c, int i)
{
	int	num;

	num = 0;
	while (s[i] != c && s[i])
	{
		num++;
		i++;
	}
	return (num);
}

void	fill_ret(char const *s, char c, char **ret)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < len_str_list(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			ret[j] = (char *)malloc(sizeof(char) * (len_el(s, c, i) + 1));
			if (ret[j] == NULL)
			{
				free_str_list(ret, j);
				put_error();
			}
			ft_strlcpy(ret[j], &s[i], len_el(s, c, i) + 1);
			i += len_el(s, c, i);
			j++;
		}
	}
	ret[len_str_list(s, c)] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	**temp;

	if (!s)
		exit(0);
	ret = (char **)malloc(sizeof(char *) * (len_str_list(s, c) + 1 + 1));
	if (ret == NULL)
		put_error();
	ret[0] = (char *)malloc(sizeof(char) * 2);
	if (ret[0] == NULL)
		put_error();
	ret[0][0] = ' ';
	ret[0][1] = '\0';
	fill_ret(s, c, ret + 1);
	return (ret);
}

// int	main(int argc, char *argv[])
// {
// 	char **temp;
// 	int i;
// 
// 	temp = ft_split("1 2 3 4 5", ' ');
// 	while (*temp != NULL)
// 	{
// 	
// 		printf(":%s:\n", *temp);
// 		temp++;
// 	}
// 	i = 0;
// 	while (i < argc)
// 	{
// 		printf(":%s:\n", *argv);
// 		argv++;
// 		i++;
// 	}
// 	printf("%s\n", *temp);
// 	printf("%s\n", *argv);
// }
