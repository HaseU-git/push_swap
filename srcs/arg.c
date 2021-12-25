#include "push_swap.h"

int count_digit(int num)
{
	int digit;

	digit = 1;
	num = num / 10;
	while (num % 10 != 0)
	{
		digit = digit + 1;
		num = num / 10;
	}
	return (digit);
}

int len_str(char *str)
{
	int len;

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

long long str_to_num(char *str)
{
	int	i;
	int	sign;
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

int is_int(char *str)
{
	int int_flag;
	int max_digit;

	int_flag = 1;
	max_digit = count_digit(INT_MAX);
	if (max_digit < len_str(str))
		int_flag = 0;
	else if (str_to_num(str) < INT_MIN)
		int_flag = 0;
	else if (INT_MAX < str_to_num(str))
		int_flag = 0;
	return int_flag;

}

int	is_num(char *str)
{
	int is_num_flag;
	int i;

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

void arg_check(int argc, char *argv[])
{
	int is_error_flag;
	int i;

	i = 1;
	is_error_flag = 0;
	if (argc == 1)
		is_error_flag = 1;
	while (i < argc && is_error_flag != 1)
	{
		if (is_num(argv[i]) == 0 || is_int(argv[i]) == 0)
			is_error_flag = 1;
		i++;
	}
	if (is_error_flag == 1)
	{
		write(1, "Error\n", 6);
        exit(1);
	}	
}


int is_dupulicated(t_node *list_a)
{
	t_node *fixed_node;
	t_node *variable_node;
	int is_dup_flag;

	fixed_node = list_a->next;
	is_dup_flag = 0;
	while (fixed_node != list_a)
	{
		variable_node = fixed_node->next; 
		while (variable_node != list_a)
		{
			if (fixed_node->key == variable_node->key)
				is_dup_flag = 1;
			variable_node = variable_node->next;
		}
		fixed_node = fixed_node->next;
	}
	return (is_dup_flag);
}

void arg_to_list(t_node *list_a, t_node *list_b, int argc, char *argv[])
{
    int i;
    t_node *new_node;

    i = 1;
    while (i < argc)
    {
        new_node = set_node_last((int)str_to_num(argv[i]), list_a);
        if (new_node == NULL)
        {
            free_two_lists(list_a, list_b);
            write(1, "Error\n", 6);
            exit(1);
        }
        i++;
    }

    if (is_dupulicated(list_a))
    {
        free_two_lists(list_a, list_b);
        write(1, "Error\n", 6);
        exit(1);
    }
}
