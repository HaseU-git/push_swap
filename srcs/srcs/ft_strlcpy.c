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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	if (!src || !dst)
		return (0);
	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

void	free_str_list(char **ret, int j)
{
	while (j-- > 0)
	{
		free(ret[j]);
		ret[j] = NULL;
	}
	free(ret);
	ret = NULL;
}

void	free_all_str_list(char **ret)
{
	char	**ptr;

	ptr = ret;
	while (*ptr != NULL)
	{
		free(*ptr);
		ptr++;
	}
	free(ptr);
}
