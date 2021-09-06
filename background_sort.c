// ### 最終目標
// バブルソートして、intの配列を作る  

// ### 必要な関数

// - 双方向循環配列を受け取って、intの配列をソートして返す関数  
//     - 双方向循環リストを受け取ってmallocしたのち、int配列に直して返す関数  
//     - int配列を受け取って、ソートして返す関数  

// - intの配列を受け取って、その中央値を返す関数  

typedef	struct  s_num_array
{
	int *elements;
    int len;
}			t_num_array;


t_num_array *substitute_for_array(int *array_elements, int array_len)
{
    t_num_array *array_info;
    
    array_info = (t_num_array *)malloc(sizeof(t_num_array));
    if (array_info == NULL)
		return NULL;
    array_info->elements = array_elements;
    array_info->len = array_len;
    return array_info;
}

int count_list_elements(t_node *nil)
{
    int list_len;
    t_node *list_ptr;
    
    list_ptr = nil;
    list_len = 0;
    while (list_ptr->next != nil)
    {
        list_ptr = list_ptr->next;
        list_len++;
    }
    return list_len;
}

t_num_array *convert_to_array(t_node *nil)
{
    int list_len;
    int *unsorted_array;
    t_node *list_ptr;
    int i;
    
    list_len = count_list_elements(nil);
    unsorted_array = (int *)malloc(sizeof(int) * list_len);
    if (!unsorted_array)
		return NULL;
    list_ptr = nil->next;
    i = 0;
    while (i < list_len)
    {
        unsorted_array[i] = list_ptr->key;
        i++;
        list_ptr = list_ptr->next;
    }
    return (substitute_for_array(list_len, unsorted_array));
}

t_num_array *sort_num_array(t_num_array *array_info)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < array_info->len)
    {
        j = i + 1;
        while (j < array_info->len)
        {
            if (array_info->elements[i] > array_info->elements[j])
            {
                tmp = array_info->elements[i];
                array_info->elements[i] = array_info->elements[j];
                array_info->elements[j] = tmp;
            }

            j++;
        }
        i++;
    }
    return array_info;
}
