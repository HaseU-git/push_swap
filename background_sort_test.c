// ### 最終目標
// バブルソートして、intの配列を作る  

// ### 必要な関数

// - 双方向循環配列を受け取って、intの配列をソートして返す関数  
//     - 双方向循環リストを受け取ってmallocしたのち、int配列に直して返す関数  
//     - int配列を受け取って、ソートして返す関数  

// - intの配列を受け取って、その中央値を返す関数  
#include <stdlib.h>
# include <stdio.h>

typedef	struct	s_node
{
	int key;
	struct s_node *prev;
	struct s_node *next;
}			t_node;

t_node	*init_node(t_node *node)
{
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return NULL;
	node->next = node;
	node->prev = node;

	return node;
}

t_node	*insert_first(int key, t_node *node)
{
	t_node *x;

	x = (t_node *)malloc(sizeof(t_node));
	if (!x)
		return NULL;
	x->key = key;
	x->next = node->next;
	node->next->prev = x;
	node->next = x;
	x->prev = node;

	return x;
}

typedef	struct  s_num_array
{
	int *elements;
    int len;
}			t_num_array;


t_num_array *substitute_for_array(int *array_elements, int array_len)
{
    t_num_array *array_info;


    // printf("el_0:%d\n", array_elements[0]);
    // printf("len:%d\n", array_len);
    array_info = (t_num_array *)malloc(sizeof(t_num_array));
    if (array_info == NULL)
        return NULL; 
    array_info->elements = array_elements;
    array_info->len = array_len;
    // printf("el_0:%d\n", array_info->elements[0]);
    // printf("len:%d\n", array_info->len);
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
    // printf("len:%d\n", list_len);
    unsorted_array = (int *)malloc(sizeof(int) * list_len);
    if (!unsorted_array)
		return NULL;
    list_ptr = nil->next;
    i = 0;
    while (i < list_len)
    {
        unsorted_array[i] = list_ptr->key;
        // printf("key:%d\n", list_ptr->key);
        // printf("index:%d, key:%d\n", i, unsorted_array[i]);
        i++;
        list_ptr = list_ptr->next;
    }
    // printf("el_0:%d\n", unsorted_array[0]);
    // printf("len:%d\n", list_len);
    return (substitute_for_array(unsorted_array, list_len));
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

int calculate_median(t_num_array *array_info)
{
    int array_median;

    if (array_info->len % 2 == 0)
    {
        array_median = \
        (array_info->elements[array_info->len / 2 - 1] + \
        array_info->elements[array_info->len / 2]) / 2;
    }
    else
    {
        array_median = array_info->elements[array_info->len / 2];
    }
    return array_median;
}

int main()
{
 	t_node *test;
    t_num_array *test_array;
    int array_median;
 
 	test = init_node(test);
 	
 	insert_first(1, test);
 	insert_first(99, test);
 	insert_first(45, test);

    test_array = convert_to_array(test);
    printf("len :%d\n", test_array->len);
    for (int i = 0; i < test_array->len; i++)
        printf("index==[%d]: %d\n", i, test_array->elements[i]);
    printf("\n--=-=-=-=-=-=-=-=-=sort-=-=-=-=-=-=-=-=-=-=-=\n\n");

    sort_num_array(test_array);
    printf("len: %d\n", test_array->len);
    for (int i = 0; i < test_array->len; i++)
        printf("index==[%d]: %d\n", i, test_array->elements[i]);
    printf("\n--=-=-=-=-=-=-=-=-=median-=-=-=-=-=-=-=-=-=-=-=\n\n");

    array_median = calculate_median(test_array);
    printf("median: %d\n", array_median);

    return 0;
}