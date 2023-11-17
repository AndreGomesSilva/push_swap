//
// Created by angomes- on 11/13/23.
//
#include "../inc/push_swap.h"

int	list_len_chunk(t_stack **stack, int chunk)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = *stack;
	while (current)
	{
		if (current->chunk == chunk)
			count++;
		current = current->next;
	}
	return (count);
}

int	remain_great_node(t_stack *stack, int check, int chunk)
{
	t_stack	*lst;

	lst = stack;
	while (lst)
	{
		if (lst->chunk == chunk && lst->value > check)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}

int	remain_small_node(t_stack *stack, int check, int chunk)
{
	t_stack	*lst;

	lst = stack;
	while (lst)
	{
		if (lst->chunk == chunk && lst->value < check)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}

//int great_chunk_value(t_stack **a, t_stack **b)
//{
//	int result;
//	t_stack *lst_a;
//	t_stack *lst_b;
//
//	lst_a = *a;
//	lst_b = *b;
//	result = 0;
//	while(lst_a)
//	{
//		if (lst_a->chunk > result)
//			result = lst_a->chunk;
//		lst_a = lst_a->next;
//	}
//	while(lst_b)
//	{
//		if (lst_b->chunk > result)
//			result = lst_b->chunk;
//		lst_b = lst_b->next;
//	}
//	return (result);
//}