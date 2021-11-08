#include "push_swap.h"

int	is_num(char *str)
{
    int is_num_flag;
    int i;

    is_num_flag = 1;
    i = 0;
    if (str[i] == '-')
        i++;
    else if (str[i] == '0' && str[i + 1] == '\n')
        return (is_num_flag);
    while (str[i] != '\0')
    {
        if (!('1' <= str[i] && str[i] <= '9'))
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
        new_node = set_node_last(ft_atoi(argv[i]), list_a);
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

#include "push_swap.h"

void show_list(t_node *dummy)
{
    t_node *ptr;
    ptr = dummy->next;

    while (ptr != dummy)
    {
        printf("%d\n", ptr->key);
        ptr = ptr->next;
    }
}

int main(int argc, char *argv[])
{
    t_node *list_a;
    t_node *list_b;

    list_a = init_node(list_a);
    list_b = init_node(list_b);

    arg_to_list(list_a, list_b, argc, argv);
    
    show_list(list_a);
    printf("%s", "---------\n");
    show_list(list_b);

	smaller_half_first_to_second(list_a, list_b);
	quick_sort(list_a, list_b);
	larger_half_first_to_second(list_a, list_b);
	quick_sort(list_a, list_b);

    printf("%s", "---=====--\n");
    show_list(list_a);
    printf("%s", "---------\n");
    show_list(list_b);

    write(1, "Error\n", 7); //7であってる？  
    // 引数を受け取る  
    // 引数エラーチェック
    // 連想配列に格納する(nodeA, nodeBをマロックする) 
        // mallocのエラーチェック  
    //  クイックソート（Array情報をmallocする）
        // 操作系を格納する  
        // mallocエラーチェック 
     // 出力する関数  
    return (1);
}