//
// Created by angomes- on 11/13/23.
//

#include "../inc/push_swap.h"

static void set_value_to_chunk(t_stack **stack, int mid, int chunk)
{
	t_stack *lst;

	lst = *stack;
	while (lst)
	{
		if (lst->chunk == chunk)
			lst->middle_value = mid;
		lst = lst->next;
	}
}

static void sort_chunk_array(t_stack **stack, int *array, int len, int chunk)
{
	int i;
	int key;
	int j;

	i = 1;
	while (i < len)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
		i++;
	}
	set_value_to_chunk(stack, array[len / 2], chunk);
}

static void fill_chunk_array(t_stack **stack, int *array, int len, int chunk)
{
	t_stack *lst;
	int i;

	lst = *stack;
	i = 0;
	while(i < len && lst)
	{
		if (lst->chunk == chunk)
		{
			array[i] = lst->value;
			i++;
		}
		lst = lst->next;
	}
}

void set_middle_chunk(t_stack **stack, int chunk)
{
	int *array;
	int len;

	len = list_len_chunk(stack, chunk);
	array = ft_calloc(len, sizeof(int));
	fill_chunk_array(stack, array, len, chunk);
	sort_chunk_array(stack, array, len, chunk);
	free(array);
}
