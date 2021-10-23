

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

// int	ft_atoi(const char *str)
// {
// 	int				i;
// 	int				sign;
// 	unsigned long	ret;

// 	i = 0;
// 	ret = 0;
// 	sign = 1;
// 	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		ret *= 10;
// 		ret += str[i++] - '0';
// 		if (ret > LONG_MAX && sign == 1)
// 			return (-1);
// 		else if (ret > (unsigned long)LONG_MAX + 1 && sign == -1)
// 			return (0);
// 	}
// 	return (sign * ret);
// }

int main(int argc, char *argv[])
{
    int test = arg_check(argc, argv);
    printf("%d\n", test);
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