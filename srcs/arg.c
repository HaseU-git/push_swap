#include "push_swap.h"

int	is_num(char *str)
{
    int is_num_flag;
    int i;

    is_num_flag = 1;
    i = 0;
    if (str[i] == '-')
        i++;
    while (str[i] != '\0')
    {
        if (!('0' <= str[i] && str[i] <= '9'))
        {
            is_num_flag = 0;
            break ;
        }
        i++;
    }
	return (is_num_flag);
}

int arg_check(int argc, char *argv[])
{
    int is_error_flag;
    int i;

    i = 1;
    is_error_flag = 0;
    while (i < argc)
    {
        if (is_num(argv[i]) == 0)
        {
            is_error_flag = 1;
            break ;
        }
        i++;
    }
    return is_error_flag;
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	ret;

	i = 0;
	ret = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret *= 10;
		ret += str[i++] - '0';
		if (ret > LONG_MAX && sign == 1)
			return (-1);
		else if (ret > (unsigned long)LONG_MAX + 1 && sign == -1)
			return (0);
	}
	return (sign * ret);
}

void arg_to_list(t_node *list_a, t_node *list_b, int argc, char *argv[])
{
    int i;
    t_node *new_node;

    i = 1;
    while (i < argc)
    {
        new_node = set_node_last(ft_atoi(argv[i]), list_a);
        if (new_node == NULL)
        {
            free_all_nodes(list_a);
            free_all_nodes(list_b);
            // エラーメッセージ出力
            write(1, "Error\n", 6); //7であってる？  
            // exit();
        }
        i++;
    }
}